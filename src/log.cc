#include "log.h"

Log* Log::ptr = NULL;

void Log::print(PriorityLevel level, std::string format, ...) {
	std::string message;                                        //vector<char>
	va_list args;
	va_start(args,format);
	message.reserve(vsnprintf(NULL, 0, format.c_str(), args) + 1);
	vsprintf((char*)message.c_str(), format.c_str(), args);

	switch (level)
	{
	case EMERG:
		Emerg(message.c_str());
		break;
	case FATAL:
		Fatal(message.c_str());
		break;
	case ALERT:
		Alert(message.c_str());
		break;
	case CRIT:
		Crit(message.c_str());
		break;
	case ERROR:
		Error(message.c_str());
		break;
	case WARN:                        //default
		Warn(message.c_str());
		break;
	case NOTICE:
		Notice(message.c_str());
		break;
	case INFO:
		Info(message.c_str());
		break;
	case DEBUG:
		Debug(message.c_str());
		break;
	case NOTSET:
		Notset(message.c_str());
		break;
	default:
		Warn(message.c_str());
		break;
	}
}
