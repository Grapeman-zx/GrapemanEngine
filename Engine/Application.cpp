#include "pch.h"
#include "Application.h"
#include<windowsx.h>

namespace Engine
{
	LRESULT CALLBACK WindProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lparam)
	{
		switch (msg) {
		case WM_NCCREATE: {
			// 1. 从 lParam 中提取 CREATESTRUCT 结构体指针
			LPCREATESTRUCT param = reinterpret_cast<LPCREATESTRUCT>(lparam);

			// 2. 从结构体中获取我们在 CreateWindowEx 中传入的自定义指针（通常是 this）
			Application* pointer = reinterpret_cast<Application*>(param->lpCreateParams);

			// 3. 将该指针存入窗口的 User Data 区域，方便后续消息取出使用
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pointer));


			break;
		}

		case WM_CREATE: {
			// 4. 在后续消息中，通过 GWLP_USERDATA 重新获取对应的 Application 对象指针
			Application* pointer = reinterpret_cast<Application*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

			pointer->OnCreate(hwnd);
			break;
		}
		case WM_DESTROY: {
						  Application* pointer = reinterpret_cast<Application*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
						  pointer->OnDestroy();
						  PostQuitMessage(0);
						  break;
		}
		}
		return DefWindowProc(hwnd, msg, wParam, lparam);
	}

	bool Application::Init()
	{
		WNDCLASS wndClass = {};
		wndClass.lpszClassName = L"BaseWindowClass";
		wndClass.style = 0;
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wndClass.lpszMenuName = 0;
		wndClass.hInstance = 0;
		wndClass.lpfnWndProc = WindProc;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;

		RegisterClass(&wndClass);

		hwnd = CreateWindow(L"BaseWindowClass", L"GEngine", WS_OVERLAPPEDWINDOW, 200, 200, 1280, 720, 0, 0, 0, this);
		if (!hwnd)
		{
			return false;
		}
		ShowWindow(hwnd, SW_SHOW);
		UpdateWindow(hwnd);

		bIsRunning = true;
		return true;
	}
	void Application::OnCreate(HWND hwnd)
	{
		mRender.Init(hwnd);
	}
	void Application::Update()
	{
		MSG message;
		while (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessageW(&message);
		}
	}
	void Application::OnDestroy()
	{
		bIsRunning = false;
	}
}

