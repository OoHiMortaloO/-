#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

#define rep(i,n)	for(int i=0; i<n; i++)

void chess_board(){
	
return;
}

bool x_win(int x, int y, char board[19][19], char player){
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

bool y_win(int x, int y, char board[19][19], char player){
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

bool r_win(int x, int y, char board[19][19], char player){
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

bool l_win(int x, int y, char board[19][19], char player){
	int count = 1;
	for(int i=1;; ++i){
		if(board[x+1][y-1]==player){
			count++;
		}else break;
	}
	for(int i=1;; ++i){
		if(board[x-1][y+1]==player){
			count++;
		}else break;
	}
	if(count>=5) return true;
	else return false;
}

bool who_wins(int x, int y, char board[19][19], char player){
	if(l_win(int x, int y, char board[19][19], char player) || r_win(int x, int y, char board[19][19], char player) || x_win(int x, int y, char board[19][19], char player) || y_win(int x, int y, char board[19][19], char player)){
		return true;
	}else return false;
}

bool check_chess(){
	
}

void user_input(){

}

int main(){

	int x=0, y=0, map[19][19];
	
	
	while(true){
		if(who_wins()==false){
			
		}else break;
	}

return 0;
}

