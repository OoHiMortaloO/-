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

bool check_chess(int x, int y){
	if(x==1 || y==1){
		return false;
	}else return true;
}

void black_input(int c, int x, int y){
	if(c==119 || c==87) y+=1; //W
    if(c==97 || c==65) x-=1; //A
    if(c==115 || c==83) y-=1; //S
    if(c==100 || c==68) x+=1; //D
    if(c==114 || c==82){
		board[x][y] = 'X'; //put chess here //R
		x = 1; //array marking
		y = 1;
	}
	if(check_chess(x, y) == false){
		cout<<"You can't put the chess here!\n";
	}
}

void white_input(int c, int x, int y){
	if(c==119 || c==87) y+=1; //W
    if(c==97 || c==65) x-=1; //A
    if(c==115 || c==83) y-=1; //S
    if(c==100 || c==68) x+=1; //D
    if(c==114 || c==82){
		board[x][y] = 'O'; //put chess here //R
		x = 1; //array marking
		y = 1;
	}
	if(check_chess(x, y) == false){
		cout<<"You can't put the chess here!\n";
	}
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
ios::sync_with_stdio(false);
cin.tie(0);

	new_screen();
	int bx = 0, by = 0, wx = 0, wy = 0, c;
	char white, black;
	chess_board();
	while(true){
		c = getch();
		black_input(c, bx, by);
		white_input(c, wx, wy);
		chess_board_print();
	}

return 0;
}
