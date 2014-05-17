void CMainWin::ClickNewGame(){
	ModifyStyle(WS_BORDER, WS_POPUP, NULL);
	ShowWindow(SW_SHOWMAXIMIZED);
	OnPaint();
	CBrush myBrush(BACK_COLOR);
	CPaintDC dc(this);
	this->InvalidateRect(0, FALSE);
	StartGame();
}

void CMainWin::ClickExit(){
	ASSERT(AfxGetApp()->m_pMainWnd != NULL);
	AfxGetApp()->m_pMainWnd->SendMessage(WM_CLOSE);
}

void CMainWin::ClickHighScores(){
	ASSERT(AfxGetApp()->m_pMainWnd != NULL);
	AfxGetApp()->m_pMainWnd->SendMessage(WM_CLOSE);
}

void CMainWin::ClickGameExit(){
	ASSERT(AfxGetApp()->m_pMainWnd != NULL);
	AfxGetApp()->m_pMainWnd->SendMessage(WM_CLOSE);
}