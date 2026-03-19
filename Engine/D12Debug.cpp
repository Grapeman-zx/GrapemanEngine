#include "pch.h"
#include"D12Debug.h"

namespace Engine
{
	D12Debug D12Debug::mInstance;

	void Engine::D12Debug::Enable()
	{
		GetInterface();
		Get()->EnableDebugLayer();
	}

	void Engine::D12Debug::GetInterface()
	{
		if (!Get())
		{
			GM_EVAL_HR(D3D12GetDebugInterface(IID_PPV_ARGS(GetAddressOf())),"Error Get debug interface");
		}
	}

}
