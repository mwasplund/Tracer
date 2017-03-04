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

#if TRACER_ENABLED==true
#define IF_TRACER_ENABLED(x) { x }
#else
#define IF_TRACER_ENABLED(x)
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
	inline static void LogMessage(const wchar_t* message) { IF_TRACER_ENABLED(LogMessageImpl(message);) }
	inline static void LogMessage(const std::wstring& message) { IF_TRACER_ENABLED(LogMessageImpl(message.c_str());) }
	inline static void LogError(const wchar_t* message) { IF_TRACER_ENABLED(LogErrorImpl(message, TRACER_MESSAGE_BOX_ERROR);) }
	inline static void LogError(const std::wstring& message) { IF_TRACER_ENABLED(LogErrorImpl(message.c_str(), TRACER_MESSAGE_BOX_ERROR);) }
	inline static void LogWarning(const wchar_t* message) { IF_TRACER_ENABLED(LogWarningImpl(message);) }
	inline static void LogWarning(const std::wstring& message) { IF_TRACER_ENABLED(LogWarningImpl(message.c_str());) }
};

