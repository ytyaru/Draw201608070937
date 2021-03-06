#include <locale.h>
#include <windows.h>
#include <tchar.h>
#include "IPartWndProc.h"
#include "Window.h"
#include "InitializeWndProc.h"
#include "KeyboardWndProc.h"
#include "GdiWndProc.h"
#include "GdiPlusWndProc.h"
#include "DrawWndProc.h"

using ytyaru::Framework::WndProc::Window;
using ytyaru::Framework::WndProc::IPartWndProc;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	setlocale(LC_ALL, ".ACP");

	Window *pWindow = Window::CreateInstance();

	InitializeWndProc initializeWndProc;
	pWindow->Add((IPartWndProc*)&initializeWndProc);
	
	KeyboardWndProc keyboardWndProc;
	pWindow->Add((IPartWndProc*)&keyboardWndProc);
	
	//GdiWndProc gdiWndProc;
	//pWindow->Add((IPartWndProc*)&gdiWndProc);

	//GdiPlusWndProc gdiPlusWndProc;
	//pWindow->Add((IPartWndProc*)&gdiPlusWndProc);
	
	DrawWndProc drawWndProc;
	pWindow->Add((IPartWndProc*)&drawWndProc);

	pWindow->Create(hInstance);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	Window::RemoveInstance(pWindow);

	return (msg.wParam);
}
