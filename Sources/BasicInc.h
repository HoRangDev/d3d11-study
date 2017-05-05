#pragma once

#define WIN32_MEAN_AND_LEAN
#include <Windows.h>
#include <d3d11_1.h>
#include <d3dCompiler.h>

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <chrono>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <exception>
#include <fstream>
#include <list>
#include <sstream>
#include <algorithm>
#include <wrl.h>

using uint32 = unsigned int;
using uint64 = unsigned long long;
using Viewport = D3D11_VIEWPORT;

template <typename T>
using ComPtr = Microsoft::WRL::ComPtr<T>;
using DevicePtr = Microsoft::WRL::ComPtr<ID3D11Device>;
using DeviceContextPtr = Microsoft::WRL::ComPtr<ID3D11DeviceContext>;
using D3D11DebuggerPtr = ComPtr<ID3D11Debug>;

using RTVPtr = Microsoft::WRL::ComPtr<ID3D11RenderTargetView>;
using DSVPtr = Microsoft::WRL::ComPtr<ID3D11DepthStencilView>;

using BufferPtr = Microsoft::WRL::ComPtr<ID3D11Buffer>;
using BlobPtr = Microsoft::WRL::ComPtr<ID3DBlob>;
using InputLayoutPtr = Microsoft::WRL::ComPtr<ID3D11InputLayout>;
using VertexShaderPtr = Microsoft::WRL::ComPtr<ID3D11VertexShader>;
using PixelShaderPtr = Microsoft::WRL::ComPtr<ID3D11PixelShader>;

#define SAFE_RELEASE(r) {if(r!=nullptr) r->Release(); r=nullptr;}