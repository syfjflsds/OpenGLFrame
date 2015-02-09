#ifndef YF_LOGGER_H__
#define YF_LOGGER_H__

#include "YFSingleton.h"
#include <string>
#include <cstdio>

#define _LOG_ENABLE

namespace YFun
{
	class YFLogger : public Singleton<YFLogger> 
	{
	public:	
		enum LogType
		{
			NORMAL = 0,
			WARNING = 1,
			WRONG = 2,
		};
		static void log(LogType type, const char *logStr);
		static void log(const char *logStr);
		void init(const char *fileStr);
	private:
		static FILE *logFilePoiner;	
	};
}

#endif