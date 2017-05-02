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
    void SetDepthStencilView( ID3D11DepthStencilView* depthStencilView );
    void SetViewport( Viewport viewport );
    void SetViewport( float topLeftX, float topLeftY, float width, float height, float minDepth, float maxDepth );
    void SetWidth( uint32 width );
    void SetHeight( uint32 height );
    void SetViewportFitOnWindow( );

    inline Viewport GetViewport( ) const { return m_viewport; }

private:
    std::wstring m_name;

    HWND m_windowHandle;

    uint32 m_width;
    uint32 m_height;

    ID3D11Device* m_device;
    ID3D11DeviceContext* m_immediateContext;
    IDXGISwapChain* m_swapChain;
    ID3D11RenderTargetView* m_renderTargetView;
    ID3D11DepthStencilView* m_depthStencilView;
    Viewport m_viewport;

};

using ExamplePtr = std::shared_ptr<Example>;