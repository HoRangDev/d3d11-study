#include "App.h"
#include "BasicExample.h"

int main( )
{
    App app{ std::make_shared<BasicExample>( TEXT( "Basic Example" ) ), 800, 600 };
    return app.Run( );
}

int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow )
{
    AllocConsole( );
    freopen( "CONOUT$", "wb", stdout );
    App app{ std::make_shared<BasicExample>( TEXT( "Basic Example" ) ), 800, 600 };
    return app.Run( );
}