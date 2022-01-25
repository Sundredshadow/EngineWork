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

	//LogDirectory %AppData%/BlankProj/Log/
	//LogFile ProjName(date)(time).log
	std::wfstream outfile;

	outfile.open(std::wstring(LogDirectory()+L"\\" + LogFile()), std::ios_base::app);

	if (outfile.is_open()) {
		std::wstring s = buf;
		outfile << L"[" << Time::GetDateTimeString() << L"]" << s;
		outfile.close();
		OutputDebugString(s.c_str());
	}
	else {
		MessageBox(0, L"Unable to open log File..", L"Log Error", 0);
	}

	//MessageBox(0, LogDirectory().c_str(), 0, 0);

}

std::wstring Logger::LogFile() {

	WCHAR File[1024];
	wcscpy_s(File, PerGameSettings::GameName());
	wcscat_s(File, PerGameSettings::BootTime());
	wcscat_s(File, L".log");
	return File;

}

#if defined WIN32 || defined WIN64
	#include <shlobj.h>
	std::wstring Logger::LogDirectory() {

		WCHAR Path[1024];
		WCHAR* AppDataLocal;
		SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
		wcscpy_s(Path, AppDataLocal);
		wcscat_s(Path, L"\\");
		wcscat_s(Path, PerGameSettings::GameName());
		CreateDirectory(Path, NULL);
		wcscat_s(Path, L"\\Log");
		CreateDirectory(Path, NULL);
		return Path;
	}
#elif defined ARM64
	std::wstring Logger::LogDirectory() {

		WCHAR Path[1024];
		WCHAR* AppDataLocal;
		SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &AppDataLocal);
		wcscpy_s(Path, AppDataLocal);
		wcscat_s(Path, L"\\");
		wcscat_s(Path, /**/);
		CreateDirectory(Path, NULL);
		wcscat_s(Path, L"\\Log");
		CreateDirectory(Path, NULL);
		return Path;
	}
#else
	std::wstring Logger::LogDirectory() {

		return;
	}
#endif

