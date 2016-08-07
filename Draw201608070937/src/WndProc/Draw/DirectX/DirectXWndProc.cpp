#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "d3d9.lib")
#include "DirectXWndProc.h"

DirectXWndProc::DirectXWndProc(void)
{
	m_pD3D = NULL;
	m_pD3DDev = NULL;
}
DirectXWndProc::~DirectXWndProc(void) {}
LRESULT CALLBACK DirectXWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_CREATE:
			{
			if( !(m_pD3D = Direct3DCreate9( D3D_SDK_VERSION )) )
			{
				throw "Direct3DCreate9ŠÖ”‚ÉŽ¸”s‚µ‚Ü‚µ‚½B";
			}
			D3DPRESENT_PARAMETERS d3dpp = { 0, 0, D3DFMT_UNKNOWN, 0, D3DMULTISAMPLE_NONE, 0, D3DSWAPEFFECT_DISCARD, NULL, TRUE, 0, D3DFMT_UNKNOWN, 0, 0 };
			
			if( FAILED( m_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &m_pD3DDev ) ) )
			{
				m_pD3D->Release();
				throw "DIRECT3D9.CreateDeviceŠÖ”‚ÉŽ¸”s‚µ‚Ü‚µ‚½B";
			}
			}
			break;
		case WM_DESTROY:
			m_pD3DDev->Release();
			m_pD3D->Release();
			m_pD3DDev = NULL;
			m_pD3D = NULL;
			break;
		case WM_ERASEBKGND:
			*pIsReturn = TRUE;
			return TRUE;
		default:
			if (NULL == m_pD3DDev) { return (0L); }
			OnPaint();
			break;
	}

	return (0L);
}

void DirectXWndProc::OnPaint()
{
	m_pD3DDev->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );
	m_pD3DDev->BeginScene();

	// ‰½‚©•`‰æ‚·‚é

	m_pD3DDev->EndScene();
	m_pD3DDev->Present( NULL, NULL, NULL, NULL );
}