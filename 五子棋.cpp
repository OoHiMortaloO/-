#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

#define rep(i,n)	for(int i=0; i<n; i++)

string board[19][19];

void chess_board(){
	for(int i = 0; i < 19; i++){
		for(int j = 0; j < 19; j++){
			board[i][j] = '+';
		}
	}
	for(int i = 0; i < 19; i++){
		for(int j = 0; j < 19; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
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

void user_input(int c, int x, int y){
	if(c==119 || c==87) y+=1; //W
    if(c==97 || c==65) x-=1; //A
    if(c==115 || c==83) y-=1; //S
    if(c==100 || c==68) x+=1; //D
    if(c==114 || c==82) board[x][y] = 'X'; //put chess here //R
}

void chess_board_print(){
	for(int i = 0; i < 19; i++){
		for(int j = 0; j < 19; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
}

int main(){

	int x = 0, y = 0, c;
	char white, black;
	chess_board();
	while(true){
		if(who_wins()==false){
			c = getch();
			user_input(c, x, y);
			chess_board_print();
		}else break;
	}

return 0;
}
