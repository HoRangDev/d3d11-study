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
