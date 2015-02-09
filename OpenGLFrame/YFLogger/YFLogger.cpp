#include "YFLogger.h"
#include <time.h>
using namespace YFun;

FILE * YFLogger::logFilePoiner = NULL; 
#define LOG_CHAR_MAX 1024

void YFLogger::log( LogType type, const char *logStr)
{
#ifdef _LOG_ENABLE
	char logStrBuff[LOG_CHAR_MAX];

	//获取当前时间
	time_t now = time(0);
	strftime(logStrBuff, sizeof(logStrBuff), "%Y/%m/%d-%H:%M:%S ", localtime(&now));

	//写入具体的Log信息
	fprintf(logFilePoiner, "%s %s\n", logStrBuff, logStr);
	fflush(logFilePoiner);
#endif
}

void YFLogger::log(const char * logStr)
{
	log(NORMAL, logStr);
}

void YFLogger::init(const char *fileStr)
{
	char fileName[LOG_CHAR_MAX];
	sprintf(fileName, "%s.log", fileStr);
	logFilePoiner = fopen(fileName, "w");
	log("YFLogger Init Successful!");
}
