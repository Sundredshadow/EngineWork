#pragma once

//architecture
//only run if windows expandable to other OS
//Architecture has a 

enum Arch {x64,x86,arm};

#ifdef BUILD_DLL
#define Engine_API __declspec(dllexport)
#else
#define Engine_API __declspec(dllimport)
#endif

#ifdef WIN32
	#include "Platform/WIN32/WinMain.h"
	#include "Platform/WIN32/IApplication.h"

#endif // WIN32 

#ifdef WIN64
//temp need WIN64 variation
	#include "Platform/WIN32/WinMain.h"
	#include "Platform/WIN32/IApplication.h"
#endif // WIN64

#ifdef ARM64
//temp need arm64 variation
#include "Platform/WIN32/WinMain.h"
#include "Platform/WIN32/IApplication.h"
#endif // ARM64

//logging
#include "Common/logger.h"