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

    void SetD3DDevice( DevicePtr device );
    void SetImmediateContext( DeviceContextPtr context );
    void SetSwapChain( IDXGISwapChain* swapChain );
    void SetRenderTargetView( RTVPtr renderTargetView );
    void SetDepthStencilView( DSVPtr depthStencilView );
    void SetViewport( Viewport viewport );
    void SetViewport( float topLeftX, float topLeftY, float width, float height, float minDepth, float maxDepth );
    void SetWidth( uint32 width );
    void SetHeight( uint32 height );
    void SetViewportFitOnWindow( );

    inline Viewport GetViewport( ) const { return m_viewport; }

protected:
    std::wstring m_name;

    HWND m_windowHandle;

    uint32 m_width;
    uint32 m_height;

    DevicePtr m_device;
    DeviceContextPtr m_immediateContext;
    IDXGISwapChain* m_swapChain;
    RTVPtr m_renderTargetView;
    DSVPtr m_depthStencilView;
    Viewport m_viewport;

};

using ExamplePtr = std::shared_ptr<Example>;