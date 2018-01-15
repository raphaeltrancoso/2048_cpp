#include <iostream>
#include <string>
#include "sokoban.hpp"

int main(){
	int choose;
	cout<<"Choose a game(1,2,3,4,5):";
	cin>>choose;
	string s1 = "#############\n"
				"#... #      #\n"
				"#.ooooooo  l#\n"
				"#...        #\n"
				"#############";

	string s2 = "#######\n"
				"###l .#\n"
				"# o #.#\n"
				"#  oo #\n"
				"#.  # #\n"
				"#   o.#\n"
				"#######";

	string s3=	"#######\n"
				"###  ##\n"
				"###o ##\n"
				"# o  l#\n"
				"# ... #\n"
				"##o  ##\n"
				"##  ###\n"
				"#######";

	string s4=  "###########\n"
				"#  #   ####\n"
				"#   o  ####\n"
				"# o## #####\n"
				"## #. ##  #\n"
				"## #.   o #\n"
				"## #. ##  #\n"
				"## #.### ##\n"
				"##l   ##  #\n"
				"### o     #\n"
				"########  #\n"
				"###########";

	string s5=  "##################\n"
				"#  ### l #       #\n"
				"#  o #ooo# ##### #\n"
				"#..............# #\n"
				"##o#o#oo ####  o #\n"
				"#  o #   #### oo##\n"
				"#  o ######## o ##\n"
				"# #  ########   ##\n"
				"#   #########   ##\n"
				"##################";


	if(choose == 1){
		sokoban game(s1);
			game.play();
	}
	else if(choose == 2){
		sokoban game(s2);
			game.play();
	}
	else if(choose==3){
		sokoban game(s3);
			game.play();
	}
	else if(choose==4){
		sokoban game(s4);
			game.play();
	}
	else if(choose==5){
		sokoban game(s5);
			game.play();
	}
	else
		cout<< "Choose invalide"<<endl;
	return 0;
}
