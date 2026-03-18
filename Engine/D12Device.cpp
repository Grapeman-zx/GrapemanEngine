#include "pch.h"
#include "D12Device.h"

Engine::D12Device::D12Device(IDXGIAdapter* pAdapter)
{
	Init(pAdapter);
}

void Engine::D12Device::Init(IDXGIAdapter* pAdapter)
{
	GM_EVAL_HR(D3D12CreateDevice(pAdapter, D3D_FEATURE_LEVEL_12_2, IID_PPV_ARGS(GetAddressOf())), "Error Create d12 device");
}
