#include "App.h"

App::App( ExamplePtr runningExample ) :
    m_example( runningExample ),
    m_isRunning( false ),
    m_windowHandle( nullptr )
{
}

App::~App( )
{
}

int App::Run( )
{
    InitWin32( );
    InitD3D( );
    InitExample( );
    m_isRunning = true;

    MSG msg{ 0 };

    while ( m_isRunning )
    {
        if ( PeekMessage( &msg, 0, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            ///
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
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = (WndProc);
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hCursor = LoadCursor( 0, IDC_ARROW );
    wc.lpszClassName = ( *m_example ).GetName( ).c_str( );

    RegisterClass( &wc );

    m_windowHandle = CreateWindow( wc.lpszClassName,
                                   wc.lpszClassName,
                                   WS_OVERLAPPEDWINDOW,
                                   CW_USEDEFAULT,
                                   CW_USEDEFAULT,
                                   CW_USEDEFAULT,
                                   CW_USEDEFAULT,
                                   0,
                                   0,
                                   nullptr,
                                   0 );

    ShowWindow( m_windowHandle, 0 );
    UpdateWindow( m_windowHandle );
}

void App::InitD3D( )
{
}

void App::InitExample( )
{
}

LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch ( msg )
    {
    case WM_DESTROY:
    case WM_CLOSE:
        PostQuitMessage( 0 );
        return 0;

    case WM_SIZE:

        break;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}
