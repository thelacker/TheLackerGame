class CMainWin : public CFrameWnd
{
public:
	CMainWin();
	CButton NewGame, Exit, High;
	afx_msg void ClickNewGame();
	afx_msg void ClickExit();
	afx_msg void ClickHighScores();
	afx_msg void OnTimer(UINT ID);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};