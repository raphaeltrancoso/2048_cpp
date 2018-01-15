#include <iostream>
#include <curses.h>
#include <stdlib.h> 
#include <ctime>
#include <string>
#include "game2048.hpp"
using namespace std;

game2048::game2048(int s,int p){
	size = s;
	puissance = p;
	tab = new int*[size];
	for(int i=0;i<size;i++){
		tab[i] = new int[size];
	}

	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			tab[i][j] = 0;
		}
	}
}
void game2048::drawGame(char* message){
	move(0,0);
	printw("*_______________________________*\n");
	printw("|       |       |       |       |\n");
	printw("|%4d   |%4d   |%4d   |%4d   |\n",tab[0][0],tab[0][1],tab[0][2],tab[0][3]);
	printw("|_______|_______|_______|_______|\n");
	printw("|       |       |       |       |\n");
	printw("|%4d   |%4d   |%4d   |%4d   |\n",tab[1][0],tab[1][1],tab[1][2],tab[1][3]);
	printw("|_______|_______|_______|_______|\n");
	printw("|       |       |       |       |\n");
	printw("|%4d   |%4d   |%4d   |%4d   |\n",tab[2][0],tab[2][1],tab[2][2],tab[2][3]);
	printw("|_______|_______|_______|_______|\n");
	printw("|       |       |       |       |\n");
	printw("|%4d   |%4d   |%4d   |%4d   |\n",tab[3][0],tab[3][1],tab[3][2],tab[3][3]);
	printw("|_______|_______|_______|_______|\n");
	printw("*********************************\n");
	printw( "      %s      ",message);
}

void game2048::addRandomNumber(){
	int** tabZero= new int*[size*size];
	int leng = 0,x,y,r,n;
	for(int i=0;i<size*size;i++){
		tabZero[i] = new int[2];
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(tab[i][j]==0){
				tabZero[leng][0] = i;
				tabZero[leng][1] = j;
				leng++;
			}
		}
	}
	if(leng>0){
		r = rand()%leng;
		x = tabZero[r][0];
		y = tabZero[r][1];
		srand(time(0));
		n = 2*((rand()%2)+1);
		tab[x][y] = n;
	}
}
void game2048::play(){
	char message[50]="USE ARROW KEY TO PLAY";
	char messageWin[50]="BRAVO!YOU WIN THE GAME.";
	char messageRobot[50]="ROBOT WIN THE GAME.";
	char messageLose[50]="YOU LOSE THE GAME.";
	bool check = true, checkRobot=false;
	int seed =0;
	addRandomNumber();
	while(check){
		initscr();
		start_color();

		init_pair(1, COLOR_BLACK, COLOR_WHITE);
		attron(COLOR_PAIR(1));
		if(gameEnd()==1 && checkRobot){
			drawGame(messageRobot);
			check = false;
		}
		/* Player wins the game */
		else if(gameEnd()==1){
			drawGame(messageWin);
			check = false;
		}
		else if(gameEnd()==2){
			drawGame(messageLose);
			check = false;
		}
		else {
			drawGame(message);
		}
		refresh();
		keypad(stdscr, TRUE);
		switch(getch()){
			case KEY_UP:
				moveUp();
				break;
			case KEY_RIGHT:
				moveRight();
				break;
			case KEY_DOWN:
				moveDown();
				break;
			case KEY_LEFT:
				moveLeft();
				break;
			case 'r':
				checkRobot=true;
				srand(time(0));
				seed = rand()%4 +1;
				if(seed == 1) moveUp();
				if(seed == 2) moveDown();
				if(seed == 3) moveRight();
				if(seed == 4) moveLeft();
				break;
		}
		endwin();
	}

}
void game2048::moveUp(){
	int count = 0;
	bool add= false;
	for(int j=0;j<size;j++){
		count = 0;
		for(int i=size-2;i>=0;i--){
			if(tab[i][j] == 0 && tab[i+1][j] !=0){
				add = true;
				for(int k=i;k<size-1;k++){
					tab[k][j] = tab[k+1][j];
				}
				tab[size-count-1][j] = 0;
				count++;
			}
		}
	}
	for(int j=0;j<size;j++){
		for(int i=0;i<size-1;i++){
			if(tab[i][j]==tab[i+1][j] && tab[i][j]!=0){
				add = true;
				tab[i][j] = 2*tab[i][j];
				for(int k=i+1;k<size-1;k++){
					tab[k][j] = tab[k+1][j];
				}
				tab[size-1][j] = 0;
			}
		}
	}

	if(add) addRandomNumber();

}
void game2048::moveDown(){
	bool add= false;
	int count = 0;
	for(int j=0;j<size;j++){
		count = 0;
		for(int i=1;i<size;i++){
			if(tab[i][j] == 0 && tab[i-1][j] !=0){
				add = true;
				for(int k=i;k>0;k--){
					tab[k][j] = tab[k-1][j];
				}
				tab[count][j] = 0;
				count++;
			}
		}
	}
	for(int j=0;j<size;j++){
		for(int i=size-1;i>0;i--){
			if(tab[i][j]==tab[i-1][j] && tab[i][j]!=0){
				add = true;
				tab[i][j] = 2*tab[i][j];
				for(int k=i-1;k>0;k--){
					tab[k][j] = tab[k-1][j];
				}
				tab[0][j] = 0;
			}
		}
	}

	if(add) addRandomNumber();
}
void game2048::moveLeft(){
	bool add= false;
	int count = 0;
	for(int i=0;i<size;i++){
		count = 0;
		for(int j=size-2;j>=0;j--){
			if(tab[i][j] == 0 && tab[i][j+1] !=0){
				add = true;
				for(int k=j;k<size-1;k++){
					tab[i][k] = tab[i][k+1];
				}
				tab[i][size-count-1] = 0;
				count++;
			}
		}
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size-1;j++){
			if(tab[i][j]==tab[i][j+1] && tab[i][j]!=0){
				add = true;
				tab[i][j] = 2* (tab[i][j]);
				for(int k=j+1;k<size-1;k++){
					tab[i][k] = tab[i][k+1];
				}
				tab[i][size-1] = 0; 
			}
		}
	}

	if(add) addRandomNumber();
}
void game2048::moveRight(){
	bool add= false;
	int count = 0;
	for(int i=0;i<size;i++){
		count = 0;
		for(int j=1;j<size;j++){
			if(tab[i][j] == 0 && tab[i][j-1] !=0){
				add = true;
				for(int k=j;k>0;k--){
					tab[i][k] = tab[i][k-1];
				}
				tab[i][count] = 0;
				count++;
			}
		}
	}
	for(int i=0;i<size;i++){
		for(int j=size-1;j>0;j--){
			if(tab[i][j]==tab[i][j-1] && tab[i][j]!=0){
				add = true;
				tab[i][j] = 2* (tab[i][j]);
				for(int k=j-1;k>0;k--){
					tab[i][k] = tab[i][k-1];
				}
				tab[i][0] = 0; 
			}
		}
	}

	if(add) addRandomNumber();
}
int game2048::gameEnd(){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(tab[i][j]==2048)
				return 1;
		}
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(tab[i][j]==0)
				return 0;
			else if((i<size-1 && tab[i][j]==tab[i+1][j]) || (i>1 && tab[i][j]==tab[i-1][j]) || (j<size-1 && tab[i][j]==tab[i][j+1]) || (j>1 && tab[i][j]==tab[i][j-1])){
				return 0;
			}
		}
	}
	return 2;
}
