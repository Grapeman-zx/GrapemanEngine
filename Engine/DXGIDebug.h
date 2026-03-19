#pragma once
#include<wrl.h>
#include "pch.h"
#include <dxgidebug.h>
namespace Engine
{
	class DXGIDebug :Microsoft::WRL::ComPtr<IDXGIDebug>
	{
	public:
		DXGIDebug() = default;

		static inline DXGIDebug& Get()
		{
			return mInstance;
		}
		void Enable();

		void GetLiveObjects();
	private:
		void GetInterface();
	private:
		static DXGIDebug mInstance;
	};
}