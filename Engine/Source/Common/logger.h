#pragma once

class Engine_API Logger {

private:
	static Logger* inst;
public:
	static Logger* Instance() { return inst; }
public:
	Logger();
	~Logger();

	static void PrintLog(const WCHAR* fmt , ...);
};