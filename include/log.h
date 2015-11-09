#ifndef __LOG__H__
#define __LOG__H__

#include "log4cpp/Category.hh"
#include "log4cpp/PropertyConfigurator.hh"
#include <cstdio>
#include <cstdarg>

#ifdef FULL_LOG
#define Print(level, format, args...)  print(level, "%s, %d, %s:\n" format, __FILE__, __LINE__, __func__, ##args)
#else
#define Print(level, format, args...)  print(level, "%s, %d: " format, __func__, __LINE__, ##args)
#endif

enum PriorityLevel
{    
    EMERG,                        //EMERG  = 0,
    FATAL,                        //FATAL  = 0,
    ALERT,                        //ALERT  = 100,
    CRIT,                        //CRIT   = 200,
    ERROR,                        //ERROR  = 300,
    WARN,                        //WARN   = 400,
    NOTICE,                        //NOTICE = 500,
    INFO,                        //INFO   = 600,
    DEBUG,                        //DEBUG  = 700,
    NOTSET,                        //NOTSET = 800,
    PriorityLevel_Num            //PriorityLevel_Num = 10
};

class Log {
private:
	Log(){
		log4cpp::PropertyConfigurator::configure("conf/log4cpp.conf");
    	m_pCategory = &log4cpp::Category::getRoot();
	}

	static Log *ptr;
	log4cpp::Category* m_pCategory;
public:
	static Log* getLogInstance(){
		if(!ptr){
			ptr = new Log();
		}
		return ptr;
	}

	static void deleteLogInstance() {
		if(ptr){
			delete ptr;
			ptr = NULL;
		}
	}

	void Notset(const char* msg) {
		
	}

	void Debug(const char* msg) {
		m_pCategory->debug(msg);
	}

	void Info(const char* msg) {
		m_pCategory->info(msg);
	}

	void Notice(const char* msg) {
		m_pCategory->notice(msg);
	}

	void Warn(const char* msg) {
		m_pCategory->warn(msg);
	}

	void Error(const char* msg) {
		m_pCategory->error(msg);
	}

	void Crit(const char* msg) {
		m_pCategory->crit(msg);
	}

	void Alert(const char* msg) {
		m_pCategory->alert(msg);
	}

	void Fatal(const char* msg) {
		m_pCategory->fatal(msg);
	}

	void Emerg(const char* msg) {
		m_pCategory->emerg(msg);
	}

	void print(PriorityLevel level, std::string format, ...);
};

#endif
