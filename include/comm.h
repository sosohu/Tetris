/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-11-05 16:27
 * Filename :        comm.h
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#ifndef __COMM__H__
#define __COMM__H__

#include <cstddef>

typedef wchar_t BrickData;
const BrickData LINE_BRICK_DATA[] = { 0x1111, 0xf0, 0x1111, 0xf0 };
const BrickData L_BRICK_DATA[] = { 0x223, 0x170, 0x622, 0x74 };
const BrickData RL_BRICK_DATA[] = { 0x322, 0x470, 0x226, 0x71 };
const BrickData SQUARE_BRICK_DATA[] = { 0x33, 0x33, 0x33, 0x33 };
const BrickData RZ_BRICK_DATA[] = { 0x132, 0x630, 0x264, 0x63 };
const BrickData UP_BRICK_DATA[] = { 0x232, 0x270, 0x262, 0x72 };
const BrickData Z_BRICK_DATA[] = { 0x231, 0x360, 0x462, 0x36 };

typedef const BrickData* BrickDataPtr;
const BrickDataPtr BRICK_DATA[] = { LINE_BRICK_DATA, L_BRICK_DATA, RL_BRICK_DATA, 
								  SQUARE_BRICK_DATA, RZ_BRICK_DATA, UP_BRICK_DATA, Z_BRICK_DATA};

typedef char BrickType;
const size_t BrickTypeNum = 6;
const BrickType LINE_BRICK_TYPE = 0x0;
const BrickType L_BRICK_TYPE = 0x1;
const BrickType RL_BRICK_TYPE = 0x2;
const BrickType SQUARE_BRICK_TYPE = 0x3;
const BrickType RZ_BRICK_TYPE = 0x4;
const BrickType UP_BRICK_TYPE = 0x5;
const BrickType Z_BRICK_TYPE = 0x6;

typedef unsigned char BrickStatus;
const BrickStatus	UP = 0;
const BrickStatus	RIGHT = 1;
const BrickStatus	DOWN = 2;
const BrickStatus 	LEFT = 3;

const size_t BRICK_WIDTH[] = {4, 3, 3, 2, 3, 3, 3};

const size_t SquareFrameWidth = 10;
const size_t SquareFrameHeight = 17;
const size_t SquareFrameRX = 2;
const size_t SquareFrameRY = 2;
const size_t SquareFrameScale = 30;

typedef unsigned char BodyStatus;
const BodyStatus START = 0;
const BodyStatus FOLLOW = 1;
const BodyStatus MERGE = 2;
const BodyStatus NEXT = 3;
const BodyStatus OVER = 9;

#endif
