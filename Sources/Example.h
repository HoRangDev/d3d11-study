#pragma once
#include "BasicInc.h"

class App;
class Example
{
    friend App;
public:
    explicit Example( const std::wstring& name );
    virtual ~Example( );

    virtual void Init( ) = 0;
    virtual void Update( float deltaTime ) = 0;
    virtual void Render( ) = 0;
    std::wstring GetName( ) const;

    void SetD3DDevice( ID3D11Device* device );
    void SetImmediateContext( ID3D11DeviceContext* context );
    void SetSwapChain( IDXGISwapChain* swapChain );
    void SetRenderTargetView( ID3D11RenderTargetView* renderTargetView );

private:
    std::wstring m_name;

    HWND m_windowHandle;

    uint32 m_width;
    uint32 m_height;

    ID3D11Device* m_device;
    ID3D11DeviceContext* m_immediateContext;
    IDXGISwapChain* m_swapChain;
    ID3D11RenderTargetView* m_renderTargetView;

};

using ExamplePtr = std::shared_ptr<Example>;