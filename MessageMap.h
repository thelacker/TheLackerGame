BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)
	ON_WM_ERASEBKGND()
	ON_WM_CHAR()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_exb, CMainWin::ClickExit)
	ON_BN_CLICKED(IDC_ngb, CMainWin::ClickNewGame)
	ON_BN_CLICKED(IDC_hsb, CMainWin::ClickHighScores)
	ON_BN_CLICKED(IDC_geb, CMainWin::ClickGameExit)
END_MESSAGE_MAP()