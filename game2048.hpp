#include <iostream>
#include <string>
using namespace std;

class game2048{
private:
	int** tab;
	int size;
	int puissance;
public:
	game2048(int s,int p);
	void drawGame(char* message);
	void addRandomNumber();
	void play();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	int gameEnd();
};
