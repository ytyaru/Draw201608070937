#include "GdiWndProc.h"

GdiWndProc::GdiWndProc(void) {}
GdiWndProc::~GdiWndProc(void) {}
LRESULT CALLBACK GdiWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	switch (uMsg) {
		case WM_PAINT:
			HDC hdc;
			PAINTSTRUCT ps;
			LPTSTR lptStr = TEXT("Ç±ÇÃï∂éöóÒÇÕGDIÇ≈ï`âÊÇµÇƒÇ¢Ç‹Ç∑ÅB");
			//hdc = GetDC(hWnd);
			hdc = BeginPaint(hWnd , &ps);
			TextOut(hdc , 10 , 10 , lptStr , _tcslen(lptStr));
			EndPaint(hWnd , &ps);
			//ReleaseDC(hWnd , hdc);
			break;
		//case WM_DESTROY:
		//	//PostQuitMessage(0);
		//	break;
		//default:
		//	return(DefWindowProc(hWnd, uMsg, wParam, lParam));
	}
	return (0L);
}
