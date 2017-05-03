#pragma once
#include "Example.h"

class BasicExample : public Example
{
public:
    BasicExample( const std::wstring& name );
    ~BasicExample( ){ }

    virtual void Init( ) override;
    virtual void Update( float deltaTime ) override;
    virtual void Render( ) override;

};