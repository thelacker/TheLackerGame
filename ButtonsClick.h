void CMainWin::ClickNewGame(){
	ModifyStyle(WS_BORDER, WS_POPUP, NULL);
	ShowWindow(SW_SHOWMAXIMIZED);
	Destruction();
	OnPaint();
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

void CMainWin::Initiate(){
	str[0] = 'R';
	str[1] = 'E';
	str[2] = 'A';
	str[3] = 'D';
	str[4] = 'Y';
	str[5] = '?';
	SetTimer(1, 1000, NULL);
	timerflag = false;
	timer = 0;
	sound = MB_ICONWARNING;
	pos = 7;
}

void CMainWin::Destruction(){
	NewGame.DestroyWindow();
	Exit.DestroyWindow();
	High.DestroyWindow();
}