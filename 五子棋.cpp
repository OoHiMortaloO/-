#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

#define rep(i,n)	for(int i=0; i<n; i++)

char board[19][19];
int backend[19][19];
int x, y;

void init_board_backend(){
	rep(i, 19){
		rep(j, 19){
			backend[i][j] = 0;
		}
	}
	for(int i = 0; i < 19; i++){
		for(int j = 0; j < 19; j++){
			board[i][j] = '¡Ï';
		}
	}
}

void show_board(){
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

bool x_win(char player){
	int count = 1;
	for(int i=1;; ++i){
		if(board[y][x+1] == player){
			count++;
		}else break;
	}
	for(int i=1;; ++i){
		if(board[y][x-1] == player){
			count++;
		}else break;
	}
	if(count >= 5) return true;
	else return false;
}

bool y_win(char player){
	int count = 1;
	for(int i=1;; ++i){
		if(board[y+1][x] == player){
			count++;
		}else break;
	}
	for(int i=1;; ++i){
		if(board[y-1][x] == player){
			count++;
		}else break;
	}
	if(count >= 5) return true;
	else return false;
}

bool r_win(char player){
	int count = 1;
	for(int i=1;; ++i){
		if(board[y+1][x+1] == player){
			count++;
		}else break;
	}
	for(int i=1;; ++i){
		if(board[y-1][x-1] == player){
			count++;
		}else break;
	}
	if(count >= 5) return true;
	else return false;
}

bool l_win(char player){
	int count = 1;
	for(int i=1;; ++i){
		if(board[y-1][x+1] == player){
			count++;
		}else break;
	}
	for(int i=1;; ++i){
		if(board[y+1][x-1] == player){
			count++;
		}else break;
	}
	if(count >= 5) return true;
	else return false;
}

bool sb_wins(char player){
	if(l_win(player) || r_win(player) || x_win(player) || y_win(player)){
		return true;
	}else return false;
}

bool check_chess(){
	if(backend[y][x] == 1){
		return false;
	}else return true;
}

void black_input(int c){
	if(c==119 || c==87) y--; //W
    if(c==97 || c==65) x--; //A
    if(c==115 || c==83) y++; //S
    if(c==100 || c==68) x++; //D
    if(c==114 || c==82){
		board[y][x] = 'X'; //put chess here //R
		backend[y][x] = 1; //marking array
	}
	if(check_chess() == false){
		cout<<"You can't put the chess here!\n";
	}
}

void white_input(int c){
	//out of map check
	if(c==119 || c==87) y+=1; //W
    if(c==97 || c==65) x-=1; //A
    if(c==115 || c==83) y-=1; //S
    if(c==100 || c==68) x+=1; //D
    if(c==114 || c==82){
		board[y][x] = 'O'; //put chess here //R
		backend[y][x] = 1; //marking array
	}
	if(check_chess() == false){
		cout<<"You can't put the chess here!\n";
	}
}

bool map_full(){
	for(int i=0; i<19; i++){
		for(int j=0; j<19; j++){
			if(board[i][j] == '¡Ï'){
				return true;
			}else return false;
		}
	}
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);

	new_screen();
	init_board_backend();
	char black = 'X', white = 'O';
	while(true){
		c = getch();
		black_input(c);
		show_board();
		white_input(c);
		chess_board_print();
	}

return 0;
}
