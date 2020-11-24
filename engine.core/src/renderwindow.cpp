// EXTERNAL INCLUDES
#include <Windows.h>
// INTERNAL INCLUDES
#include "renderwindow.h"
#include "logging.h"
#include "input/mouse.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
		case WM_PAINT:
		{
			HDC hdc;
			PAINTSTRUCT ps;
			hdc = BeginPaint(hwnd, &ps);
			EndPaint(hwnd, &ps);
			break;
		}
		case WM_KEYDOWN:
			break;
		case WM_LBUTTONDOWN:
		{
			DebugLog("Left Mouse Click Pos: (%i, %i)", LOWORD(lparam), HIWORD(lparam));
			MouseInput::GetInstance().SetMouseButtonData(MouseButtonData{ EMouseButton::MouseButton1, true });
			break;
		}
		case WM_LBUTTONUP:
		{
			DebugLog("Left Mouse Release Pos: (%i, %i)", LOWORD(lparam), HIWORD(lparam));
			MouseInput::GetInstance().SetMouseButtonData(MouseButtonData{ EMouseButton::MouseButton1, false });
			break;
		}		
		case WM_RBUTTONDOWN:
		{
			DebugLog("Right Mouse Click Pos: (%i, %i)", LOWORD(lparam), HIWORD(lparam));
			MouseInput::GetInstance().SetMouseButtonData(MouseButtonData{ EMouseButton::MouseButton2, true });
			break;
		}
		case WM_RBUTTONUP:
		{
			DebugLog("Right Mouse Release Pos: (%i, %i)", LOWORD(lparam), HIWORD(lparam));
			MouseInput::GetInstance().SetMouseButtonData(MouseButtonData{ EMouseButton::MouseButton2, false });
			break;
		}
		case WM_CLOSE:
		default:
			break;
	}
	return DefWindowProc(hwnd, message, wparam, lparam);
}

intptr_t RenderWindow::Initialize(const char* title, u32 width, u32 height)
{
	HMODULE instance = 0;
	RECT windowRect = { 0 };
	WNDCLASS wc = { 0 };
	UINT style;

	instance = GetModuleHandle(NULL);

	wc.hbrBackground		= (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.hCursor				= LoadCursor(NULL, IDC_ARROW);
	wc.hIcon				= NULL;
	wc.hInstance			= instance;
	wc.lpfnWndProc			= WndProc;
	wc.lpszClassName		= title;
	wc.style				= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;

	if (!RegisterClassA(&wc))
	{
		MessageBoxA(NULL, "Window class could not be registered.", "ERROR!", MB_OK);
		return 0;
	}

	windowRect = {
		static_cast<LONG>((GetSystemMetrics(SM_CXSCREEN) - width) / 2),
		static_cast<LONG>((GetSystemMetrics(SM_CYSCREEN) - height) / 2),
		windowRect.left + static_cast<LONG>(width),
		windowRect.top + static_cast<LONG>(height)
	};

	style = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPCHILDREN | WS_CLIPSIBLINGS;

	AdjustWindowRect(&windowRect, style, false);

	this->handle = reinterpret_cast<intptr_t>(CreateWindowA(
		wc.lpszClassName,
		title,
		style,
		windowRect.left,
		windowRect.top,
		windowRect.right,
		windowRect.bottom,
		NULL, NULL,
		instance,
		NULL
	));

	if (!this->handle)
	{
		MessageBoxA(NULL, "Window could not be created.", "ERROR!", MB_OK);
		return 0;
	}

	ShowWindow(reinterpret_cast<HWND>(this->handle), SW_SHOWNORMAL);
	UpdateWindow(reinterpret_cast<HWND>(this->handle));

	return this->handle;
}
void RenderWindow::PumpMessages(void)
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}