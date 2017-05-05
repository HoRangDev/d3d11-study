#include "RendererDX11.h"
#include "BasicInc.h"

RendererDX11* RendererDX11::m_sRenderer = nullptr;

RendererDX11::RendererDX11( ) :
    m_device( nullptr ),
    m_debugger( nullptr ),
    m_driverType( D3D_DRIVER_TYPE::D3D_DRIVER_TYPE_NULL )
{
    if ( m_sRenderer == nullptr )
    {
        m_sRenderer = this;
    }
}

RendererDX11::~RendererDX11( )
{
}

bool RendererDX11::Initialization( D3D_DRIVER_TYPE driverType, D3D_FEATURE_LEVEL featureLevel )
{
    HRESULT hr = S_OK;

    uint32 createDeviceFlags = 0;
#ifdef _DEBUG | DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    D3D_FEATURE_LEVEL featureLevels[ ] = { featureLevel };
    D3D_FEATURE_LEVEL createdFeatureLevel;

    DeviceContextPtr context = nullptr;

    hr = D3D11CreateDevice(
        nullptr,
        driverType,
        nullptr,
        createDeviceFlags,
        featureLevels,
        1,
        D3D11_SDK_VERSION,
        m_device.GetAddressOf( ),
        &createdFeatureLevel,
        context.GetAddressOf( )
    );

    if ( FAILED( hr ) )
    {
        return false;
    }

    hr = m_device.CopyTo( m_debugger.GetAddressOf( ) );

    m_featureLevel = m_device->GetFeatureLevel( );

    return true;
}

void RendererDX11::Shutdown( )
{
}
