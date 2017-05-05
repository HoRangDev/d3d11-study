#include "Resource.h"

int Resource::m_scInnerID = 0;

Resource::Resource( ) :
    m_innerID( 0 )
{
    m_innerID = m_scInnerID;
    ++m_scInnerID;
}

Resource::~Resource( )
{
    // Empty
}
