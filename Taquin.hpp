#include <iostream>
using namespace std;

class Taquin{
	private:
		int** tab;
		int maxElem;
	public:
		Taquin(int max);
		void drawGame(char* message);
		void randomGame(int niveau);
		void play();
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		bool gameEnd();
};