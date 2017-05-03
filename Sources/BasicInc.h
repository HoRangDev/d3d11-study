#pragma once

#define WIN32_MEAN_AND_LEAN
#include <Windows.h>
#include <d3d11.h>

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <chrono>

using uint32 = unsigned int;
using uint64 = unsigned long long;

using Viewport = D3D11_VIEWPORT;

#define SAFE_RELEASE(r) {if(r!=nullptr) r->Release(); r=nullptr;}