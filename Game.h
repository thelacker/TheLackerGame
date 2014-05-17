#include <windows.h>
#include <random>
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#pragma warning(disable : 4996)

void CMainWin::StartGame(){
	timerflag = true;
	Game();
	str[0] = first % 10 + '0';
	switch (znak){
	case 1: str[1] = '+'; otvet = first + second; break;
	case 2:	str[1] = '-'; otvet = first - second; break;
	case 3: str[1] = '*'; otvet = first * second; break;
	}
	str[2] = second % 10 + '0';
};

void CMainWin::StopGame(){
	timerflag = false;
}

void CMainWin::Game(){
	srand(time(NULL));
	first = rand();
	second = rand();
	znak = rand() % 3 + 1;
}