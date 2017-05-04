#pragma once
#include "Example.h"

struct SimpleVertex
{
    float xx;
    float yy;
    float zz;
};

class TriangleExample : public Example
{
public:
    TriangleExample( const std::wstring& name );
    ~TriangleExample( );

    virtual void Init( ) override;
    virtual void Update( float deltaTime ) override;
    virtual void Render( ) override;

private:
    BufferPtr m_vb;
    InputLayoutPtr m_inputLayout;
    VertexShaderPtr m_vs;
    PixelShaderPtr m_ps;

};