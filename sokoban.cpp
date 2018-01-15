#include <iostream>
#include <string>
#include <curses.h>
#include <ctime>
#include <stdlib.h> 
#include "sokoban.hpp"
using namespace std;

sokoban::sokoban(string s){
	/* Chercher hauteur et largeur du tableau data*/
	int h = 1, l =0, r=0;
	for(int i=0;i<s.size();i++){
		if(s.at(i)=='\n'){
			h++;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s.at(i)!='\n'){
			l++;
		}
		else
			break;
	}

	for(int i=0;i<s.size();i++){
		if(s.at(i)=='.'){
			r++;
		}
	}

	largeur = l;
	hauteur = h;
	reachPoint = r;
	data = new char*[hauteur];
	for(int i=0;i<hauteur;i++){
		data[i] = new char[largeur];
	}
	/* Recuperer le data depuis la chaine entree */
	int index = 0;
	for(int j=0;j<hauteur;j++){
		for(int k=0;k<largeur;k++){
			if(s.at(index) != '\n' && index<s.size()){
				data[j][k] = s.at(index);
				index++;
			}
		}
		index++;
	}
	
}
void sokoban::play(){
	char message[50]="USE ARROW KEY!";
	char messageWin[50]="BRAVO! YOU WIN.";
	char messageRobot[50]="ROBOT WIN.";
	char messageLose[50]="YOU LOSE THE GAME.";
	bool check = true;
	int seed = 0;
	while(check){
		initscr();
		start_color();

		init_pair(1, COLOR_BLACK, COLOR_WHITE);
		attron(COLOR_PAIR(1));
		if(gameEnd()==0) drawGame(message);
		else if(gameEnd()==1){
			drawGame(messageWin);
			check = false;
		}
		else {
			drawGame(messageLose);
			check = false;
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
				srand(time(0));
				seed = rand()%4 +1;
				if(seed == 1) moveUp();
				if(seed == 2) moveDown();
				if(seed == 3) moveRight();
				if(seed == 4) moveLeft();
				if(gameEnd()==1){
					drawGame(messageRobot);
					check = false;
				}
				break;
		}
		endwin();

	}
}
void sokoban::drawGame(char* message){
	move(0,0);
	for(int i=0;i<hauteur;i++){
		for(int j=0;j<largeur;j++){
			printw("%c ",data[i][j]);
		}
		printw("\n");
	}
	printw("*************************\n");
	printw( "      %s      ",message);
}
void sokoban::moveUp(){
	int x=0, y=0;
	for(int i=0;i<hauteur;i++){
		for(int j=0;j<largeur;j++){
			if(data[i][j]=='l' || data[i][j]=='L'){
				x= i;
				y = j;
			}
		}
	}
	if(data[x][y]=='l' && x>=1 && data[x-1][y]==' '){
		data[x-1][y]= 'l';
		data[x][y] = ' ';
	}
	if(data[x][y]=='L' && x>=1 && data[x-1][y]==' '){
		data[x-1][y]= 'l';
		data[x][y] = '.';
	}
	if(data[x][y]=='l' && x>=1 && data[x-1][y]=='.'){
		data[x-1][y]= 'L';
		data[x][y] = ' ';
	}
	if(data[x][y]=='L' && x>=1 && data[x-1][y]=='.'){
		data[x-1][y]= 'L';
		data[x][y] = '.';
	}
	if(data[x][y]=='l' && x>=2 && data[x-1][y]=='o' && data[x-2][y]==' '){
		data[x-2][y] = 'o';
		data[x-1][y] = 'l';
		data[x][y] =' ';
	}
	if(data[x][y]=='L' && x>=2 && data[x-1][y]=='o' && data[x-2][y]==' '){
		data[x-2][y] = 'o';
		data[x-1][y] = 'l';
		data[x][y] ='.';
	}
	if(data[x][y]=='l' && x>=2 && data[x-1][y]=='o' && data[x-2][y]=='.'){
		data[x-2][y]= '0';
		data[x-1][y]= 'l';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && x>=2 && data[x-1][y]=='o' && data[x-2][y]=='.'){
		data[x-2][y]= '0';
		data[x-1][y]= 'l';
		data[x][y]='.';
	}
	if(data[x][y]=='l' && x>=2 && data[x-1][y]=='0' && data[x-2][y]==' '){
		data[x-2][y]='o';
		data[x-1][y]='L';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && x>=2 && data[x-1][y]=='0' && data[x-2][y]==' '){
		data[x-2][y]='o';
		data[x-1][y]='L';
		data[x][y]='.';
	}
	if(data[x][y]=='l' && x>=2 && data[x-1][y]=='0' && data[x-2][y]=='.'){
		data[x-2][y]= '0';
		data[x-1][y]= 'L';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && x>=2 && data[x-1][y]=='0' && data[x-2][y]=='.'){
		data[x-2][y]= '0';
		data[x-1][y]= 'L';
		data[x][y]='.';
	}
}
void sokoban::moveDown(){
	int x=0, y=0;
	for(int i=0;i<hauteur;i++){
		for(int j=0;j<largeur;j++){
			if(data[i][j]=='l' || data[i][j]=='L'){
				x= i;
				y = j;
			}
		}
	}
	if(data[x][y]=='l' && data[x+1][y]==' '){
		data[x+1][y]= 'l';
		data[x][y] = ' ';
	}
	if(data[x][y]=='L' && data[x+1][y]==' '){
		data[x+1][y]= 'l';
		data[x][y] = '.';
	}
	if(data[x][y]=='l' && data[x+1][y]=='.'){
		data[x+1][y]= 'L';
		data[x][y] = ' ';
	}
	if(data[x][y]=='L' && data[x+1][y]=='.'){
		data[x+1][y]= 'L';
		data[x][y] = '.';
	}
	if(data[x][y]=='l' && data[x+1][y]=='o' && data[x+2][y]==' '){
		data[x+2][y] = 'o';
		data[x+1][y] = 'l';
		data[x][y] =' ';
	}
	if(data[x][y]=='L' && data[x+1][y]=='o' && data[x+2][y]==' '){
		data[x+2][y] = 'o';
		data[x+1][y] = 'l';
		data[x][y] ='.';
	}
	if(data[x][y]=='l' && data[x+1][y]=='o' && data[x+2][y]=='.'){
		data[x+2][y]= '0';
		data[x+1][y]= 'l';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && data[x+1][y]=='o' && data[x+2][y]=='.'){
		data[x+2][y]= '0';
		data[x+1][y]= 'l';
		data[x][y]='.';
	}
	if(data[x][y]=='l' && data[x+1][y]=='0' && data[x+2][y]==' '){
		data[x+2][y]='o';
		data[x+1][y]='L';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && data[x+1][y]=='0' && data[x+2][y]==' '){
		data[x+2][y]='o';
		data[x+1][y]='L';
		data[x][y]='.';
	}
	if(data[x][y]=='l' && data[x+1][y]=='0' && data[x+2][y]=='.'){
		data[x+2][y]= '0';
		data[x+1][y]= 'L';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && data[x+1][y]=='0' && data[x+2][y]=='.'){
		data[x+2][y]= '0';
		data[x+1][y]= 'L';
		data[x][y]='.';
	}
}
void sokoban::moveLeft(){
	int x=0, y=0;
	for(int i=0;i<hauteur;i++){
		for(int j=0;j<largeur;j++){
			if(data[i][j]=='l' || data[i][j]=='L'){
				x= i;
				y = j;
			}
		}
	}
	if(data[x][y]=='l' && y>=1 && data[x][y-1]==' '){
		data[x][y-1]= 'l';
		data[x][y] = ' ';
	}
	if(data[x][y]=='L' && y>=1 && data[x][y-1]==' '){
		data[x][y-1]= 'l';
		data[x][y] = '.';
	}
	if(data[x][y]=='l' && y>=1 && data[x][y-1]=='.'){
		data[x][y-1]= 'L';
		data[x][y] = ' ';
	}
	if(data[x][y]=='L' && y>=1 && data[x][y-1]=='.'){
		data[x][y-1]= 'L';
		data[x][y] = '.';
	}
	if(data[x][y]=='l' && y>=2 && data[x][y-1]=='o' && data[x][y-2]==' '){
		data[x][y-2] = 'o';
		data[x][y-1] = 'l';
		data[x][y] =' ';
	}
	if(data[x][y]=='L' && y>=2 && data[x][y-1]=='o' && data[x][y-2]==' '){
		data[x][y-2] = 'o';
		data[x][y-1] = 'l';
		data[x][y] ='.';
	}
	if(data[x][y]=='l' && y>=2 && data[x][y-1]=='o' && data[x][y-2]=='.'){
		data[x][y-2]= '0';
		data[x][y-1]= 'l';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && y>=2 && data[x][y-1]=='o' && data[x][y-2]=='.'){
		data[x][y-2]= '0';
		data[x][y-1]= 'l';
		data[x][y]='.';
	}
	if(data[x][y]=='l' && y>=2 && data[x][y-1]=='0' && data[x][y-2]==' '){
		data[x][y-2]='o';
		data[x][y-1]='L';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && y>=2 && data[x][y-1]=='0' && data[x][y-2]==' '){
		data[x][y-2]='o';
		data[x][y-1]='L';
		data[x][y]='.';
	}
	if(data[x][y]=='l' && y>=2 && data[x][y-1]=='0' && data[x][y-2]=='.'){
		data[x][y-2]= '0';
		data[x][y-1]= 'L';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && y>=2 && data[x][y-1]=='0' && data[x][y-2]=='.'){
		data[x][y-2]= '0';
		data[x][y-1]= 'L';
		data[x][y]='.';
	}
}
void sokoban::moveRight(){
	int x=0, y=0;
	for(int i=0;i<hauteur;i++){
		for(int j=0;j<largeur;j++){
			if(data[i][j]=='l' || data[i][j]=='L'){
				x= i;
				y = j;
			}
		}
	}
	if(data[x][y]=='l' && data[x][y+1]==' '){
		data[x][y+1]= 'l';
		data[x][y] = ' ';
	}
	if(data[x][y]=='L' && data[x][y+1]==' '){
		data[x][y+1]= 'l';
		data[x][y] = '.';
	}
	if(data[x][y]=='l' && data[x][y+1]=='.'){
		data[x][y+1]= 'L';
		data[x][y] = ' ';
	}
	if(data[x][y]=='L' && data[x][y+1]=='.'){
		data[x][y+1]= 'L';
		data[x][y] = '.';
	}
	if(data[x][y]=='l' && data[x][y+1]=='o' && data[x][y+2]==' '){
		data[x][y+2] = 'o';
		data[x][y+1] = 'l';
		data[x][y] =' ';
	}
	if(data[x][y]=='L' && data[x][y+1]=='o' && data[x][y+2]==' '){
		data[x][y+2] = 'o';
		data[x][y+1] = 'l';
		data[x][y] ='.';
	}
	if(data[x][y]=='l' && data[x][y+1]=='o' && data[x][y+2]=='.'){
		data[x][y+2]= '0';
		data[x][y+1]= 'l';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && data[x][y+1]=='o' && data[x][y+2]=='.'){
		data[x][y+2]= '0';
		data[x][y+1]= 'l';
		data[x][y]='.';
	}
	if(data[x][y]=='l' && data[x][y+1]=='0' && data[x][y+2]==' '){
		data[x][y+2]='o';
		data[x][y+1]='L';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && data[x][y+1]=='0' && data[x][y+2]==' '){
		data[x][y+2]='o';
		data[x][y+1]='L';
		data[x][y]='.';
	}
	if(data[x][y]=='l' && data[x][y+1]=='0' && data[x][y+2]=='.'){
		data[x][y+2]= '0';
		data[x][y+1]= 'L';
		data[x][y]=' ';
	}
	if(data[x][y]=='L' && data[x][y+1]=='0' && data[x][y+2]=='.'){
		data[x][y+2]= '0';
		data[x][y+1]= 'L';
		data[x][y]='.';
	}
}
int sokoban::gameEnd(){
	/* 1:WIN  2:LOSE  3:CONTINUE PLAY*/
	int count = 0;
	for(int i=0;i<hauteur;i++){
		for(int j=0;j<largeur;j++){
			if(data[i][j]=='0'){
				count++;
			}
		}
	}
	if(reachPoint==count)
		return 1;

	for(int i=1;i<hauteur-1;i++){
		for(int j=1;j<largeur-1;j++){
			if(data[i][j]=='o'){
				if(data[i-1][j]=='#' && data[i][j-1]=='#'){
					return 2;
				}
				if(data[i-1][j]=='#' && data[i][j+1]=='#'){
					return 2;
				}
				if(data[i+1][j]=='#' && data[i][j-1]=='#'){
					return 2;
				}
				if(data[i+1][j]=='#' && data[i][j+1]=='#'){
					return 2;
				}
			}
		}
	}

	return 0;
}
