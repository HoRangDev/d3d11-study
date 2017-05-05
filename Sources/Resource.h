#pragma once
#include "BasicInc.h"

enum class ResourceType
{
    RT_VertexBuffer,
    RT_IndexBuffer,
    RT_ConstantBuffer,
    RT_Texture1D,
    RT_Texture2D,
    RT_Texture3D
};

class Resource
{
public:
    Resource( );
    virtual ~Resource( );

    inline int GetInnerID( ) const { return m_innerID; }

    virtual ResourceType GetTyep( ) const = 0;
    virtual ID3D11Resource* GetResource( ) = 0;

protected:
    int m_innerID;

private:
    static int m_scInnerID;

};