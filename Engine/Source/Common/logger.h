#pragma once
#include <string>

class Engine_API Logger {

private:
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }
public:
	Logger();
	~Logger();

	static void PrintLog(const WCHAR* fmt , ...);

	static std::wstring LogDirectory();
	static std::wstring LogFile();
};