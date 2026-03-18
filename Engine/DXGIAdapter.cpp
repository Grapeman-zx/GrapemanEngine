#include "pch.h"
#include "DXGIAdapter.h"

Engine::DXGIAdapter::DXGIAdapter(IDXGIAdapter* pAdapter) :Microsoft::WRL::ComPtr<IDXGIAdapter>(pAdapter)
{
}
