/*******************************************************************************
 * Author :          Qinghai Hu
 * Email :           ustc.sosohu@gmail.com
 * Last modified :   2015-11-08 16:30
 * Filename :        alarm.h
 * Description :     This program is free software, you can redistribute it and/or
                     modify it under the terms of the GNU General Public License
                     as published by the Free Software Foundation.
 * *****************************************************************************/
#ifndef __ALARM__H__
#define __ALARM__H__

#include <signal.h>
#include <unistd.h>

#define ALARM_MAX = 10;

static void idle(int signo){
	
}

/*
static void deamon(int signo){
	func();
	alarm(per_second);
}
*/

class Alarm {
public:
	Alarm(void (*m_func)(int) = idle, size_t m_per_second = 1) : m_func(m_func), m_per_second(m_per_second) {
		
	}

	void start() {
		signal(SIGALRM, m_func);
		alarm(m_per_second);
	}

	void end() {
		// TODO
	}
private:
	void (*m_func)(int);
	size_t m_per_second;
};

#endif
