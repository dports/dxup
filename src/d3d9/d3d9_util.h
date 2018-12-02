#pragma once

#include "d3d9_includes.h"
#include "../util/log.h"
#include "../util/shared_conversions.h"

namespace dxapex {

  namespace convert {
    DXGI_FORMAT format(D3DFORMAT Format);
    D3DFORMAT format(DXGI_FORMAT Format);

    DXGI_MODE_SCANLINE_ORDER scanlineOrdering(D3DSCANLINEORDERING ScanlineOrdering);
    D3DSCANLINEORDERING scanlineOrdering(DXGI_MODE_SCANLINE_ORDER ScanlineOrdering);

    UINT cpuFlags(D3DPOOL pool, UINT usage);
    D3D11_USAGE usage(D3DPOOL pool, UINT usage);

    void lockFlags(D3DPOOL pool, UINT lockFlags, UINT* d3d11Flags, D3D11_MAP* d3d11MapType);

    UINT primitiveData(D3DPRIMITIVETYPE type, UINT count);

    DXGI_FORMAT declType(D3DDECLTYPE type);

    const char* declUsage(D3DDECLUSAGE usage);

    void color(D3DCOLOR color, FLOAT* d3d11Color);
  }

}