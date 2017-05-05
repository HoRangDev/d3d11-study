#pragma once
#include "Resource.h"

class Buffer : public Resource
{
public:
    Buffer( BufferPtr buffer );
    virtual ~Buffer( );

    virtual ID3D11Resource* GetResource( ) override;

protected:
    BufferPtr m_resource;

};
