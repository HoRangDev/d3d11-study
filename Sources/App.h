#pragma once
#include "Example.h"

class App
{
public:
    App( ExamplePtr runningExample );
    virtual ~App( );

    int Run( );
    void Exit( );

private:
    void InitWin32( );
    void InitD3D( );
    void InitExample( );

private:
    ExamplePtr m_example;
    bool m_isRunning;

    HWND m_windowHandle;

};

LRESULT CALLBACK WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
using AppPtr = std::shared_ptr<App>;