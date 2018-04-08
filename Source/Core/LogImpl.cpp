// <copyright file="TracerImpl.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include "LogImpl.h"

namespace Tracer
{
	/*static*/ bool LogImpl::s_showMessageBox = false;

	std::wstring ToString(int value, int requiredDigits)
	{
		std::wstring result = std::wstring(requiredDigits, '0');
		int index = requiredDigits - 1;
		int currValue = value;
		while (currValue != 0 && index >= 0)
		{
			int digit = currValue % 10;
			wchar_t digitChar = static_cast<wchar_t>(digit + 48);
			result[index] = digitChar;
			index--;
			currValue /= 10;
		}

		return result;
	}

	void WriteLine(std::wstring_view message)
	{
		// Get the current time
		time_t rawTime = time(nullptr);
		tm timeInfo;
		localtime_s(&timeInfo, &rawTime);

		std::wcout << L"["
			<< ToString(timeInfo.tm_hour, 2) << L":"
			<< ToString(timeInfo.tm_min, 2) << L":"
			<< ToString(timeInfo.tm_sec, 2) << L"] "
			<< message << std::endl;
	}

	void LogImpl::MessageImpl(std::wstring_view message)
	{
		WriteLine(message);
	}

	void LogImpl::ErrorImpl(std::wstring_view message)
	{
		std::wostringstream errorMessage;
		errorMessage << L"ERROR: " << message;
		WriteLine(errorMessage.str());

#if _DEBUG
		__debugbreak();
#endif

		if (s_showMessageBox)
		{
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
			MessageBoxW(nullptr, message.data(), L"Tracer - Error", MB_OK);
#else
#endif
		}
	}

	void LogImpl::WarningImpl(std::wstring_view message)
	{
		std::wostringstream warningMessage;
		warningMessage << L"WARNING: " << message;
		WriteLine(warningMessage.str());
	}
} // namespace Tracer