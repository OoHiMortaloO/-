#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

#define rep(i,n)	for(int i=0; i<n; i++)

string map[19][19];

bool x_win(int x, int y, char player){
	int count = 1;
	for(int i=1;; ++i){
		if(board[x+1][y]==player){
			count++;
		}else break;
	}
	for(int i=1;; ++i){
		if(board[x-1][y]==player){
			count++;
		}else break;
	}
	if(count>=5) return true;
	else return false;
}

bool y_win(int x, int y, char player){
	int count = 1;
	for(int i=1;; ++i){
		if(board[x][y+1]==player){
			count++;
		}else break;
	}
	for(int i=1;; ++i){
		if(board[x][y-1]==player){
			count++;
		}else break;
	}
	if(count>=5) return true;
	else return false;
}

bool r_win(int x, int y, char player){
	int count = 1;
	for(int i=1;; ++i){
		if(board[x+1][y+1]==player){
			count++;
		}else break;
	}
	for(int i=1;; ++i){
		if(board[x-1][y-1]==player){
			count++;
		}else break;
	}
	if(count>=5) return true;
	else return false;
}

bool l_win(int x, int y, char player){
	int count = 1;
	for(int i=1;; ++i){
		if([x+1][y-1]==player){
			count++;
		}else break;
	}
	for(int i=1;; ++i){
		if([x-1][y+1]==player){
			count++;
		}else break;
	}
	if(count>=5) return true;
	else return false;
}

bool who_wins(int x, int y, char player){
	if(l_win(int x, int y, char player) || r_win(int x, int y, char player) || x_win(int x, int y, char player) || y_win(int x, int y, char player)){
		return true;
	}else return false;
}

bool check_chess(){

}

void user_input(){

}

void new_screen(int xpos, int ypos) {
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = xpos, scrn.Y = ypos;
    SetConsoleCursorPosition(hOuput, scrn);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);
    CursorInfo.bVisible = false;
    SetConsoleCursorInfo(handle, &CursorInfo);
}

void chess_board(){
	for(int i = 0; i < 19; i++){
		for(int j = 0; j < 19; j++){
			map[i][j] = "＋";
		}
	}
	for(int i = 0; i < 19; i++){
		for(int j = 0; j < 19; j++){
			cout << map[i][j];
		}
		cout << endl;
	}

	int x, y;
	cin >> x >> y;
	map[x][y] = "X";

	for(int i = 0; i < 19; i++){
		for(int j = 0; j < 19; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
}

int main(){

	int x=0, y=0;
	char white, black;
	while(true){
		if(who_wins()==false){

		}else break;
	}

return 0;
}
