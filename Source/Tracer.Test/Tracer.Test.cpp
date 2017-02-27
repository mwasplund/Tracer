// <copyright file="Tracer.Test.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"

#include <VSOutputDebugStreamBufW.h>
#include <CaptureStream.h>

int main()
{
	Tracer::LogMessage(L"Test Log Message.");
	Tracer::LogError(L"Test Log Error.");
	Tracer::LogWarning(L"Test Log Warning.");

	{
		CaptureStream<VSOutputDebugStreamBufW> capture(&std::wcout);
		Tracer::LogMessage(L"Test Log Message to VS.");
		Tracer::LogError(L"Test Log Error to VS.");
		Tracer::LogWarning(L"Test Log Warning to VS.");
	}

	Tracer::LogMessage(L"Test Log Message 2.");
	Tracer::LogError(L"Test Log Error 2.");
	Tracer::LogWarning(L"Test Log Warning 2.");

	return 0;
}

