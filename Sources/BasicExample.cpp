#include "BasicExample.h"

BasicExample::BasicExample( const std::wstring& name ) : 
    Example( name )
{
}

void BasicExample::Init( )
{

}

void BasicExample::Update( float deltaTime )
{
    system( "cls" );
    printf( "delta time : %f", deltaTime );
}

void BasicExample::Render( )
{
    float clearColor[ 4 ] = { 0.0f, 0.125f, 0.3f, 1.0f };
    m_immediateContext->ClearRenderTargetView( m_renderTargetView, clearColor );
    m_immediateContext->ClearDepthStencilView( m_depthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0 );
    m_swapChain->Present( 0, 0 );
}