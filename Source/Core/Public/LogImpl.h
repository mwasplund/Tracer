// <copyright file="LogImpl.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include <string>

namespace Tracer
{
	/// <summary>
	/// Implementation of all tracing logging functionality
	/// </summary>
	class LogImpl
	{
	protected:
		/// <summary>
		/// A value that indicates if the message box should be used
		/// </summary>
		static bool s_showMessageBox;

		/// <summary>
		/// Logging api implementation
		/// </summary>
		static void _stdcall MessageImpl(std::wstring message);
		static void _stdcall ErrorImpl(std::wstring message);
		static void _stdcall WarningImpl(std::wstring message);
	};
} // namespace Tracer
