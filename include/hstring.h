/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-11-09 20:42
 * Filename :        hstring.h
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#ifndef __HSTRING__H__
#define __HSTRING__H__

#include <string>
#include <cstddef>

/* w width num which use string to store, add n
	eg: 5 width num "00123" add 1 -> "00124"
 */
void strNumAddU(std::string &num, size_t w, size_t n);

#endif
