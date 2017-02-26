// <copyright file="Tracer.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include <iostream>
#include <string>

static class Tracer
{
public:
	void LogMessage(const std::wstring& message)
	{
		std::wcout << message << std::endl;
	}
};

