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
    printf( "delta time : %f", &deltaTime );
}

void BasicExample::Render( )
{
    float clearColor[ 4 ] = { 0.0f, 0.125f, 0.3f, 1.0f };
}