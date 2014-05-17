#include <afxwin.h>
#include <time.h>
#include "DefineIDC.h"
#include "MainWindowClass.h"
#include "MessageMap.h"
#include "Game.h"
#include "ButtonsClick.h"

CMainWin::CMainWin()
{
	CRect rect(X/3, Y/5, 9*X/16, Y/2);

	Create(NULL,	_T("TheLacker Game"),	WS_BORDER,	rect);
	NewGame.Create(	_T("New Game"),			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,				RECT_NEWGAME,		this,	IDC_ngb);
	Exit.Create(	_T("Exit"),				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,				RECT_EXIT,			this,	IDC_exb);
	High.Create(	_T("High Scores"),		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,				RECT_HSB,			this,	IDC_hsb);
	GameExit.Create(_T("||"),				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT,	RECT_GEB,			this,	IDC_geb);
	SetTimer(1, 1000, NULL);
	timerflag = false;
	timer = 0;
	sound = MB_ICONWARNING;
}

void CMainWin::OnPaint()
{
	NewGame.DestroyWindow();
	Exit.DestroyWindow();
	High.DestroyWindow();
}



BOOL CMainWin::OnEraseBkgnd(CDC* pDC)
{
	CBrush		backBrush(BACK_COLOR);
	CBrush*		pOldBrush				=		pDC->SelectObject(&backBrush);
	CRect		rect;

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

void CMainWin::OnTimer(UINT){
	if (timerflag == true){
		if (timer == 7){
			SetTimer(1, 500, NULL);
			sound = MB_ICONASTERISK;
		}		
		MessageBeep(sound);
		timer++;
		if (timer == 14){
			MessageBeep(MB_ICONERROR);
			StopGame();
		}
	}
	
}

BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWin;
	m_pMainWnd->SetTimer(1, 1000, 0);
	m_pMainWnd->ShowWindow(m_nCmdShow);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CApp App;