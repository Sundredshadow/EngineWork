#include "Engine.h"
#include <fstream>

Logger* Logger::inst;

Logger::Logger()
{
	inst = this;
}

Logger::~Logger()
{
}

void Logger::PrintLog(const WCHAR* fmt, ...)
{
	WCHAR buf[4096];
	va_list args;

	va_start(args, fmt);
	vswprintf_s(buf, fmt, args);
	va_end(args);

	//%AppData%/BlankProj/Log/BlankProj(date)(time).log
	std::wfstream outfile;

	outfile.open(std::wstring(LogDirectory()+L"/" + LogFile()), std::ios_base::app);

}

