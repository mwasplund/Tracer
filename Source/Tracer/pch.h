// <copyright file="pch.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

#ifdef _WIN32
// Exclude rarely-used stuff from Windows headers
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

// STL 
#include <ctime>
#include <iostream>
#include <string>