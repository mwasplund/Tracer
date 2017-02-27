// <copyright file="Tracer.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include <string>

// Contoller flags defaults 
// Set before include this header to force desired state
#ifndef TRACER_MESSAGE_BOX_ERROR
#define TRACER_MESSAGE_BOX_ERROR true
#endif
#ifndef TRACER_ENABLED
#define TRACER_ENABLED true
#endif

#include "TracerImpl.h"

/// <summary>
/// Core tracer class
/// </summary>
class Tracer : public TracerImpl
{
public:
	/// <summary>
	/// Log a message to std out
	/// </summary>
	inline static void LogMessage(const wchar_t* message) { LogMessageImpl(message); }
	inline static void LogMessage(const std::wstring& message) { LogMessageImpl(message.c_str()); }

	/// <summary>
	/// Log an error to std out
	/// </summary>
	inline static void LogError(const wchar_t* message) { LogErrorImpl(message, TRACER_MESSAGE_BOX_ERROR); }
	inline static void LogError(const std::wstring& message) { LogErrorImpl(message.c_str(), TRACER_MESSAGE_BOX_ERROR); }

	/// <summary>
	/// Log a warning to std out
	/// </summary>
	inline static void LogWarning(const wchar_t* message) { LogWarningImpl(message); }
	inline static void LogWarning(const std::wstring& message) { LogWarningImpl(message.c_str()); }
};

