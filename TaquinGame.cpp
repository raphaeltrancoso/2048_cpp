#include <iostream>
#include "Taquin.hpp"
using namespace std;

int main(){
	int choose = 0;
	cout<<"Choisir le niveau de difficulté(1,2,3): ";
	cin>>choose;
	Taquin t(16);
	if(choose==1 || choose==2 || choose==3){
		t.randomGame(choose);
			t.play();
	}
	else
		cout<<"Choix invalide!!!"<<endl;
	return 0;
}