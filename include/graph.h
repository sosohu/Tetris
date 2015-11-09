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
	glColor3ub(f.m_color.r, f.m_color.g, f.m_color.b);
	pLog->Print(DEBUG,"Color: %d, %d, %d", f.m_color.r, f.m_color.g, f.m_color.b);
	glRecti(x, y, x + width, y + height); 
	pLog->Print(DEBUG, "%d, %d, %d, %d", x, y, x + width, y + height);
	return 0;
}

int drawSquareFrame(SquareFrame &f) {
	Log* pLog = Log::getLogInstance();

	//draw background
	drawFrame(f);

	//draw edge
	glLineWidth(4);
	glColor3ub(f.m_edge_color.r, f.m_edge_color.g, f.m_edge_color.b);
	glBegin(GL_LINE_LOOP);  
		pLog->Print(DEBUG,"EdgeColor: %d, %d, %d", f.m_edge_color.r, f.m_edge_color.g, f.m_edge_color.b);
		glVertex2i(f.m_x, f.m_y);  
		glVertex2i(f.m_x + f.m_width * f.m_scale, f.m_y);  
		glVertex2i(f.m_x + f.m_width * f.m_scale, f.m_y + f.m_height * f.m_scale);  
		glVertex2i(f.m_x, f.m_y + f.m_height * f.m_scale);  
		pLog->Print(DEBUG, "startPoint: ( %d, %d ), endPoint: ( %d, %d)", f.m_x, f.m_y, f.m_x + f.m_width * f.m_scale, f.m_y + f.m_height * f.m_scale);
    glEnd();  
	
	//draw square
	glColor3ub(f.m_square_color.r, f.m_square_color.g, f.m_square_color.b);
	pLog->Print(DEBUG,"SquareColor: %d, %d, %d", f.m_square_color.r, f.m_square_color.g, f.m_square_color.b);

	size_t width = f.m_width;
	size_t height = f.m_height;
	size_t x = f.m_x;
	size_t y = f.m_y;
	size_t scale = f.m_scale;
	for(size_t i = 0; i < height; i++) {
		for(size_t j = 0; j < width; j++) {
			if(f.isSet(i, j)) {
				//size_t curX = x + (width - j - 1) * scale;
				size_t curX = x + j * scale;
				size_t curY = y + (height - i - 1) * scale;
				glRecti(curX, curY, curX + scale, curY + scale); 
				pLog->Print(NOTSET,"Mini Square--> width: %d,  height: %d, X: %d, Y: %d", scale, scale, curX, curY);
			}
		}
	}
	return 0;
}

int drawNextFrame(NextFrame &f) {
	Log* pLog = Log::getLogInstance();

	//draw background
	drawFrame(f);

	//draw edge
	glLineWidth(4);
	glColor3ub(f.m_edge_color.r, f.m_edge_color.g, f.m_edge_color.b);
	glBegin(GL_LINE_LOOP);  
		pLog->Print(DEBUG,"EdgeColor: %d, %d, %d", f.m_edge_color.r, f.m_edge_color.g, f.m_edge_color.b);
		glVertex2i(f.m_x, f.m_y);  
		glVertex2i(f.m_x + f.m_width * f.m_scale, f.m_y);  
		glVertex2i(f.m_x + f.m_width * f.m_scale, f.m_y + f.m_height * f.m_scale);  
		glVertex2i(f.m_x, f.m_y + f.m_height * f.m_scale);  
		pLog->Print(DEBUG, "startPoint: ( %d, %d ), endPoint: ( %d, %d)", f.m_x, f.m_y, f.m_x + f.m_width * f.m_scale, f.m_y + f.m_height * f.m_scale);
    glEnd();  
	
	//draw square
	glColor3ub(f.m_square_color.r, f.m_square_color.g, f.m_square_color.b);
	pLog->Print(DEBUG,"SquareColor: %d, %d, %d", f.m_square_color.r, f.m_square_color.g, f.m_square_color.b);

	size_t width = f.m_width;
	size_t height = f.m_height;
	size_t x = f.m_x;
	size_t y = f.m_y;
	size_t scale = f.m_scale;
	for(size_t i = 0; i < 4; i++) {
		for(size_t j = 0; j < 4; j++) {
			if(f.m_brick.isSet(i, j)) {
				//size_t curX = x + (width - (j + 1) - 1) * scale;
				size_t curX = x + (j + 1 ) * scale;
				size_t curY = y + (height - (i + 1) - 1) * scale;
				glRecti(curX, curY, curX + scale, curY + scale); 
				pLog->Print(NOTSET,"Mini Square--> width: %d,  height: %d, X: %d, Y: %d", scale, scale, curX, curY);
			}
		}
	}
	return 0;
}

int drawScoreFrame(ScoreFrame &f){
	//draw background
	drawFrame(f);
	std::string text = f.m_text + f.m_score;
	glColor3ub(f.m_text_color.r, f.m_text_color.g, f.m_text_color.b);
	size_t x = f.m_x, y = f.m_y + 20;
	for(size_t i = 0; i < text.size(); i++){
		x = x + 10;
		glRasterPos2f(x, y);
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, text[i] );
	}
	return 0;
}

int drawBodyFrame(BodyFrame &f){
	drawFrame(f);
	//f.m_square.setData(5, 5);
	drawSquareFrame(f.m_square);
	drawNextFrame(f.m_next);
	drawScoreFrame(f.m_score);
}



#endif
