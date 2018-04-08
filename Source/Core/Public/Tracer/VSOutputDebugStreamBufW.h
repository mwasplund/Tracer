// <copyright file="VSOutputDebugStreamBufW.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once
#include <vector>
#include <string>
#include <cassert>
#include <functional>

/// <summary>
/// A helper class used to capture a stream and pipe the values to the visual studio debug console
/// </summary>
class VSOutputDebugStreamBufW : public std::wstreambuf
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="VSOutputDebugStreamBufW"/> class
	/// </summary>
	explicit VSOutputDebugStreamBufW(std::size_t bufferSize = 256) :
		m_buffer(bufferSize + 2)
	{
		// -2 to leave room for overflow (if "full")
		// and to always have room to the null terminated string
		wchar_t* base = &m_buffer.front();
		setp(base, base + m_buffer.size() - 2);
	}

private:
	/// <summary>
	/// xsputn
	/// </summary>
	std::streamsize xsputn(const wchar_t* ptr, std::streamsize count) override
	{
		std::streamsize copied = std::wstreambuf::xsputn(ptr, count);
		WriteOutputAndFlush();
		return copied;
	}

	/// <summary>
	/// overflow
	/// </summary>
	int_type overflow(int_type ch) override
	{
		if (ch != traits_type::eof())
		{
			assert(std::less_equal<wchar_t*>()(pptr(), epptr()));
			*pptr() = ch;
			pbump(1);
			if (WriteOutputAndFlush())
			{
				return ch;
			}
		}

		return traits_type::eof();
	}

	/// <summary>
	/// sync
	/// </summary>
	int sync() override
	{
		return WriteOutputAndFlush() ? 0 : -1;
	}

	/// <summary>
	/// Write Output And Flush
	/// </summary>
	bool WriteOutputAndFlush()
	{
		// Calculate string length
		ptrdiff_t n = pptr() - pbase();

		// Set the end of the string to null
		assert(static_cast<size_t>(n) < m_buffer.size());
		m_buffer[n] = 0;

		// Write the output to the console
		OutputDebugStringW(pbase());

		// Reset the buffer
		pbump(static_cast<int>(-n));

		return true;
	}

	/// <summary>
	/// copying not allowed
	/// </summary>
	VSOutputDebugStreamBufW(const VSOutputDebugStreamBufW&);
	VSOutputDebugStreamBufW &operator=(const VSOutputDebugStreamBufW&);

private:
	/// <summary>
	/// The buffer
	/// </summary>
	std::vector<wchar_t> m_buffer;
};