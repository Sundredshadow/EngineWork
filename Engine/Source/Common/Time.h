#pragma once

#include <string>

namespace Time {
	
	std::wstring Engine_API GetTime(bool stripped = FALSE);

	std::wstring Engine_API GetDate(bool stripped = FALSE);

	std::wstring Engine_API GetDateTimeString(bool stripped = FALSE);

}