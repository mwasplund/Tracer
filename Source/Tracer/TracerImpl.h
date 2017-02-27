// <copyright file="TracerImpl.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

/// <summary>
/// Implementation of all tracing functionality
/// </summary>
class TracerImpl
{
protected:
	/// <summary>
	/// Logging api implementation
	/// </summary>
	static void _stdcall LogMessageImpl(const wchar_t* message);
	static void _stdcall LogErrorImpl(const wchar_t* message, bool showMessageBox);
	static void _stdcall LogWarningImpl(const wchar_t* message);
};

