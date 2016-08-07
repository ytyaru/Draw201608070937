#include "DrawWndProc.h"

DrawWndProc::DrawWndProc(void)
{
	m_selected = &m_gdiWndProc;
	//m_selected = &m_gdiPlusWndProc;
	//m_selected = &m_directXWndProc;
}
DrawWndProc::~DrawWndProc(void) {}
LRESULT CALLBACK DrawWndProc::PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn)
{
	m_selected->PartWndProc(hWnd, uMsg, wParam, lParam, pIsReturn);
	return (0L);
}