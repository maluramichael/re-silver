#pragma once
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment (lib, "comctl32.lib")

#include <iostream>
#include <windows.h>
#include <tlhelp32.h>

#include "d3d9.h"


// Api Hooks
typedef IDirect3D9 *(WINAPI *D3DC9)(UINT);

// Main hook
IDirect3D9 *WINAPI Hook_Direct3DCreate9(UINT SDKVersion);

// Function prototypes
void Startup(HINSTANCE hInstance);
void Shutdown(HINSTANCE hInstance);

// ImGui's Window Proc
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

// Taken from DXWnd proxy dll project
// https://github.com/dxwnd/
struct d3d9_dll
{
	HMODULE dll;
	FARPROC	Direct3DShaderValidatorCreate9;
	FARPROC	PSGPError;
	FARPROC	PSGPSampleTexture;
	FARPROC	D3DPERF_BeginEvent;
	FARPROC	D3DPERF_EndEvent;
	FARPROC	D3DPERF_GetStatus;
	FARPROC	D3DPERF_QueryRepeatFrame;
	FARPROC	D3DPERF_SetMarker;
	FARPROC	D3DPERF_SetOptions;
	FARPROC	D3DPERF_SetRegion;
	FARPROC	DebugSetLevel;
	FARPROC	DebugSetMute;
	FARPROC	Direct3DCreate9;
	FARPROC	Direct3DCreate9Ex;
} d3d9;

// Function trampolines
__declspec(naked) void FakeDirect3DShaderValidatorCreate9() { _asm { jmp[d3d9.Direct3DShaderValidatorCreate9] } }
__declspec(naked) void FakePSGPError() { _asm { jmp[d3d9.PSGPError] } }
__declspec(naked) void FakePSGPSampleTexture() { _asm { jmp[d3d9.PSGPSampleTexture] } }
__declspec(naked) void FakeD3DPERF_BeginEvent() { _asm { jmp[d3d9.D3DPERF_BeginEvent] } }
__declspec(naked) void FakeD3DPERF_EndEvent() { _asm { jmp[d3d9.D3DPERF_EndEvent] } }
__declspec(naked) void FakeD3DPERF_GetStatus() { _asm { jmp[d3d9.D3DPERF_GetStatus] } }
__declspec(naked) void FakeD3DPERF_QueryRepeatFrame() { _asm { jmp[d3d9.D3DPERF_QueryRepeatFrame] } }
__declspec(naked) void FakeD3DPERF_SetMarker() { _asm { jmp[d3d9.D3DPERF_SetMarker] } }
__declspec(naked) void FakeD3DPERF_SetOptions() { _asm { jmp[d3d9.D3DPERF_SetOptions] } }
__declspec(naked) void FakeD3DPERF_SetRegion() { _asm { jmp[d3d9.D3DPERF_SetRegion] } }
__declspec(naked) void FakeDebugSetLevel() { _asm { jmp[d3d9.DebugSetLevel] } }
__declspec(naked) void FakeDebugSetMute() { _asm { jmp[d3d9.DebugSetMute] } }
__declspec(naked) void FakeDirect3DCreate9() { _asm { jmp[Hook_Direct3DCreate9] } } // Modify the jumps as needed
__declspec(naked) void FakeDirect3DCreate9Ex() { _asm { jmp[d3d9.Direct3DCreate9Ex] } }
