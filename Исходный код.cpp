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
	level = 1;
	Create(NULL,	_T("TheLacker Game"),	WS_BORDER,	rect);
	NewGame.Create(	_T("New Game"),			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,				RECT_NEWGAME,		this,	IDC_ngb);
	Exit.Create(	_T("Exit"),				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,				RECT_EXIT,			this,	IDC_exb);
	High.Create(	_T("High Scores"),		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,				RECT_HSB,			this,	IDC_hsb);
	GameExit.Create(_T("||"),				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT,	RECT_GEB,			this,	IDC_geb);
	Initiate();
	CMainWin::SetFont(&font, TRUE);
	VERIFY(font.CreateFont(400, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, _T("Arial")));
}

void CMainWin::OnPaint()
{
	CClientDC dc(this);
	CFont* def_font = dc.SelectObject(&font);
	dc.SetBkColor(BACK_COLOR);
	dc.TextOut(X / pos, Y / 3, str);
	dc.SelectObject(def_font);
}



BOOL CMainWin::OnEraseBkgnd(CDC* pDC)
{
	CBrush		backBrush(BACK_COLOR);
	CBrush*		pOldBrush				=		pDC->SelectObject(&backBrush);
	CRect		rect;

	pDC->GetClipBox(&rect);
	pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOldBrush);
	OnPaint();
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

void CMainWin::OnChar(UINT Ch, UINT Count, UINT Flags)
{
	if (Ch == 13) {
		otvet2 = 0;
		o == 0;
	}
	if ((Ch-48) == otvet || otvet2 == otvet){
		StopGame();
	}
	else {
		if (o == 0){
			otvet2 = 10 * (Ch - 48);
		}
		else{
			otvet2 += (Ch - 48);
		}
		o++;
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