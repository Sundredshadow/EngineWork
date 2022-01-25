#include "pch.h"
#include "Application.h"

ENTRYAPP(Application)
Application::Application()
{
}

Application::~Application()
{
}

void Application::SetupPerGameSettings()
{
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
}

void Application::init()
{
	Logger::PrintLog(L"I have Loaded Up %s",PerGameSettings::GameName());
}

void Application::update()
{
	//Logger::PrintLog(L"Loop");
}
