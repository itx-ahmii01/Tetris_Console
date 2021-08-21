
#pragma once
#include"Board.h"
#include"Piece.h"
#include <cstdlib>
#include <ctime>
class Game :public Piece {
public:
	
	int a = 0;
	
	int random_shape()                //Random function to generate random shapes
	{

		srand(time(NULL));
		a = (rand() % 7) + 1;    //number between 1 - 7
		return a;
	}

	


	void working() {
		Board board;          //Objects of all classes(shapes)
		Piece p;
		Piece* P[7];
		Piece1 P1;
		P[0] = &P1;
		Piece2 P2;
		P[1] = &P2;
		Piece3 P3;
		P[2] = &P3;
		Piece4 P4;
		P[3] = &P4;
		Piece5 P5;
		P[4] = &P5;
		Piece6 P6;
		P[5] = &P6;
		Piece7 P7;
		P[6] = &P7;
		board.display();     //Display board
		char c = getKey();
		int b;

		b = random_shape();   //Random shape to display
		if (b == 1) {
			while (!P[0]->IsGrounded()) {
				

				system("cls");
				P[0]->shape();
				board.display();
				if (board.gameover == true)     //Break point to end game
				{

					board.gameOver();
					
					break;
				}
				delay(50);    //Time animation

			}
		}

		P[1]->Reset();
		P[0]->OnGround = false;

		if (b == 2) {
			while (!P[1]->IsGrounded()) {
				
				system("cls");
				P[1]->shape();
				board.display();
				if (board.gameover == true)
				{

					board.gameOver();
					
					break;
				}
				delay(50);
			}
			P[1]->Reset();
			P[1]->OnGround = false;
		}

			
		
			if (b == 3) {
				while (!P[2]->IsGrounded()) {
					
					system("cls");
					P[2]->shape();
					board.display();
					if (board.gameover == true)
					{

						board.gameOver();
						
						break;
					}
					delay(50);
				}
				P[1]->Reset();
				P[2]->OnGround = false;
				
			}

			if (b == 4) {
				while (!P[3]->IsGrounded()) {
					
					system("cls");
					P[3]->shape();
					board.display();
					if (board.gameover == true)
					{

						board.gameOver();
						
						break;
					}
					delay(50);

				}
				P[1]->Reset();
				P[3]->OnGround = false;
				
			}

			if (b == 5) {
				while (!P[4]->IsGrounded()) {
					
					system("cls");
					P[4]->shape();
					board.display();
					if (board.gameover == true)
					{

						board.gameOver();
						
						break;
					}
					delay(50);
				}
				P[1]->Reset();
				P[4]->OnGround = false;
				
			}
			if (b == 6) {
				while (!P[5]->IsGrounded()) {
					
					system("cls");
					P[5]->shape();
					board.display();
					if (board.gameover == true)
					{

						board.gameOver();
						
						break;
					}
					delay(50);
				}
				P[1]->Reset();
				P[5]->OnGround = false;
				
			}
			if (b == 7) {
				while (!P[6]->IsGrounded()) {
					
					system("cls");
					P[6]->shape();
					board.display();
					if (board.gameover == true)
					{
						board.gameOver();
						
						break;
					}
					delay(50);
				}
				P[1]->Reset();
				P[6]->OnGround = false;
				
			}





		
	}
};

