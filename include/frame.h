/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-11-05 17:39
 * Filename :        frame.h
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#ifndef __FRAME__H__
#define __FRAME__H__

#include "comm.h"
#include "color.h"
#include "log.h"
#include "bitset.h"
#include "cstring"
#include <cstdlib>

struct Frame {
	size_t m_width;
	size_t m_height;
	size_t m_x;
	size_t m_y;
	size_t m_scale;
	Color m_color;
	Frame(size_t m_width, size_t m_height, size_t m_x, size_t m_y, size_t m_scale, Color m_color) : 
		m_width(m_width), m_height(m_height), m_x(m_x), m_y(m_y), m_scale(m_scale), m_color(m_color) {}
};

//class SquareFrame;
//int drawSquareFrame(const SquareFrame &f);

class SquareFrame : public Frame {

friend int drawSquareFrame(SquareFrame &f);

public:
	SquareFrame(size_t m_width, size_t m_height, size_t m_x, size_t m_y, size_t m_scale, Color m_color, Color m_squre_color) : 
		Frame(m_width, m_height, m_x, m_y, m_scale, m_color), m_squre_color(m_squre_color) {
		m_size = ( m_width * m_height) / 8 + 1 ;
		m_data_ptr = static_cast < unsigned char* > ( malloc( m_size ) );
		memset(static_cast<void*>(m_data_ptr), m_size, 0);
		//PRINT_MSG("%d, %d, %d, %d, %d", m_width, m_height, m_x, m_y, m_scale);
	}

	~SquareFrame() {
		free(m_data_ptr);
		m_data_ptr = NULL;
	}
	
	bool isSet(const size_t &i, const size_t &j) const {
		return isSetBit(m_data_ptr, i * m_width + j);
	}

	void setData(const size_t &i, const size_t &j){
		setBit(m_data_ptr, i * m_width + j);
	}

	void unSetData(const size_t &i, const size_t &j){
		unSetBit(m_data_ptr, i * m_width + j);
	}

private:
	unsigned char *m_data_ptr;
	Color m_squre_color;
	size_t m_size;
};

class ScoreFrame : public Frame {
public:
	//ScoreFrame(size_t m_width, size_t m_height, size_t m_x, size_t m_y, size_t m_scale) : 
	//	Frame(m_width, m_height, m_x, m_y, m_scale) {}
	ScoreFrame() = default;
};

class NextFrame : public Frame {
public:
	//NextFrame(size_t m_width, size_t m_height, size_t m_x, size_t m_y, size_t m_scale) : 
	//	Frame(m_width, m_height, m_x, m_y, m_scale) {}
	NextFrame() = default;
};

//class BodyFrame;
//int drawBodyFrame(const BodyFrame &f);

class BodyFrame : public Frame {

friend int drawBodyFrame(BodyFrame &f);

public:
	BodyFrame(size_t m_width, size_t m_height, size_t m_x, size_t m_y, size_t m_scale = 1, Color m_color = Color(255, 0, 0), Color m_squre_color = Color(0, 0, 255)) : 
		Frame(m_width, m_height, m_x, m_y, m_scale, m_color), 
		m_square(SquareFrameWidth, SquareFrameHeight, m_x + SquareFrameRX, m_y + SquareFrameRY, SquareFrameScale, m_color, m_squre_color) {
		//PRINT_MSG("%d, %d, %d, %d, %d", m_width, m_height, m_x, m_y, m_scale);
	}
private:
	SquareFrame m_square;
	//ScoreFrame m_score;
	//NextFrame m_next;
};
#endif
