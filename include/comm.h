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

typedef char BrickType;
const BrickType LINE_BRICK_TYPE = 0x1;
const BrickType L_BRICK_TYPE = 0x2;
const BrickType RL_BRICK_TYPE = 0x4;
const BrickType SQUARE_BRICK_TYPE = 0x8;
const BrickType RZ_BRICK_TYPE = 0x16;
const BrickType UP_BRICK_TYPE = 0x32;
const BrickType Z_BRICK_TYPE = 0x64;

typedef char BrickStatus;
const BrickStatus	UP = 0;
const BrickStatus	RIGHT = 1;
const BrickStatus	DOWN = 2;
const BrickStatus 	LEFT = 3;

const size_t SquareFrameWidth = 10;
const size_t SquareFrameHeight = 20;
const size_t SquareFrameRX = 20;
const size_t SquareFrameRY = 20;
const size_t SquareFrameScale = 50;

#endif
