#pragma once
#include"mygraphics.h"

#include<iostream>
using namespace std;
class Board{

	
public:
	bool gameover = false;
	

	void gameOver()
	{
		
		using namespace std;

		char a;
		gotoxy(26, 2);
		cout << "MADE BY PRO_NOOB PROGRAMERS \n\n";
		gotoxy(26, 5);
		cout << " *****     *    *     * ******* ******* **    * ****\n";
		gotoxy(26, 6);
		cout << "*     *   * *   **   ** *       *       * *   * *   *\n";
		gotoxy(26, 7);
		cout << "*        *   *  * * * * *       *       *     * *    *\n";
		gotoxy(26, 8);
		cout << "*  **** *     * *  *  * *****   *****   *  *  * *    *\n";
		gotoxy(26, 9);
		cout << "*     * ******* *     * *       *       *     * *    *\n";
		gotoxy(26, 10);
		cout << "*     * *     * *     * *       *       *   * * *   *\n";
		gotoxy(26, 11);
		cout << " *****  *     * *     * ******* ******* *    ** ****\n";
		gotoxy(26, 12);
		cout << "Press any key and enter";
		gotoxy(26, 15);
		cout << "SCORE="<<score;
		drawRectangle(0, 0, 10, 235, 155, 0, 155, 155, 0, 155);
		drawRectangle(185, 0, 195, 235, 155, 0, 155, 155, 0, 155);
		drawRectangle(0, 0, 195, 11, 25, 0, 250, 25, 0, 250);
		drawRectangle(0, 230, 195, 240, 25, 0, 250, 25, 0, 250);
		delay(100);
		cin >> a;
		
		
	}
	void title()
	{

		using namespace std;

		

		cout << "*==============================================================================*\n";

		cout << "******* ******* ******* ******    ***    *****\n";
		cout << "   *    *          *    *     *    *    *     *\n";
		cout << "   *    *          *    *     *    *    *\n";
		cout << "   *    *****      *    ******     *     *****\n";
		cout << "   *    *          *    *   *      *          *\n";
		cout << "   *    *          *    *    *     *    *     *\n";
		cout << "   *    *******    *    *     *   ***    *****\t\t";
		cout << "\n\n\n\n";
		cout << "MADE BY PRO_NOOB PROGRAMERS \n\n";



		cout << "*==============================================================================*\n";

	}
	
	void display() {
		
	
			
			for (int i = 0; i < 20; i++) {
				for (int j = 0; j < 25; j++) {
					
					cout << map[i][j];
					
					
					
				}
				cout << endl;
			}

			int estaric = 0;
			for (int i = 19; i > 0; i--) {

				for (int j = 0; j < 25; j++)
				{
					if (map[i][j] == '*')
					{
						estaric++;
						break;
					}
					
				}
			}
			
			if (estaric == 18)
			{
				gameover = true;

			}
			
		
			

	}
	
};