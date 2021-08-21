

#include<iostream>

char map[20][25] = {
			"________________________",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"|                      |",
			"________________________"
};
int score = 0;
#include"Game.h"
#include"Board.h"
#include"mygraphics.h"
using namespace std;

int main() {
	
	Game G;     //object for game class
	Board b;    //object for board class
	int a = 0;
	G.title();        //Startup menu
	delay(2000);
	cin >> a;
	game_loop:      //goto statement
	if (a == 1)
	{
		while(true){
		
			system("cls");

			G.working();
			


		}
	}
	else
	{
		cout << "Press 1 to play game:";
		cin >> a;
		if (a == 1)
		{
			goto game_loop;
		}

	}

	
	system("pause");

	


}