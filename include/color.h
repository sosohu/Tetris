/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-11-07 19:35
 * Filename :        color.h
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#ifndef __COLOR__H__
#define __COLOR__H__

#include "log.h"

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}
};

#endif
