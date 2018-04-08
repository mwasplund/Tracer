// <copyright file="CaptureStream.h" company="mwasplund"> 
//     Copyright (c) MWASPLUND. All rights reserved.
// </copyright>

#pragma once

/// <summary>
/// A helper class used to capture a stream and pipe it into the provided buffer
/// </summary>
template<typename TStreamBuf>
class CaptureStream
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="CaptureStream"/> class
	/// </summary>
	CaptureStream(std::wostream* stream) :
		m_outBuf(),
		m_stream(stream),
		m_previousBuffer(stream->rdbuf(&m_outBuf))
	{
	}

	/// <summary>
	/// Finalizes an instance of the <see cref="CaptureStream"/> class
	/// </summary>
	~CaptureStream()
	{
		m_stream->rdbuf(m_previousBuffer);
	}

private:
	/// <summary>
	/// The output buffer
	/// </summary>
	TStreamBuf m_outBuf;

	/// <summary>
	/// The cached stream
	/// </summary>
	std::wostream* m_stream;

	/// <summary>
	/// The old buffer
	/// </summary>
	std::wstreambuf* m_previousBuffer;
};
