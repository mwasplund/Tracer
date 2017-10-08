// <copyright file="Tracer.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include <string>

// Contoller flags defaults 
// Set before include this header to force desired state
#ifndef TRACER_ENABLED
#define TRACER_ENABLED true
#endif

#if TRACER_ENABLED==true
#define IF_TRACER_ENABLED(x) { x }
#else
#define IF_TRACER_ENABLED(x)
#endif

#include "LogImpl.h"

namespace Tracer
{
	/// <summary>
	/// Core tracer logging class
	/// </summary>
	class Log : public LogImpl
	{
	public:
		/// <summary>
		/// Log a message to std out
		/// </summary>
		static void Message(const wchar_t* message)
		{
			IF_TRACER_ENABLED(MessageImpl(message);)
		}
		static void Message(const std::wstring& message)
		{
			IF_TRACER_ENABLED(MessageImpl(message.c_str());)
		}
		static void Error(const wchar_t* message)
		{
			IF_TRACER_ENABLED(ErrorImpl(message);)
		}
		static void Error(const std::wstring& message)
		{
			IF_TRACER_ENABLED(ErrorImpl(message.c_str());)
		}
		static void Warning(const wchar_t* message)
		{
			IF_TRACER_ENABLED(WarningImpl(message);)
		}
		static void Warning(const std::wstring& message)
		{
			IF_TRACER_ENABLED(WarningImpl(message.c_str());)
		}
		static void SetShowMessageBox(bool value)
		{
			s_showMessageBox = value;
		}
	};
} // namespace Tracer