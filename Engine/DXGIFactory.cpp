#include "pch.h"
#include "DXGIFactory.h"
using namespace Engine;

Engine::DXGIFactory::DXGIFactory()
{
	GM_EVAL_HR(CreateDXGIFactory2(0, IID_PPV_ARGS(&ptr_)), "创建DXGI失败");
}

DXGIAdapter Engine::DXGIFactory::GetAdapter()
{
	ComPtr<IDXGIFactory6> fac6;
	ComPtr<IDXGIAdapter> adapter;
	if (Get()->QueryInterface(IID_PPV_ARGS(&fac6)) == S_OK)
	{
		GM_EVAL_HR(fac6->EnumAdapterByGpuPreference(0, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&adapter)), "Can't Find Adapter");
	}
	else 
	{
		GM_ASSERT(false);
	}

	return DXGIAdapter(adapter.Get());
}
