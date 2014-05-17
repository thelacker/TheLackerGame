#include <afxwin.h>
#include <time.h>
#include "DefineIDC.h"
#include "MainWindowClass.h"
#include "MessageMap.h"
#include "Game.h"
#include "ButtonsClick.h"

CMainWin::CMainWin()
{
	int X = GetSystemMetrics(SM_CXSCREEN);
	int Y = GetSystemMetrics(SM_CYSCREEN);
	CRect rect(X/3, Y/5, 9*X/16, Y/2);
	Create(NULL, _T("TheLacker Game"), WS_BORDER, rect);
	NewGame.Create(_T("New Game"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, RECT_NEWGAME, this, IDC_ngb);
	Exit.Create(_T("Exit"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, RECT_EXIT, this, IDC_exb);
	High.Create(_T("High Scores"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, RECT_HSB, this, IDC_hsb);
}

void CMainWin::OnPaint()
{
	NewGame.DestroyWindow();
	Exit.DestroyWindow();
	High.DestroyWindow();
}



BOOL CMainWin::OnEraseBkgnd(CDC* pDC)
{
	CBrush backBrush(BACK_COLOR);
	CBrush* pOldBrush = pDC->SelectObject(&backBrush);
	CRect rect;
	pDC->GetClipBox(&rect);
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOldBrush);
	return TRUE;
}

class CApp : public CWinApp
{
public:
	BOOL InitInstance();
};

BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWin;
	m_pMainWnd->SetTimer(1, 1000, 0);
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CApp App;