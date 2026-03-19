#pragma once
#include<wrl.h>
#include "pch.h"
namespace Engine 
{
	class D12Debug :Microsoft::WRL::ComPtr<ID3D12Debug>
	{
	public:
		D12Debug() = default;

		static inline D12Debug& Get()
		{
			return mInstance;
		}
		void Enable();
	private:
		void GetInterface();
	private:
		static D12Debug mInstance;
	};
}