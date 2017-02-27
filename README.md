# Tracer
A c++ class based tracer for simple program logging to std out.

#Example
```
Tracer::LogMessage(L"Test Log Message.");
Tracer::LogError(L"Test Log Error.");
Tracer::LogWarning(L"Test Log Warning.");
```
```
{
	CaptureStream<VSOutputDebugStreamBufW> capture(&std::wcout);
	Tracer::LogMessage(L"Test Log Message to VS.");
	Tracer::LogError(L"Test Log Error to VS.");
	Tracer::LogWarning(L"Test Log Warning to VS.");	
}
```
