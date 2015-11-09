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
#include "brick.h"
#include "hstring.h"
#include <cstring>
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
	SquareFrame(size_t m_width, size_t m_height, size_t m_x, size_t m_y, size_t m_scale, Color m_color = GRAY, Color m_square_color = BLACK) : 
		Frame(m_width, m_height, m_x, m_y, m_scale, m_color), m_square_color(m_square_color) {
		m_size = ( m_width * m_height) / 8 + 1 ;
		m_data_ptr = static_cast < unsigned char* > ( malloc( m_size ) );
		memset(static_cast<void*>(m_data_ptr), 0, m_size);
		m_col_heights = static_cast< size_t* > (malloc(m_width * sizeof(size_t)));
		memset(static_cast<void*>(m_col_heights), 0, m_width * sizeof(size_t));
		m_line_widths = static_cast< size_t* > (malloc(m_height * sizeof(size_t)));
		memset(static_cast<void*>(m_line_widths), 0, m_height * sizeof(size_t));
		//printData();
	}

	~SquareFrame() {
		free(m_data_ptr);
		m_data_ptr = NULL;
		free(m_col_heights);
		m_col_heights = NULL;
		free(m_line_widths);
		m_line_widths = NULL;
	}
	
	bool isSet(const size_t &i, const size_t &j) const {
		return isSetBit(m_data_ptr, i + j * m_height);
	}

	void setData(const size_t &i, const size_t &j){
		setBit(m_data_ptr, i + j * m_height);
	}

	void unSetData(const size_t &i, const size_t &j){
		unSetBit(m_data_ptr, i + j * m_height);
	}

	void setFrameColor(const Color &edge, const Color &square, const Color &background);

	size_t clearLine(const Brick &follow_brick, size_t follow_i, size_t follow_j);

	void computeHeights();

	void computeWidths();

	bool isOver() const;

	void printData(){
		Log *pLog = Log::getLogInstance();
		#include <iostream>
		std::cout << "Print SquareFrame data: " << std::endl;
		for(size_t i = 0; i < m_height; i++){
			for(size_t j = 0; j < m_width; j++){
				std::cout << isSetBit(m_data_ptr, i + j * m_height) << " ";
			} 
			std::cout << std::endl;
		}
	}

public:
	size_t *m_col_heights;
	size_t *m_line_widths;

private:
	unsigned char *m_data_ptr;
	Color m_square_color;
	Color m_edge_color;
	size_t m_size;
};

class ScoreFrame : public Frame {
friend int drawScoreFrame(ScoreFrame &f);
public:
	ScoreFrame(size_t m_width, size_t m_height, size_t m_x, size_t m_y, size_t m_scale, Color m_color = WHITE, Color m_text_color = BLACK) : 
		Frame(m_width, m_height, m_x, m_y, m_scale, m_color), 
		m_text("Score:  "), m_score("00000"), m_text_color(m_text_color) {}

	void setFrameColor(const Color &text, const Color &background);

	void addScore(size_t n = 1) {
		strNumAddU(m_score, 5, n);
	}

private:
	const std::string m_text;
	std::string m_score;
	Color m_text_color;
};

class NextFrame : public Frame {
friend int drawNextFrame(NextFrame &f);
public:
	NextFrame(size_t m_width, size_t m_height, size_t m_x, size_t m_y, size_t m_scale, Color c = GRAY, Color m_square_color = BLACK) :
		Frame(m_width, m_height, m_x, m_y, m_scale, c), m_square_color(m_square_color) {}

	void setBrick(const Brick &brick){
		m_brick = brick;
	}

	void setFrameColor(const Color &edge, const Color &square, const Color &background);
	
private:
	Brick m_brick;
	Color m_square_color;
	Color m_edge_color;
};

//class BodyFrame;
//int drawBodyFrame(const BodyFrame &f);

class BodyFrame : public Frame {

friend int drawBodyFrame(BodyFrame &f);

public:
	BodyFrame(size_t m_width, size_t m_height, size_t m_x, size_t m_y, size_t m_scale = 1, Color m_color = BLACK, Color m_squre_color = GRAY) : 
		Frame(m_width, m_height, m_x, m_y, m_scale, m_color), 
		m_square(SquareFrameWidth, SquareFrameHeight, m_x + SquareFrameRX, m_y + SquareFrameRY, SquareFrameScale),
		m_next(NextFrameWidth, NextFrameHeight, m_x + NextFrameRX, m_y + NextFrameRY,
NextFrameScale),
		m_score(ScoreFrameWidth, ScoreFrameHeight, m_x + ScoreFrameRX, m_y + ScoreFrameRY,
ScoreFrameScale){
		//PRINT_MSG("%d, %d, %d, %d, %d", m_width, m_height, m_x, m_y, m_scale);
		m_status = START;
		m_follow_brick = genRandBrick();
		m_follow_i = 0; // line
		m_follow_j = m_square.m_width / 2 - 2; // col
		m_next_brick = genRandBrick();
		m_next.setBrick(m_next_brick);
	}

	void setBodyFrameColor(const Color &c);
	void setSquareFrameColor(const Color &edge, const Color &square, const Color &background);
	void setNextFrameColor(const Color &edge, const Color &square, const Color &background);
	void setScoreFrameColor(const Color &text, const Color &background);

	bool isOver() const { return m_status == OVER; }

	void update();

	void pressUpdate();

	void leftShift();

	void rightShift();

	void downShift();

	void changeFollow();

private:
	void computeLife();
	void clear();
	void eliminate();
	void uneliminate();

private:
	SquareFrame m_square;
	ScoreFrame m_score;
	NextFrame m_next;
	BodyStatus m_status;
	Brick m_follow_brick;
	Brick m_next_brick;
	size_t m_follow_i;  // line
	int m_follow_j;  // col
	size_t m_follow_life; // how long it will meet
};
#endif
