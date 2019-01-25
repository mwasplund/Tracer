// <copyright file="Tracer.cppm" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

export module Tracer;
import std.core;

namespace Tracer
{
	/// <summary>
	/// Core tracer logging class
	/// </summary>
	class Log
	{
	public:
		/// <summary>
		/// Log a message to std out
		/// </summary>
		static void Message(const std::wstring message)
		{
			WriteLine(message);
		}

		static void Error(std::wstring message)
		{
			std::wostringstream errorMessage;
			errorMessage << L"ERROR: " << message;
			WriteLine(errorMessage.str());
		}

		static void Warning(std::wstring message)
		{
			std::wostringstream warningMessage;
			warningMessage << L"WARNING: " << message;
			WriteLine(warningMessage.str());
		}

	private:
		static std::wstring ToString(int value, int requiredDigits)
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

		static void WriteLine(std::wstring message)
		{
			// Get the current time
			auto now = std::chrono::system_clock::now();
			auto time = std::chrono::system_clock::to_time_t(now);
			tm timeInfo;
			localtime_s(&timeInfo, &time);

			std::wcout
				<< std::put_time(&timeInfo, L"[%H:%M:%S]")
				<< message 
				<< std::endl;
		}
	};
}
