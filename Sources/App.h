#pragma once
#include "Example.h"

class App
{
public:
    App( ExamplePtr runningExample, uint32 width, uint32 height );
    virtual ~App( );

    int Run( );
    void Exit( );

    inline HWND GetWindowHandle( ) const { return m_windowHandle; }

    inline uint32 GetWidth( ) const { return m_width; }
    inline uint32 GetHeight( ) const { return m_height; }

    inline ID3D11Device* GetDevice( ) const { return m_device; }
    inline ID3D11DeviceContext* GetImmediateContext( ) const { return m_immediateContext; }
    inline IDXGISwapChain* GetSwapChain( ) const { return m_swapChain; }

private:
    void InitWin32( );
    void InitD3D( );
    void InitExample( );

private:
    ExamplePtr m_example;
    bool m_isRunning;

    HWND m_windowHandle;

    uint32 m_width;
    uint32 m_height;

    ID3D11Device* m_device;
    ID3D11DeviceContext* m_immediateContext;
    IDXGISwapChain* m_swapChain;
    D3D_FEATURE_LEVEL m_featureLevel;
    ID3D11RenderTargetView* m_renderTargetView;
    ID3D11DepthStencilView* m_depthStencilView;
};

LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
using AppPtr = std::shared_ptr<App>;