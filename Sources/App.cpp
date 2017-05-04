#include "App.h"

App::App( ExamplePtr runningExample, uint32 width, uint32 height ) :
    m_example( runningExample ),
    m_isRunning( false ),
    m_windowHandle( nullptr ),
    m_width( width ),
    m_height( height )
{
}

App::~App( )
{
    SAFE_RELEASE( m_depthStencilView );
    SAFE_RELEASE( m_renderTargetView );
    SAFE_RELEASE( m_immediateContext );
    SAFE_RELEASE( m_device );
}

int App::Run( )
{
    InitWin32( );
    InitD3D( );
    InitExample( );
    m_isRunning = true;

    MSG msg{ 0 };

    double deltaTimeVal = 0.0;
    while ( m_isRunning )
    {
        if ( PeekMessage( &msg, 0, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            std::chrono::system_clock::time_point begin = std::chrono::system_clock::now( );
            ( *m_example ).Update( static_cast< float >( deltaTimeVal ) );
            ( *m_example ).Render( );
            std::chrono::duration<double> deltaTime = std::chrono::system_clock::now( ) - begin;
            deltaTimeVal = deltaTime.count( );
        }
    }

    return 0;
}

void App::Exit( )
{
    m_isRunning = false;
}

void App::InitWin32( )
{
    std::wstring title = ( *m_example ).GetName( );
    WNDCLASS wc{ NULL };
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = (WndProc);
    wc.hCursor = LoadCursor( nullptr, IDC_ARROW );
    wc.lpszClassName = title.c_str( );
    RegisterClass( &wc );

    m_windowHandle = CreateWindow( title.c_str( ), title.c_str( ),
                                   WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
                                   CW_USEDEFAULT, CW_USEDEFAULT, m_width, m_height,
                                   nullptr, nullptr, nullptr, nullptr );

}

void App::InitD3D( )
{
    D3D_FEATURE_LEVEL featureLevels[] = { D3D_FEATURE_LEVEL_11_0 };

    uint32 createDeviceFlags{ 0 };
#ifdef _DEBUG | DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    DXGI_SWAP_CHAIN_DESC sd;
    ZeroMemory( &sd, sizeof( sd ) );
    sd.BufferCount = 1;
    sd.BufferDesc.Width = m_width;
    sd.BufferDesc.Height = m_height;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = m_windowHandle;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = true;

    auto hr = D3D11CreateDeviceAndSwapChain( nullptr,
                                   D3D_DRIVER_TYPE_HARDWARE,
                                   nullptr,
                                   createDeviceFlags,
                                   featureLevels,
                                   1,
                                   D3D11_SDK_VERSION,
                                   &sd,
                                   &m_swapChain,
                                   &m_device,
                                   &m_featureLevel,
                                   &m_immediateContext );

    ID3D11Texture2D* backBuffer = nullptr;
    m_swapChain->GetBuffer( 0, __uuidof( ID3D11Texture2D ), (void**)&backBuffer );
    m_device->CreateRenderTargetView( backBuffer, nullptr, &m_renderTargetView );
    backBuffer->Release( );

    D3D11_TEXTURE2D_DESC descDepth;
    ZeroMemory( &descDepth, sizeof( descDepth ) );
    descDepth.Width = m_width;
    descDepth.Height = m_height;
    descDepth.MipLevels = 1;
    descDepth.ArraySize = 1;
    descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDepth.SampleDesc.Count = 1;
    descDepth.SampleDesc.Quality = 0;
    descDepth.Usage = D3D11_USAGE_DEFAULT;
    descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    descDepth.CPUAccessFlags = 0;
    descDepth.MiscFlags = 0;

    ID3D11Texture2D* depthStencilBuffer;
    m_device->CreateTexture2D( &descDepth, nullptr, &depthStencilBuffer );

    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    ZeroMemory( &descDSV, sizeof( descDSV ) );
    descDSV.Format = descDepth.Format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSV.Texture2D.MipSlice = 0;
    m_device->CreateDepthStencilView( depthStencilBuffer, &descDSV, &m_depthStencilView );
    depthStencilBuffer->Release( );

    m_immediateContext->OMSetRenderTargets( 1, &m_renderTargetView, m_depthStencilView );
}

void App::InitExample( )
{
    ( *m_example ).SetWidth( m_width );
    ( *m_example ).SetHeight( m_height );
    ( *m_example ).SetD3DDevice( m_device );
    ( *m_example ).SetImmediateContext( m_immediateContext );
    ( *m_example ).SetSwapChain( m_swapChain );
    ( *m_example ).SetRenderTargetView( m_renderTargetView );
    ( *m_example ).SetDepthStencilView( m_depthStencilView );
    ( *m_example ).SetViewportFitOnWindow( );
    ( *m_example ).Init( );
}

LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch ( msg )
    {
    case WM_DESTROY:
    case WM_CLOSE:
        PostQuitMessage( 0 );
        return 0;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}
