// <copyright file="TracerImpl.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "LogImpl.h"
#include <string>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <sstream>

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

	void WriteLine(std::wstring message)
	{
		// Get the current time
		auto now = std::time(nullptr);
		auto tm = *std::localtime(&now);

		std::wcout << std::put_time(&tm, "[%H:%M:%S]") << message << std::endl;
	}

	void LogImpl::MessageImpl(std::wstring message)
	{
		WriteLine(message);
	}

	void LogImpl::ErrorImpl(std::wstring message)
	{
		std::wostringstream errorMessage;
		errorMessage << L"ERROR: " << message;
		WriteLine(errorMessage.str());

#if _DEBUG
		__debugbreak();
#endif

		if (s_showMessageBox)
		{
			// TODO
		}
	}

	void LogImpl::WarningImpl(std::wstring message)
	{
		std::wostringstream warningMessage;
		warningMessage << L"WARNING: " << message;
		WriteLine(warningMessage.str());
	}
} // namespace Tracer
