#pragma once

#include "../../BlankProj/resource.h"

//Definitions//
#ifdef _DEBUG//wether in debug or release
#define SolutionState 1
#else
#define SolutionState 0
#endif

#define MAX_NAME_STRING 256//max size of window title

//so i don't to pass around these function to function after its creation in WinMain
#define HInstance() GetModuleHandle(NULL)//gets the hinstance


void IntializesVariables();
void CreateWindowClass();
void DisplayWindow();
void ListenForWindowEvents();