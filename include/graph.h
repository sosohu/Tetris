/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-11-07 19:17
 * Filename :        graph.h
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#ifndef __GRAPH__H__
#define __GRAPH__H__

#include "frame.h"
#include "log.h"
#include <GL/glut.h>

//extern Log* pLog;

int drawFrame(Frame &f) {
	Log* pLog = Log::getLogInstance();
	size_t width = f.m_width * f.m_scale;
	size_t height = f.m_height * f.m_scale;
	size_t x = f.m_x;
	size_t y = f.m_y;
	glColor3i(f.m_color.r, f.m_color.g, f.m_color.b);
	pLog->print(DEBUG,"Color: %d, %d, %d", f.m_color.r, f.m_color.g, f.m_color.b);
	glRecti(x, y, x + width, y + height); 
	return 0;
}

int drawSquareFrame(SquareFrame &f) {
	Log* pLog = Log::getLogInstance();
	drawFrame(f);
    //glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3i(f.m_squre_color.r, f.m_squre_color.g, f.m_squre_color.b);
	//printColor(f.m_squre_color);
	size_t width = f.m_width;
	size_t height = f.m_height;
	size_t x = f.m_x;
	size_t y = f.m_y;
	size_t scale = f.m_scale;
	for(size_t i = 0; i < height; i++) {
		for(size_t j = 0; j < width; j++) {
			if(f.isSet(i, j)) {
				size_t curX = x + j * scale;
				size_t curY = y + i * scale;
				glRecti(curX, curY, curX + scale, curY + scale); 
				pLog->print(DEBUG,"Mini Square--> width: %d,  height: %d, X: %d, Y: %d", scale, scale, curX, curY);
			}
		}
	}
	return 0;
}

int drawBodyFrame(BodyFrame &f){
	drawFrame(f);
	f.m_square.setData(5, 5);
	drawSquareFrame(f.m_square);
}



#endif
