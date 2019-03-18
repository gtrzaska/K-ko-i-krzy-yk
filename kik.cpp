// kik.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <conio.h>
#include <Windows.h>

using namespace std;

string plansza[3][3];
string gracz1, gracz2;
int wynik, remis;
int cpy, cpx;

void rys_plansze();
void sprawdzenie();
void od_nowa();
void ruch_komp();
void pozycja_kursora();

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbiInfo;

int main()
{
	srand(time(NULL));
	wynik = -1, remis = 0;
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		plansza[i][j] = " ";

	string tura = "1", p="", pozycja="";

	cout << " Kto zaczyna? (1-Gracz 2- Kpmputer)" << endl;
	do{
		cin >> tura;
		if (tura != "1" && tura != "2")
			cout << "zly numer" << endl;
	} while (tura != "1" && tura != "2");
	cout << " Znak dla gracza :(1-X 2-O) " << endl;
	do{
	
		cin >> p;
		if (p != "1" && p != "2")
			cout << "zly numer" << endl;
	} while (p != "1" && p != "2");
	if (p == "1"){
		gracz1 = "X";
		gracz2 = "O";
	}
	else if (p == "2"){
		gracz1 = "O";
		gracz2 = "X";
	}
			
	do{
		
		rys_plansze();
		
			if (tura == "1"){
			int x;
			cpy = 7;cpx = 11;

			pozycja_kursora();
			int pom2 = 0;

			do{
			do{
				x = _getch();

				if (x == 72) {
					if (cpy - 3 >= 4) {
						cpy -= 3;
						pozycja_kursora();
					}
				}
				if (x == 80) {
					if (cpy + 3 < 11) {
						cpy += 3;
						pozycja_kursora();
					}
				}
				if (x == 75) {
					if (cpx - 6 >= 0) {
						cpx -= 6;
						pozycja_kursora();
					}
				}
				if (x == 77) {
					if (cpx + 6 <= 17) {
						cpx += 6;
						pozycja_kursora();
					}
				}
			} while (x != 13);
			
				if (cpx == 5 && cpy == 4 && plansza[0][0] == " " ){
						 pom2 =1;
						plansza[0][0] = gracz1;
				}
				else if (cpx == 11 && cpy == 4 && plansza[0][1] == " "){
						pom2 = 1;
						plansza[0][1] = gracz1;

				}
				else if (cpx == 17 && cpy == 4 && plansza[0][2] == " "){
						pom2 = 1;
						plansza[0][2] = gracz1;

				}
				else if (cpx == 5 && cpy == 7 && plansza[1][0] == " "){
						pom2 = 1;
						plansza[1][0] = gracz1;

				}
				else if (cpx == 11 && cpy == 7 && plansza[1][1] == " "){
						pom2 = 1;
						plansza[1][1] = gracz1;

				}
				else if (cpx == 17 && cpy == 7 && plansza[1][2] == " "){
						pom2 = 1;
						
						plansza[1][2] = gracz1;

				}
				else if (cpx == 5 && cpy == 10 && plansza[2][0] == " "){
						pom2 = 1;
						plansza[2][0] = gracz1;

				}
				else if (cpx == 11 && cpy == 10 && plansza[2][1] == " "){
					pom2 = 1;
						plansza[2][1] = gracz1;

				}
				else if (cpx == 17 && cpy == 10 && plansza[2][2] == " "){
						pom2 = 1;
						plansza[2][2] = gracz1;

				}
			} while (pom2==0);
		}
			else if (tura=="2"){
				ruch_komp();
			}
			
				sprawdzenie();
				if (tura == "1")
					tura = "2";
				else if (tura == "2")
					tura = "1";

		
	} while (wynik == -1);

	cin.sync();
	cin.get();
	return 0;
}
void rys_plansze(){
	system("cls");
	cout << endl;
	cout << "                  " << endl;
	cout << "   _____ _____ _____" << endl;
	cout << "  |     |     |     |" << endl;
	cout << "  |  " << plansza[0][0] << "  |  " << plansza[0][1] << "  |  " << plansza[0][2] << "  |  " << endl;
	cout << "  |_____|_____|_____|" << endl;
	cout << "  |     |     |     |" << endl;
	cout << "  |  " << plansza[1][0] << "  |  " << plansza[1][1] << "  |  " << plansza[1][2] << "  |  " << endl;
	cout << "  |_____|_____|_____|" << endl;
	cout << "  |     |     |     |" << endl;
	cout << "  |  " << plansza[2][0] << "  |  " << plansza[2][1] << "  |  " << plansza[2][2] << "  |  " << endl;
	cout << "  |_____|_____|_____|" << endl << endl;
}

void sprawdzenie(){
	for (int i = 0; i < 3; i++){
		if (plansza[i][1] == plansza[i][0] && plansza[i][1] == plansza[i][2] && plansza[i][1] !=" " ){
			if (plansza[i][0] == gracz1){
				rys_plansze(); wynik = 1; cout << "Wygral Gracz " << endl;
				od_nowa();
			}
			else if (plansza[i][0] == gracz2){
				rys_plansze(); wynik = 1; cout << "Wygral komputer" << endl;
				od_nowa();
			}
		}
		if (plansza[0][i] == plansza[1][i] && plansza[0][i] == plansza[2][i] && plansza[0][i] != " "){
			if (plansza[0][i] == gracz1){
				rys_plansze(); wynik = 1; cout << "Wygral Gracz" << endl;
				od_nowa();
			}
			else if (plansza[0][i] == gracz2){
				rys_plansze(); wynik = 1; cout << "Wygral komputer" << endl;
				od_nowa();
			}
		}
	}

	

	 if (plansza[0][0] == plansza[1][1] && plansza[1][1] == plansza[2][2]){
		if (plansza[1][1] == gracz1){
			rys_plansze(); wynik = 1; cout << "Wygral Gracz" << endl;
			od_nowa();
		}
		else if (plansza[1][1] == gracz2){
			rys_plansze(); wynik = 1; cout << "Wygral komputer" << endl;
			od_nowa();
		}
	}
	else if (plansza[0][2] == plansza[1][1] && plansza[1][1] == plansza[2][0]){
		if (plansza[1][1] == gracz1){
			rys_plansze(); wynik = 1; cout << "Wygral Gracz" << endl;
			od_nowa();
		}
		else if (plansza[1][1] == gracz2){
			rys_plansze(); wynik = 1; cout << "Wygral komputer" << endl;
			od_nowa();
		}
	}
		remis++;
		if (remis == 9 && wynik!=1){
			rys_plansze(); wynik = 0; cout << " REMIS!" << endl;
			od_nowa();
	}
}
void od_nowa(){
	char res;
	wynik = -1, remis = 0;
	cout << "Czy chcesz grac jeszcze raz? (tak=t nie =n)" << endl;
	cin >> res;
	if (res == 'T' || res == 't') {
		system("CLS");
		main();
	}
	else
		exit(0);
}

void ruch_komp() {

	for (int i = 0; i<3; i++) {
		if (plansza[i][0] == gracz2 && plansza[i][1] == gracz2 && plansza[i][2] == " ") {
			plansza[i][2] = gracz2;
			return;
		}
		if (plansza[i][0] == gracz2 && plansza[i][2] == gracz2 && plansza[i][1] == " ") {
			plansza[i][1] = gracz2;
			return;
		}
		if (plansza[i][2] == gracz2 && plansza[i][1] == gracz2 && plansza[i][0] == " ") {
			plansza[i][0] = gracz2;
			return;
		}
		if (plansza[0][i] == gracz2 && plansza[1][i] == gracz2 && plansza[2][i] == " ") {
			plansza[2][i] = gracz2;
			return;
		}
		if (plansza[0][i] == gracz2 && plansza[2][i] == gracz2 && plansza[1][i] == " ") {
			plansza[1][i] = gracz2;
			return;
		}
		if (plansza[2][i] == gracz2 && plansza[1][i] == gracz2 && plansza[0][i] == " ") {
			plansza[0][i] = gracz2;
			return;
		}
	}
	if (plansza[0][0] == gracz2 && plansza[1][1] == gracz2 && plansza[2][2] == " ") {
		plansza[2][2] = gracz2;
		return;
	}
	if (plansza[0][0] == gracz2 && plansza[2][2] == gracz2 && plansza[1][1] == " ") {
		plansza[1][1] = gracz2;
		return;
	}
	if (plansza[2][2] == gracz2 && plansza[1][1] == gracz2 && plansza[0][0] == " ") {
		plansza[0][0] = gracz2;
		return;
	}
	if (plansza[0][2] == gracz2 && plansza[1][1] == gracz2 && plansza[2][0] == " ") {
		plansza[2][0] = gracz2;
		return;
	}
	if (plansza[0][2] == gracz2 && plansza[2][0] == gracz2 && plansza[1][1] == " ") {
		plansza[1][1] = gracz2;
		return;
	}
	if (plansza[2][0] == gracz2 && plansza[1][1] == gracz2 && plansza[0][2] == " ") {
		plansza[0][2] = gracz2;
		return;
	}



	for (int i = 0; i<3; i++) {
		if (plansza[i][0] == gracz1 && plansza[i][1] == gracz1 && plansza[i][2] == " ") {
			plansza[i][2] = gracz2;
			return;
		}
		if (plansza[i][0] == gracz1 && plansza[i][2] == gracz1 && plansza[i][1] == " ") {
			plansza[i][1] = gracz2;
			return;
		}
		if (plansza[i][2] == gracz1 && plansza[i][1] == gracz1 && plansza[i][0] == " ") {
			plansza[i][0] = gracz2;
			return;
		}
		if (plansza[0][i] == gracz1 && plansza[1][i] == gracz1 && plansza[2][i] == " ") {
			plansza[2][i] = gracz2;
			return;
		}
		if (plansza[0][i] == gracz1 && plansza[2][i] == gracz1 && plansza[1][i] == " ") {
			plansza[1][i] = gracz2;
			return;
		}
		if (plansza[2][i] == gracz1 && plansza[1][i] == gracz1 && plansza[0][i] == " ") {
			plansza[0][i] = gracz2;
			return;
		}
	}
	if(plansza[0][0] == gracz1 && plansza[1][1] == gracz1 && plansza[2][2] == " ") {
		plansza[2][2] = gracz2;
		return;
	}
	 if(plansza[0][0] == gracz1 && plansza[2][2] == gracz1 && plansza[1][1] == " ") {
		plansza[1][1] = gracz2;
		return;
	}
	 if(plansza[2][2] == gracz1 && plansza[1][1] == gracz1 && plansza[0][0] == " ") {
		plansza[0][0] = gracz2;
		return;
	}
	 if(plansza[0][2] == gracz1 && plansza[1][1] == gracz1 && plansza[2][0] == " ") {
		plansza[2][0] = gracz2;
		return;
	}
	 if(plansza[0][2] == gracz1 && plansza[2][0] == gracz1 && plansza[1][1] == " ") {
		plansza[1][1] = gracz2;
		return;
	}
	 if(plansza[2][0] == gracz1 && plansza[1][1] == gracz1 && plansza[0][2] == " ") {
		plansza[0][2] = gracz2;
		return;
	}
	 if(plansza[1][1] == " "){
		plansza[1][1] = gracz2;
		return;
	}
	 if (plansza[0][0] == gracz1 && plansza[2][2] == gracz1 && plansza[1][1]==gracz2){
		 plansza[0][1] = gracz2;
		 return;
	 
	}
	 if (plansza[2][0] == gracz1 && plansza[0][2] == gracz1 && plansza[1][1] == gracz2){
		 plansza[1][0] = gracz2;
		 return;
	 }
	 if (plansza[1][1] == gracz1 && plansza[0][0] == gracz2 && plansza[2][2] == gracz1 && plansza[0][2] == " "){
		 plansza[0][2] = gracz2;
		 return;
	 }
	 if (plansza[1][1] == gracz1 && plansza[0][0] == " "){
		 plansza[0][0] = gracz2;
		 return;
	 }
	
	bool los = false;
		int a, b;
		while (!los) {
		a = rand()%3;
		b = rand()%3;
		if (plansza[a][b] == " ") {
			plansza[a][b] = gracz2;
			los = true;
		}
	}
}

void pozycja_kursora() {
	csbiInfo.dwCursorPosition.Y = cpy;
	csbiInfo.dwCursorPosition.X = cpx;
	SetConsoleCursorPosition(hStdout, csbiInfo.dwCursorPosition);
}