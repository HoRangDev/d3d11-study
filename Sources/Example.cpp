#include "Example.h"

Example::Example( const std::wstring& name ) :
    m_name( name )
{

}

Example::~Example( )
{
}

std::wstring Example::GetName( ) const
{
    return m_name;
}

void Example::SetD3DDevice( ID3D11Device* device )
{
    m_device = device;
}

void Example::SetImmediateContext( ID3D11DeviceContext* context )
{
    m_immediateContext = context;
}

void Example::SetSwapChain( IDXGISwapChain* swapChain )
{
    m_swapChain = swapChain;
}

void Example::SetRenderTargetView( ID3D11RenderTargetView* renderTargetView )
{
    m_renderTargetView = renderTargetView;
}

void Example::SetDepthStencilView( ID3D11DepthStencilView* depthStencilView )
{
    m_depthStencilView = depthStencilView;
}

void Example::SetViewport( Viewport viewport )
{
    m_viewport = viewport;
    Viewport vps[] = { viewport };
    m_immediateContext->RSSetViewports( 1, vps );
}

void Example::SetViewport( float topLeftX, float topLeftY, float width, float height, float minDepth, float maxDepth )
{
    auto vp = Viewport( );
    vp.TopLeftX = topLeftX;
    vp.TopLeftY = topLeftY;
    vp.Width = width;
    vp.Height = height;
    vp.MinDepth = minDepth;
    vp.MaxDepth = maxDepth;
    SetViewport( vp );
}

void Example::SetWidth( uint32 width )
{
    m_width = width;
}

void Example::SetHeight( uint32 height )
{
    m_height = height;
}

void Example::SetViewportFitOnWindow( )
{
    SetViewport( 0, 0, m_width, m_height, 0.0f, 1.0f );
}
