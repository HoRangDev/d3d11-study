#pragma once
#include "BasicInc.h"

class App;
class Example
{
    friend App;
public:
    explicit Example( const std::wstring& name );
    virtual ~Example( );

    virtual void Update( float deltaTime ) = 0;
    std::wstring GetName( ) const;

private:
    std::wstring m_name;

};

using ExamplePtr = std::shared_ptr<Example>;