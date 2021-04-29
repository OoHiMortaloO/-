#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

#define rep(i,n)	for(int i=0; i<n; i++)

char board[19][19];
int backend[19][19];
int x = 0, y = 0;

void init_board_backend(){
	rep(i, 19){
		rep(j, 19){
			backend[i][j] = 0;
		}
	}
	for(int i = 0; i < 19; i++){
		for(int j = 0; j < 19; j++){
			board[i][j] = '.';
		}
	}
}

void show_board(){
	for(int i = 0; i < 19; i++){
		for(int j = 0; j < 19; j++){
			if(x == j && y == i) cout << '$' << ' ';
			else cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

void move_back(){
	if(y > 19) y = 0;
	if(y < 0) y = 19;
	if(x > 19) x = 0;
	if(x < 0) x = 19;
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
		if(board[y][x+i] == player){
			count++;
		}else break;
	}
	for(int i=1; x-i >= 0; ++i){
		if(board[y][x-i] == player){
			count++;
		}else break;
	}
	if(count >= 6) return true;
	else return false;
}

bool y_win(char player){
	int count = 1;
	for(int i=1;; ++i){
		if(board[y+i][x] == player){
			count++;
		}else break;
	}
	for(int i=1; y-i >= 0; ++i){
		if(board[y-i][x] == player){
			count++;
		}else break;
	}
	if(count >= 6) return true;
	else return false;
}

bool r_win(char player){
	int count = 1;
	for(int i=1;; ++i){
		if(board[y+i][x+i] == player){
			count++;
		}else break;
	}
	for(int i=1; (y-i >= 0 && x-i >= 0); ++i){
		if(board[y-i][x-i] == player){
			count++;
		}else break;
	}
	if(count >= 6) return true;
	else return false;
}

bool l_win(char player){
	int count = 1;
	for(int i=1; y-i >= 0; ++i){
		if(board[y-i][x+i] == player){
			count++;
		}else break;
	}
	for(int i=1; x-i >= 0; ++i){
		if(board[y+i][x-i] == player){
			count++;
		}else break;
	}
	if(count >= 6) return true;
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

void user_input(int c){
	if(c==119 || c==87) y--; //W
    if(c==97 || c==65) x--; //A
    if(c==115 || c==83) y++; //S
    if(c==100 || c==68) x++; //D
}

bool map_full(){
	int count = 0;
	for(int i=0; i<19; i++){
		for(int j=0; j<19; j++){
			if(backend[j][i] == 1){
				count++;
			}
		}
	}
	if(count == 361) //19 * 19
		return true;
	else return false;
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);

	init_board_backend();
	show_board();
	char player = 'O';
	// black = O, white = X
	while(true){
		if(sb_wins(player) == true){
			cout << player << " Victory !!!";
			break;
		}else{
			int c;
			c = getch();
			user_input(c);
			move_back();
			if(c==114 || c==82){ //R
				if(check_chess() == false){
					cout<<"You can't put the chess here!\n";
				}else{
					board[y][x] = player; //put chess here
					backend[y][x] = 1; //marking array
					player = 'X'; //change player
				}
			}
			new_screen(0, 0);
			show_board();
		}
	}
	new_screen(0, 0);
	
return 0;
}
