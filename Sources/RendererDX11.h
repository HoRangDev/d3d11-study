#pragma once
#include "BasicInc.h"

class RendererDX11
{
public:
    RendererDX11( );
    ~RendererDX11( );

    bool Initialization( D3D_DRIVER_TYPE driverType, D3D_FEATURE_LEVEL featureLevel );
    void Shutdown( );

    ID3D11Device* GetRawDevice( ) const;
    D3D_DRIVER_TYPE GetDriverType( ) const;
    D3D_FEATURE_LEVEL GetFeatureLevel( ) const;


protected:
    static RendererDX11* m_sRenderer;
    DevicePtr m_device;
    D3D11DebuggerPtr m_debugger;
    D3D_DRIVER_TYPE m_driverType;
    D3D_FEATURE_LEVEL m_featureLevel;

};