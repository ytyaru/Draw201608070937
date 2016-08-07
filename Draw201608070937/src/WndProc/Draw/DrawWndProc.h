#pragma once
#include "IPartWndProc.h"
#include "GdiWndProc.h"
#include "GdiPlusWndProc.h"
#include "DirectXWndProc.h"
// 描画アーキテクチャを選択する
class DrawWndProc : public ytyaru::Framework::WndProc::IPartWndProc
{
public:
	DrawWndProc(void);
	~DrawWndProc(void);
	LRESULT CALLBACK PartWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL* pIsReturn);
private:
	ytyaru::Framework::WndProc::IPartWndProc* m_selected;
	GdiWndProc m_gdiWndProc;
	GdiPlusWndProc m_gdiPlusWndProc;
	DirectXWndProc m_directXWndProc;
};

