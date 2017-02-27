// <copyright file="Tracer.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include <ctime>
#include <iostream>
#include <string>

/// <summary>
/// Core tracer class
/// </summary>
class Tracer
{
public:
	/// <summary>
	/// Log a message to std out
	/// </summary>
	inline static void LogMessage(const std::wstring& message)
	{
		WriteLine(message);
	}

	/// <summary>
	/// Log an error to std out
	/// </summary>
	inline static void LogError(const std::wstring& message)
	{
		WriteLine(L"ERROR: " + message);
	}

	/// <summary>
	/// Log a warning to std out
	/// </summary>
	inline static void LogWarning(const std::wstring& message)
	{
		WriteLine(L"WARNING: " + message);
	}

private:
	inline static void WriteLine(const std::wstring& message)
	{
		// Get the current time
		time_t rawTime = time(nullptr);
		tm timeInfo;
		localtime_s(&timeInfo, &rawTime);

		std::wcout << L"[" 
			<< timeInfo.tm_hour << L":"
			<< timeInfo.tm_min << L":" 
			<< timeInfo.tm_sec << L"] " 
			<< message << std::endl;
	}
};

