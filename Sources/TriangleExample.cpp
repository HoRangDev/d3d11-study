#include "TriangleExample.h"

TriangleExample::TriangleExample( const std::wstring& name ) :
    m_vb( nullptr ),
    Example( name )
{
}

TriangleExample::~TriangleExample( )
{
}

void TriangleExample::Init( )
{
    BlobPtr blobVS = nullptr;
    auto hr = D3DCompileFromFile(
        L"D:/Project/Developement/Practice/d3d11-study/Sources/Shaders/SimpleVertexShader.hlsl",
        nullptr,
        nullptr,
        "main",
        "vs_4_0",
        D3D10_SHADER_ENABLE_STRICTNESS | D3D10_SHADER_PACK_MATRIX_COLUMN_MAJOR,
        0,
        blobVS.GetAddressOf( ),
        nullptr );

    m_device->CreateVertexShader( blobVS->GetBufferPointer( ), blobVS->GetBufferSize( ),
                                  nullptr, m_vs.GetAddressOf( ) );

    D3D11_INPUT_ELEMENT_DESC layout[] = 
    {
        { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }
    };

    m_device->CreateInputLayout( layout, 1,
                                 blobVS->GetBufferPointer( ), blobVS->GetBufferSize( ),
                                 m_inputLayout.GetAddressOf( ) );

    BlobPtr blobPS = nullptr;
    hr = D3DCompileFromFile(
        TEXT( "D:/Project/Developement/Practice/d3d11-study/Sources/Shaders/SimplePixelShader.hlsl" ),
        nullptr,
        nullptr,
        "main",
        "ps_4_0",
        D3D10_SHADER_ENABLE_STRICTNESS | D3D10_SHADER_PACK_MATRIX_COLUMN_MAJOR,
        0,
        blobPS.GetAddressOf( ),
        nullptr );

    m_device->CreatePixelShader( blobPS->GetBufferPointer( ),
                                  blobPS->GetBufferSize( ),
                                  nullptr,
                                  m_ps.GetAddressOf( ) );

    m_immediateContext->IASetInputLayout( m_inputLayout.Get( ) );

    // Vertex Buffer Initialization
    D3D11_BUFFER_DESC bufferDesc;
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = sizeof( SimpleVertex ) * 3;
    bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bufferDesc.CPUAccessFlags = 0;
    bufferDesc.MiscFlags = 0;
    bufferDesc.StructureByteStride = 0;

    SimpleVertex vertices[ 3 ] =
    {
        { 0.0f, 0.5f, 0.5f },
        { 0.5f, -0.5f, 0.5f },
        { -0.5f, -0.5f, 0.5f }
    };

    D3D11_SUBRESOURCE_DATA subRes;
    subRes.pSysMem = vertices;
    subRes.SysMemPitch = 0;
    subRes.SysMemSlicePitch = 0;

    m_device->CreateBuffer( &bufferDesc, &subRes, m_vb.GetAddressOf( ) );

    uint32 stride = sizeof( SimpleVertex );
    uint32 offset = 0;
    m_immediateContext->IASetVertexBuffers( 0, 1, m_vb.GetAddressOf( ), &stride, &offset );
    m_immediateContext->IASetPrimitiveTopology( D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST );

    m_immediateContext->VSSetShader( m_vs.Get( ), nullptr, 0 );
    m_immediateContext->PSSetShader( m_ps.Get( ), nullptr, 0 );
}

void TriangleExample::Update( float deltaTime )
{
}

void TriangleExample::Render( )
{
    float clearColor[ 4 ] = { 0.0f, 0.0f, 0.0f, 1.0f };
    m_immediateContext->ClearRenderTargetView( m_renderTargetView.Get( ),
                                               clearColor );
    m_immediateContext->ClearDepthStencilView( m_depthStencilView.Get( ),
                                               D3D11_CLEAR_DEPTH, 1.0f, 0 );

    m_immediateContext->Draw( 3, 0 );

    m_swapChain->Present( 0, 0 );
}