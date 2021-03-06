#include <windows.h>
#include <random>
#pragma warning(disable : 4996)

void CMainWin::StartGame(){
	Sleep(500);
	pos = 3;
	timerflag = true;
	Game();
	if (level == 1){
		str[0] = first + '0';
		switch (znak){
		case 1: str[1] = '+'; otvet = first + second; otvet > 0 ? otvet = otvet : otvet = -otvet; break;
		case 2:	str[1] = '-'; otvet = first - second; otvet > 0 ? otvet = otvet : otvet = -otvet; break;
		case 3: str[1] = '*'; otvet = first * second; otvet > 0 ? otvet = otvet : otvet = -otvet; break;
		}
		str[2] = second % 10 + '0';
		str[3] = NULL;
		str[4] = NULL;
		str[5] = NULL;
	}
	else if (level == 2){
		pos = 4;
		str[0] = first + '0';
		switch (znak){
		case 1: str[1] = '+'; otvet = first + second; break;
		case 2:	str[1] = '-'; otvet = first - second; break;
		case 3: str[1] = '*'; otvet = first * second; break;
		}
		str[2] = second + '0';
		switch (znak2){
		case 1: str[3] = '+'; otvet += third; otvet > 0 ? otvet = otvet : otvet = -otvet; break;
		case 2:	str[3] = '-'; otvet -= third; otvet > 0 ? otvet = otvet : otvet = -otvet; break;
		}
		str[4] = third + '0';
		str[5] = NULL;
	}
	else {
		f.open("C:\\HighScores.txt", std::ios::ate);
		f << Scores;
		timerflag = false;
		str[0] = 'E';
		str[1] = 'N';
		str[2] = 'D';
		str[3] = NULL;
		str[4] = NULL;
		str[5] = NULL;
		OnPaint();
		Sleep(500);
		
	}
	OnPaint();
};

void CMainWin::StopGame(){
	Scores += timer + otvet;
	timerflag = false;
	str[0] = 'D';
	str[1] = 'O';
	str[2] = 'N';
	str[3] = 'E';
	str[4] = '!';
	pos = 5;
	OnPaint();
	level++;
	Initiate();
	Sleep(300);
	CClientDC dc(this);
	CFont* def_font = dc.SelectObject(&font);
	dc.SetBkColor(BACK_COLOR);
	dc.SetTextColor(BACK_COLOR);
	dc.TextOut(X / pos, Y / 3, str);
	StartGame();
}

void CMainWin::Game(){
	if (level == 1){
		srand(time(NULL));
		first = rand() % 10;
		second = rand() % 10;
		znak = rand() % 3 + 1;
	}
	if (level == 2){
		srand(time(NULL));
		first = rand() % 10;
		second = rand() % 10;
		third = rand() % 10;
		znak = rand() % 3 + 1;
		znak2 = rand() % 2 + 1;
	}
	if (level == 3){
		srand(time(NULL));
		first = rand();
		second = rand() % 10;
	}
}