#pragma once

//singleton

class Engine_API PerGameSettings {

private:
	static PerGameSettings* inst;
public:
	static PerGameSettings* Instance() { return inst; }
public:
	PerGameSettings();
	~PerGameSettings();

private://settings
	WCHAR m_GameName[MAX_NAME_STRING];
	WCHAR m_ShortName[MAX_NAME_STRING];
	HICON m_MainIcon;
	WCHAR m_BootTime[MAX_NAME_STRING];

public:
	//getters setters
	static WCHAR* GameName() { return inst->m_GameName; }
	static void SetGameName(UINT id) { LoadString(HInstance(), id, inst->m_GameName, MAX_NAME_STRING); }

	static WCHAR* ShortName() { return inst->m_GameName; }
	static void SetShortName(UINT id) { LoadString(HInstance(), id, inst->m_ShortName, MAX_NAME_STRING); }

	static HICON MainIcon() { return inst->m_MainIcon; }
	static void SetMainIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* BootTime() { return inst->m_BootTime; }


};