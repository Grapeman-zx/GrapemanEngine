#pragma once
#include"EngineMin.h"
#include "D12Device.h"
namespace Engine
{
	class GM_ENGINE RenderAPI
	{
	public:
		RenderAPI() = default;
		~RenderAPI() {}

	public:
		void Init(HWND hwnd);

	private:

		D12Device mDevice;
	};
}