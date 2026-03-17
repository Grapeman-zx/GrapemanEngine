#pragma once
#include "EngineMin.h"
#include <Windows.h>
namespace Engine
{
	class GM_ENGINE Application 
	{
	public:
		Application() = default;

		bool Init();

		void Update();

		inline bool IsRunning() { return bIsRunning; }

	private:
		HWND  hwnd = nullptr;

		bool bIsRunning = false;
	};
};