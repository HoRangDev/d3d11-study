#include "Example.h"

Example::Example( const std::wstring& name ) :
    m_name( name )
{

}

Example::~Example( )
{
}

std::wstring Example::GetName( ) const
{
    return m_name;
}
