#include <iostream>
#include <string>
using namespace std;

class game2048_3{
private:
	int** tab;
	int size;
	int puissance;
public:
	game2048_3(int s,int p);
	void drawGame(char* message);
	void addRandomNumber();
	void play();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	int gameEnd();
};
