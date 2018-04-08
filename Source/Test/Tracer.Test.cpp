// <copyright file="Tracer.Test.cpp" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#include "pch.h"

#include <Tracer\VSOutputDebugStreamBufW.h>
#include <Tracer\CaptureStream.h>

int main()
{
	Tracer::Log::SetShowMessageBox(false);

	Tracer::Log::Message(L"Test Log Message.");
	Tracer::Log::Error(L"Test Log Error.");
	Tracer::Log::Warning(L"Test Log Warning.");

	{
		CaptureStream<VSOutputDebugStreamBufW> capture(&std::wcout);
		Tracer::Log::Message(L"Test Log Message to VS.");
		Tracer::Log::Error(L"Test Log Error to VS.");
		Tracer::Log::Warning(L"Test Log Warning to VS.");
	}

	Tracer::Log::Message(L"Test Log Message 2.");
	Tracer::Log::Error(L"Test Log Error 2.");
	Tracer::Log::Warning(L"Test Log Warning 2.");

	return 0;
}
