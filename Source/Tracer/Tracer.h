// <copyright file="Tracer.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include <ctime>
#include <iostream>
#include <string>
#ifdef _WIN32
// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

// Contoller flags defaults 
// Set before include this header to force desired state
#ifndef TRACER_MESSAGE_BOX_ERROR
#define TRACER_MESSAGE_BOX_ERROR true
#endif

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

#if TRACER_MESSAGE_BOX_ERROR
#ifdef _WIN32
		MessageBoxW(nullptr, message.c_str(), L"Error!", MB_OK);
#endif
#endif
	}

	/// <summary>
	/// Log a warning to std out
	/// </summary>
	inline static void LogWarning(const std::wstring& message)
	{
		WriteLine(L"WARNING: " + message);
	}

private:
	/// <summary>
	/// Write a single line message
	/// </summary>
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

