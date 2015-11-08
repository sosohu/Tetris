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

class Brick {
public:
	Brick(BrickType m_type = 0x0) : m_status(UP),  m_type(m_type) {}

	void rorate(){
		m_status = (m_status + 1) % 4;
	}

	virtual BrickData getBrickData() const = 0;

	BrickType getBrickType() const {
		return m_type;
	}
protected:
	BrickStatus m_status;
	BrickType m_type; // lower 7 bit represent the type of Brick
};

class LineBrick : public Brick {
public:
	LineBrick() : Brick(LINE_BRICK_TYPE) {}

	BrickData getBrickData() const {
		return LINE_BRICK_DATA[m_status];
	}
};

class LBrick : public Brick {
public:
	LBrick() : Brick(L_BRICK_TYPE) {}

	BrickData getBrickData() const {
		return L_BRICK_DATA[m_status];
	}
};

class RlBrick : public Brick {
public:
	RlBrick() : Brick(RL_BRICK_TYPE) {}

	BrickData getBrickData() const {
		return RL_BRICK_DATA[m_status];
	}
};

class SquareBrick : public Brick {
public:
	SquareBrick() : Brick(SQUARE_BRICK_TYPE) {}

	BrickData getBrickData() const {
		return SQUARE_BRICK_DATA[m_status];
	}
};

class RzBrick : public Brick {
public:
	RzBrick() : Brick(RZ_BRICK_TYPE) {}

	BrickData getBrickData() const {
		return RZ_BRICK_DATA[m_status];
	}
};

class UpBrick : public Brick {
public:
	UpBrick() : Brick(UP_BRICK_TYPE) {}

	BrickData getBrickData() const {
		return UP_BRICK_DATA[m_status];
	}
};

class ZBrick : public Brick {
public:
	ZBrick() : Brick(Z_BRICK_TYPE) {}

	BrickData getBrickData() const {
		return Z_BRICK_DATA[m_status];
	}
};

#endif
