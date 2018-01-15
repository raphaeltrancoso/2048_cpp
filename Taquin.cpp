#include <iostream>
#include <curses.h>
#include <stdlib.h> 
#include <ctime>
#include "Taquin.hpp"
using namespace std;

Taquin::Taquin(int max){
	maxElem = max;
	tab = new int*[maxElem];
	for(int i=0;i<maxElem;i++){
		tab[i] = new int(0);
	}
}
void Taquin::drawGame(char* message){
	move(0,0);
	printw("*_______________________*\n");
	printw("|     |     |     |     |\n");
	printw("| %2d  | %2d  | %2d  | %2d  |\n",*tab[0],*tab[1],*tab[2],*tab[3]);
	printw("|_____|_____|_____|_____|\n");
	printw("|     |     |     |     |\n");
	printw("| %2d  | %2d  | %2d  | %2d  |\n",*tab[4],*tab[5],*tab[6],*tab[7]);
	printw("|_____|_____|_____|_____|\n");
	printw("|     |     |     |     |\n");
	printw("| %2d  | %2d  | %2d  | %2d  |\n",*tab[8],*tab[9],*tab[10],*tab[11]);
	printw("|_____|_____|_____|_____|\n");
	printw("|     |     |     |     |\n");
	printw("| %2d  | %2d  | %2d  | %2d  |\n",*tab[12],*tab[13],*tab[14],*tab[15]);
	printw("|_____|_____|_____|_____|\n");
	printw("*************************\n");
	printw( " %s   ",message);
}
void Taquin::randomGame(int niveau){
	if(niveau==1){
		for(int i=0;i<maxElem-2;i++){
			tab[i] = new int(i+1);
		}
		tab[maxElem-2] = new int(0);
		tab[maxElem-1] = new int(15);
	}
	else if(niveau==2){
		for(int i=0;i<maxElem-4;i++){
			tab[i] = new int(i+1);
		}
		tab[maxElem-4] = new int(0);
		tab[maxElem-3] = new int(15);
		tab[maxElem-2] = new int(14);
		tab[maxElem-1] = new int(13);
	}
	else if(niveau==3){
		for(int i=0;i<maxElem-1;i++){
			tab[i] = new int(i);
		}
		tab[maxElem-1]= new int(15);
	}
}

void Taquin::play(){
	char message[50]="USE ARROW KEY TO PLAY";
    char messageWin[50]="BRAVO!YOU WIN THE GAME";
	bool check = true;
	while(check){
		initscr();
  		noecho();
  		start_color();
		init_pair(1, COLOR_BLACK, COLOR_WHITE);
		attron(COLOR_PAIR(1));
		if(!gameEnd()) drawGame(message);
		else{
			drawGame(messageWin);
			check = false;
		} 
		refresh();
		keypad ( stdscr, TRUE );
		switch ( getch() )
		{
		    case KEY_UP:
		      moveUp();
		      break;
		    case KEY_DOWN:
		      moveDown();
		      break;
		    case KEY_LEFT:
		      moveLeft();
		      break;
		    case KEY_RIGHT:
		      moveRight();
		      break;
		}
		endwin();
	}

}

void Taquin::moveUp(){
	int pos=0;
	for(int i=0;i<maxElem;i++){
		if(*tab[i]==0){
			pos = i;
		}
	}
	if(pos+4<maxElem){
		tab[pos] = tab[pos+4];
		tab[pos+4] = new int(0);
	}
}
void Taquin::moveDown(){
	int pos=0;
	for(int i=0;i<maxElem;i++){
		if(*tab[i]==0){
			pos = i;
		}
	}
	if(pos-4>=0){
		tab[pos] = tab[pos-4];
		tab[pos-4] = new int(0);
	}

}
void Taquin::moveLeft(){
	int pos=0;
	for(int i=0;i<maxElem;i++){
		if(*tab[i]==0){
			pos = i;
		}
	}
	if((pos+1)%4 !=0){
		tab[pos] = tab[pos+1];
		tab[pos+1] = new int(0);
	}
}
void Taquin::moveRight(){
	int pos=0;
	for(int i=0;i<maxElem;i++){
		if(*tab[i]==0){
			pos = i;
		}
	}
	if(pos%4 !=0){
		tab[pos] = tab[pos-1];
		tab[pos-1] = new int(0);
	}
}

bool Taquin::gameEnd(){
	bool check = true;
	for(int i=0;i<maxElem-1;i++){
		if(*tab[i]!=i+1) check=false;
	}
	if(*tab[maxElem-1]!=0) check==false;
	return check;
}
