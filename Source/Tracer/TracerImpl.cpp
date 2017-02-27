// <copyright file="TracerImpl.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"
#include "TracerImpl.h"

void WriteLine(const wchar_t* message)
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

void TracerImpl::LogMessageImpl(const wchar_t* message)
{
	WriteLine(message);
}

void TracerImpl::LogErrorImpl(const wchar_t* message, bool showMessageBox)
{
	std::wstring errorMessage = std::wstring(L"ERROR: ") + message;
	WriteLine(errorMessage.c_str());

	if (showMessageBox)
	{
#ifdef _WIN32
		MessageBoxW(nullptr, message, L"Tracer - Error", MB_OK);
#endif
	}
}

void TracerImpl::LogWarningImpl(const wchar_t* message)
{
	std::wstring warningMessage = std::wstring(L"WARNING: ") + message;
	WriteLine(warningMessage.c_str());
}