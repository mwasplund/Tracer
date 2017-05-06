# Tracer
A c++ class based tracer for simple program logging to std out.

By default Trace will be enabled for all builds, however any client can override
the default behavior to either allow tracer to be compiled out when desired.
When disabled the Tracer methods will result in NO-OPs and any will be removed by the compiler.
#Enable debug builds
```c++
#ifdef DEBUG
#define TRACER_ENABLED true
#else
#define TRACER_ENABLED false
#endif
```
#Example
```c++
Tracer::LogMessage(L"Test Log Message.");
Tracer::LogError(L"Test Log Error.");
Tracer::LogWarning(L"Test Log Warning.");
```
```c++
{
	CaptureStream<VSOutputDebugStreamBufW> capture(&std::wcout);
	Tracer::LogMessage(L"Test Log Message to VS.");
	Tracer::LogError(L"Test Log Error to VS.");
	Tracer::LogWarning(L"Test Log Warning to VS.");	
}
```
