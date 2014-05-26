class CMainWin : public CFrameWnd
{
public:
	CMainWin();

	CButton			NewGame,
					Exit,
					High,
					GameExit;
	CFont			font;

	bool			timerflag;
	unsigned int	timer;
	int				sound;
	int				pos;
	char			str[10];
	int				first;
	int				second;
	int				third;
	int				znak;
	int				znak2;
	int				otvet;
	int				level;
	int				otvet2 = 0;
	int				o = 0;

	void			Initiate();
	void			Destruction();
	afx_msg void ClickNewGame();
	afx_msg void ClickExit();
	afx_msg void ClickHighScores();
	afx_msg void ClickGameExit();
	afx_msg void OnTimer(UINT ID);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg void StartGame();
	afx_msg void StopGame();
	afx_msg void Game();
	afx_msg void OnChar(UINT Ch, UINT Count, UINT Flags);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};
