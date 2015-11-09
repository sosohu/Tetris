/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-11-05 16:13
 * Filename :        brick.h
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#ifndef __BRICK__H__
#define __BRICK__H__

#include "comm.h"
#include "bitset.h"
#include "log.h"

class Brick {
public:
	Brick(BrickType m_type = 0) : m_status(UP),  m_type(m_type), m_data(BRICK_DATA[m_type]) {
		
	}

	

	void rorate(){
		m_status = (m_status + 1) % 4;
	}

	BrickData getBrickData() const {
		return m_data[m_status];
	}

	BrickType getBrickType() const {
		return m_type;
	}

	size_t getLineHeight(size_t j) const {
		Log* pLog = Log::getLogInstance();
		pLog->Print(DEBUG, "m_data[m_status]: %0x", m_data[m_status]);
		unsigned char cur = ((m_data[m_status] & ( 0xf << (j*4))) >> (j*4) );
		pLog->Print(DEBUG, "cur: %d", cur);
		if(cur >= 8)	return 4;
		if(cur >= 4)	return 3;
		if(cur >= 2)	return 2;
		if(cur >= 1)	return 1;
		return 0;
	}
	
	size_t getLeftPadding() const{
		for(size_t i = 0; i < 4; i++){
			if((m_data[m_status] & (0xf << i*4)) != 0x0)	return i;
		}
		return 4;
	}

	size_t getRightPadding() const{
		for(int i = 3; i >= 0; i--){
			if((m_data[m_status] & (0xf << i*4)) != 0x0)	return 3 - i;
		}
		return 4;
	}

	bool isSet(size_t i, size_t j) const {
		return isSetBit(reinterpret_cast<const unsigned char*>(&m_data[m_status]), i + j * 4);
	}
protected:
	BrickStatus m_status;
	BrickType m_type; // lower 7 bit represent the type of Brick
	const BrickData *m_data;
};

class LineBrick : public Brick {
public:
	LineBrick() : Brick(LINE_BRICK_TYPE) {}
};

class LBrick : public Brick {
public:
	LBrick() : Brick(L_BRICK_TYPE) {}
};

class RlBrick : public Brick {
public:
	RlBrick() : Brick(RL_BRICK_TYPE) {}
};

class SquareBrick : public Brick {
public:
	SquareBrick() : Brick(SQUARE_BRICK_TYPE) {}
};

class RzBrick : public Brick {
public:
	RzBrick() : Brick(RZ_BRICK_TYPE) {}
};

class UpBrick : public Brick {
public:
	UpBrick() : Brick(UP_BRICK_TYPE) {}
};

class ZBrick : public Brick {
public:
	ZBrick() : Brick(Z_BRICK_TYPE) {}
};

Brick genRandBrick();

#endif
