#pragma once
#include "EngineMin.h"
#include <Windows.h>
#include "RenderAPI.h"
namespace Engine
{
	class GM_ENGINE Application 
	{
	public:
		Application() = default;

		bool Init();

		void OnCreate(HWND hwnd);

		void Update();

		void OnDestroy();

		inline bool IsRunning() { return bIsRunning; }

	private:
		RenderAPI mRender;

	private:
		HWND  hwnd = nullptr;

		bool bIsRunning = false;
	};
};