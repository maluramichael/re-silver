#include "main.h"

void Startup(HINSTANCE hInstance)
{
	// Load direct x and acquire the function pointer
	DisableThreadLibraryCalls(hInstance);

	TCHAR szFileName[MAX_PATH] = { 0 };

	GetSystemDirectory(szFileName, MAX_PATH);
	lstrcat(szFileName, "\\d3d9.dll");

	d3d9.dll = LoadLibrary(szFileName);

	d3d9.Direct3DShaderValidatorCreate9 = GetProcAddress(d3d9.dll, "Direct3DShaderValidatorCreate9");
	d3d9.PSGPError						= GetProcAddress(d3d9.dll, "PSGPError");
	d3d9.PSGPSampleTexture				= GetProcAddress(d3d9.dll, "PSGPSampleTexture");
	d3d9.D3DPERF_BeginEvent				= GetProcAddress(d3d9.dll, "D3DPERF_BeginEvent");
	d3d9.D3DPERF_EndEvent				= GetProcAddress(d3d9.dll, "D3DPERF_EndEvent");
	d3d9.D3DPERF_GetStatus				= GetProcAddress(d3d9.dll, "D3DPERF_GetStatus");
	d3d9.D3DPERF_QueryRepeatFrame		= GetProcAddress(d3d9.dll, "D3DPERF_QueryRepeatFrame");
	d3d9.D3DPERF_SetMarker				= GetProcAddress(d3d9.dll, "D3DPERF_SetMarker");
	d3d9.D3DPERF_SetOptions				= GetProcAddress(d3d9.dll, "D3DPERF_SetOptions");
	d3d9.D3DPERF_SetRegion				= GetProcAddress(d3d9.dll, "D3DPERF_SetRegion");
	d3d9.DebugSetLevel					= GetProcAddress(d3d9.dll, "DebugSetLevel");
	d3d9.DebugSetMute					= GetProcAddress(d3d9.dll, "DebugSetMute");
	d3d9.Direct3DCreate9				= GetProcAddress(d3d9.dll, "Direct3DCreate9");
	d3d9.Direct3DCreate9Ex				= GetProcAddress(d3d9.dll, "Direct3DCreate9Ex");

	InitCommonControls();
}

void Shutdown(HINSTANCE hInstance)
{
	// Cleanup code goes here
	FreeLibrary(d3d9.dll);
}

void HookEndScene(IDirect3DDevice9 *pD3DDevice)
{
	// Test clear to make sure function is working
	//D3DRECT testRect = { 0, 0, 400, 80 };
	//pD3DDevice->Clear(1, &testRect, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 0, 0), 0, 0);
}

void HookPreCreateDevice(D3DPRESENT_PARAMETERS *pPresentationParameters)
{
	// Install window hook for input
	if (pPresentationParameters->hDeviceWindow != NULL)
	{
		SetWindowSubclass(pPresentationParameters->hDeviceWindow, SubclassWindowProc, (UINT_PTR)0, (DWORD_PTR)0);
		// TODO: Find a way to parameterize this
		pPresentationParameters->BackBufferWidth = 800;
		pPresentationParameters->BackBufferHeight = 600;
		pPresentationParameters->Windowed = true;
	}
}

void HookPostCreateDevice(IDirect3DDevice9 *pD3DDevice) 
{
}

bool WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID p)
{
	switch (dwReason) {
		
		case DLL_PROCESS_ATTACH:
		{
			Startup(hInstance);
		}
		break;

		case DLL_PROCESS_DETACH:
		{
			Shutdown(hInstance);
		}
		break;

	}
	return TRUE;
}

//
// Function for hooking the main window loop
//
LRESULT CALLBACK SubclassWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
	switch (uMsg) {
		case WM_KEYDOWN:
		{
			// TODO: Maybe create a window/fullscreen toggle
		}
		break;
		case WM_KEYUP:
		{
		}
		break;
	}

	// Pass messages onto the main proc
	return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}

// Our hooked function
IDirect3D9 *WINAPI Hook_Direct3DCreate9(UINT SDKVersion)
{
	// Create a new instance of our wrapper class and pass it to the application
	D3DC9 fnDirect3DCreate9 = (D3DC9)d3d9.Direct3DCreate9;
	return new f_iD3D9(fnDirect3DCreate9(SDKVersion));
}
