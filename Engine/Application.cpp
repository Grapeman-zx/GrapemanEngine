#include "pch.h"
#include "Application.h"
#include<windowsx.h>

namespace Engine 
{
	LRESULT CALLBACK WindProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lparam) 
	{
		return DefWindowProc(hwnd, msg, wParam, lparam);
	}

	bool Application::Init()
	{
		WNDCLASS wndClass = {};
		wndClass.lpszClassName = L"BaseWindowClass";
		wndClass.style = 0;
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
		wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wndClass.lpszMenuName = 0;
		wndClass.hInstance = 0;
		wndClass.lpfnWndProc = WindProc;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;

		RegisterClass(&wndClass);

		hwnd = CreateWindow(L"BaseWindowClass",L"GEngine",WS_OVERLAPPEDWINDOW,200,200,1280,720,0,0,0,0);
		if (!hwnd) 
		{
			return false;
		}
		ShowWindow(hwnd,SW_SHOW);
		UpdateWindow(hwnd);

		bIsRunning = true;
		return true;
	}
	void Application::Update()
	{

	}
}

