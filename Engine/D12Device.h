#pragma once
#include <wrl.h>
#include "pch.h"
namespace Engine 
{
	class D12Device : public Microsoft::WRL::ComPtr<ID3D12Device>
	{
	public:
		D12Device() = default;

		D12Device(IDXGIAdapter* pAdapter);

		void Init(IDXGIAdapter* pAdapter);
	};
}