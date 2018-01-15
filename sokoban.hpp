#include <iostream>
#include <string>
using namespace std;

class sokoban {
	private:
		char** data;
		int largeur;
		int hauteur;
		int reachPoint;

	public:
		sokoban(string s);
		void play();
		void drawGame(char* message);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		int gameEnd();

};