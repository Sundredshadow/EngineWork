#include "pch.h"
#include "Application.h"

ENTRYAPP(Application)
Application::Application()
{
}

Application::~Application()
{
}

void Application::init()
{
	Logger::PrintLog(L"I have Loaded Up");
}

void Application::update()
{
	Logger::PrintLog(L"Loop");
}
