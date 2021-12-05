// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <iostream>

LONG WINAPI UnhandledException(LPEXCEPTION_POINTERS lpInfo)
{
	wchar_t szBuffer[256] = {};
	swprintf(szBuffer, sizeof(szBuffer), L"Unhandled exception: %x\nAt address:\t0x%X", lpInfo->ExceptionRecord->ExceptionCode,
		lpInfo->ExceptionRecord->ExceptionAddress);
	MessageBox(0, szBuffer, L"Unhandled exception", 0);

	return EXCEPTION_EXECUTE_HANDLER;
}
extern "C"
{
	__declspec(dllexport) void InitializeASI()
	{
		SetUnhandledExceptionFilter(UnhandledException);
	}
}

