#include "pch.h"
#include "RenderAPI.h"
#include "DXGIFactory.h"
#include "D12Debug.h"
namespace Engine
{
	void RenderAPI::Init(HWND hwnd)
	{

		D12Debug::Get().Enable();

		DXGIFactory factory;
		DXGIAdapter adapter = factory.GetAdapter();

		DXGI_ADAPTER_DESC desc;
		adapter->GetDesc(&desc);

		PRINT_W_N("Adapter Name: " << desc.Description);

		mDevice.Init(adapter.Get());
	}
}
