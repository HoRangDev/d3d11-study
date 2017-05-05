#include "Buffer.h"

Buffer::Buffer( BufferPtr buffer ) :
    m_resource( buffer )
{
}

Buffer::~Buffer( )
{
}

ID3D11Resource* Buffer::GetResource( )
{
    D3D11_BUFFER_DESC d;
    return ( m_resource.Get( ) );
}
