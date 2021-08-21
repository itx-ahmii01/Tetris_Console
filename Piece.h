
#pragma once

#include"Board.h"
#include<iostream>


using namespace std;
class Piece :public Board {       //Base Class for all shapes Inherited to Board
protected:


public:

	int x = 1, y = 12;
	
	Piece();
	virtual void shape();               //Polymorphism
	void gotoxy(int x, int y)
	{
		COORD c;         /* Using column number as x-coordinate and row number as y-coordinate*/
		c.X = y;
		c.Y = x;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	}
	void motion(int x, int y)
	{
		if (GetAsyncKeyState(VK_DOWN))       /*Moves to the below row*/
		{
			this->y--;
		}
		if (GetAsyncKeyState(VK_LEFT))          /*Moves 1 column back */
		{
			this->x--;
		}
		if (GetAsyncKeyState(VK_RIGHT))        /*Moves to the next column*/
		{
			this->x++;
		}
		if (GetAsyncKeyState(VK_UP))         /*Moves to the upper row*/
		{
			this->y++;
		}

	}
	void Reset()      //Function to reset coordinates
	{
		x = 1;
		y = 12;
	}
	virtual bool IsGrounded()         //Function for shapes untill it touches base
	{
		return false;
	}
	bool OnGround;
};
Piece::Piece()
{
	//Default Constructor
}
void Piece::shape()
{
	//Function to be over-ride
}
class Piece1 :public Piece {

private:
	int Count;

	int Row, Col;
	char** shape1;

public:


	Piece1()                                               //constructor
	{
		Row = 2, Col = 2;

		shape1 = new char* [Row];

		for (int i = 0; i < Row; i++)
		{
			shape1[i] = new char[Col];
		}

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				shape1[i][j] = '*';
			}
		}

		Count = 0;
		OnGround = false;
	}

	void shape()                                         //function to draw shape
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				map[x + i][y + j] = shape1[i][j];
			}
		}
		if (map[x + Row][y] == '_' || map[x + Row][y] == '*' || map[x + Row][y + 1] == '*')          //condition to check the shape is on the ground or not
		{
			OnGround = true;
			return;
		}

		Count++;
		char c = getKey();
	if (c == 'd') 
	{
		

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				map[x + i][y + j] = ' ';
			}
		}

		if (map[x][y + Col] == '|' || map[x][y + Col] == '*' || map[x + Row][y + Col] == '*') {        //conditions to move right
			y--;
		}
		y = y + 1;
	}
		if (c == 'a') {                                        // key to move the shape left side
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			y = y - 1;
			if (map[x][y] == '|' || map[x][y] == '*' || map[x+Row][y] == '*') {            //conditions to move left
				y++;
			}
		}
		if (c == 's' && (map[x + Row][y] != '*' || map[x + Row][y + (Col - 1)] != '*')) {                                      //key to speed up the downward motion of shape
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x+Row][y]!='_') {
				x = x + 1;
			}
		}

		if (Count == 4)                                 //check to move shape downward
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}

			x++;
			Count = 0;
		}

	}

	bool IsGrounded()
	{
		return OnGround;
	}


};
class Piece2 :public Piece {

private:
	int Count;
	bool OnGround;

	int Row, Col;
	char** shape2;

public:

	Piece2()
	{
		Row = 2; Col = 3;

		shape2 = new char* [Row];

		for (int i = 0; i < Row; i++)
		{
			shape2[i] = new char[Col];
		}

		shape2[0][0] = ' ';
		shape2[0][1] = '*';
		shape2[0][2] = ' ';
		
        shape2[1][0] = '*';
		shape2[1][1] = '*';
		shape2[1][2] = '*';

		OnGround = false;
		Count = 0;
	}

	void shape()
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				map[x + i][y + j] = shape2[i][j];
			}
		}

		Count++;

		if (map[x + Row][y] == '_' || map[x + Row][y] == '*' || map[x + Row][y+1] == '*' || map[x + Row][y+2] == '*')
		{
			OnGround = true;
			return;
		}
		char c = getKey();
		if (c == 'd') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			
			if (map[x][y + Col] == '|' || map[x][y + Col] == '*' || map[x+Row][y + Col] == '*') {
				y--;
			}
			y = y + 1;
		}
		if (c == 'a') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			y = y - 1;
			if (map[x][y] == '|' || map[x][y] == '*' || map[x + Row][y] == '*') {
				y++;
			}
		}
		if (c == 's' &&  (map[x+Row][y]!='*'|| map[x + Row][y+(Col-1)] != '*')) {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x + Row][y] != '*') {
				x = x + 1;
			}
		}
		if (Count == 4)
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}

			x++;
			Count = 0;
		}
	}

	bool IsGrounded()
	{
		return OnGround;
	}

};
class Piece3 :public Piece {
private:
	int Count;
	bool OnGround;

	int Row, Col;
	char** shape3;
public:
	Piece3()
	{
		Row = 3; Col = 1;

		shape3 = new char* [Row];

		for (int i = 0; i < Row; i++)
		{
			shape3[i] = new char[Col];
		}

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				shape3[i][j] = '*';
			}
		}

		OnGround = false;
		Count = 0;
	}


	void shape()
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				map[x + i][y + j] = shape3[i][j];
			}
		}

		Count++;

		if (map[x + Row][y] == '_' || map[x + Row][y] == '*')
		{
			OnGround = true;
			return;
		}

		char c = getKey();
		if (c == 'd') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x][y + Col] == '|' || map[x][y + Col] == '*' || map[x + Row][y + Col] == '*') {
				y--;
			}
			y = y + 1;
		}
		if (c == 'a') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			y = y - 1;
			if (map[x][y] == '|' || map[x][y] == '*' || map[x + Row][y] == '*') {
				y++;
			}
		}
		if (c == 's' && (map[x + Row][y] != '*' || map[x + Row][y + (Col - 1)] != '*')) {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x + Row][y] != '*') {
				x = x + 1;
			}
		}

		if (Count == 3)
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}

			x++;
			Count = 0;
		}
	}

	bool IsGrounded()
	{
		return OnGround;
	}


};
class Piece4 :public Piece {
private:
	int Count;
	bool OnGround;

	int Row, Col;
	char** shape4;
public:
	Piece4()
	{

		Row = 3; Col = 3;

		shape4 = new char* [Row];

		for (int i = 0; i < Row; i++)
		{
			shape4[i] = new char[Col];
		}

		shape4[0][0] = ' ';
		shape4[0][1] = ' ';
		shape4[0][2] = ' ';

		shape4[1][0] = '*';
		shape4[1][1] = '*';
		shape4[1][2] = ' ';

		shape4[2][0] = ' ';
		shape4[2][1] = '*';
		shape4[2][2] = '*';


		OnGround = false;
		Count = 0;
	}

	void shape()
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (shape4[i][j] == '*') {
					map[x + i][y + j] = shape4[i][j];
				}
			}
		}

		Count++;

		if (map[x + Row][y] == '_' || map[x +2][y] == '*'||map[x + Row][y+1] == '*' || map[x + Row][y + 2] == '*')
		{
			OnGround = true;
			return;
		}
		char c = getKey();
		if (c == 'd') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x][y + Col] == '|' || map[x][y + Col] == '*' || map[x + Row][y + Col] == '*') {
				y--;
			}
			y = y + 1;
		}
		if (c == 'a') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			y = y - 1;
			if (map[x][y] == '|' || map[x][y] == '*' || map[x + Row][y] == '*') {
				y++;
			}
		}
		if (c == 's' && (map[x + Row][y] != '*' || map[x + Row][y + (Col - 1)] != '*')) {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x + Row][y] != '*') {
				x = x + 1;
			}
		}

		if (Count == 4)
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}



			x++;
			Count = 0;
		}
	}

	bool IsGrounded()
	{
		return OnGround;
	}
};
class Piece5 :public Piece {
private:
	int Count;
	bool OnGround;

	int Row, Col;
	char** shape5;
public:
	Piece5()
	{

		Row = 3; Col = 3;

		shape5 = new char* [Row];

		for (int i = 0; i < Row; i++)
		{
			shape5[i] = new char[Col];
		}

		shape5[0][0] = ' ';
		shape5[0][1] = ' ';
		shape5[0][2] = ' ';

		shape5[1][0] = ' ';
		shape5[1][1] = '*';
		shape5[1][2] = '*';

		shape5[2][0] = '*';
		shape5[2][1] = '*';
		shape5[2][2] = ' ';


		OnGround = false;
		Count = 0;
	}
	void shape()
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (shape5[i][j] == '*') {
					map[x + i][y + j] = shape5[i][j];
				}
			}
		}

		Count++;

		if (map[x + Row][y] == '_' || map[x + Row][y] == '*' ||map[x + Row][y+1] == '*' || map[x + 2][y + 2] == '*')
		{
			OnGround = true;
			return;
		}

		char c = getKey();
		if (c == 'd') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x][y + Col] == '|' || map[x][y + Col] == '*' || map[x + Row][y + Col] == '*') {
				y--;
			}
			y = y + 1;
		}
		if (c == 'a') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			y = y - 1;
			if (map[x][y] == '|' || map[x][y] == '*' || map[x + Row][y] == '*') {
				y++;
			}
		}
		if (c == 's' && (map[x + Row][y] != '*' || map[x + Row][y + (Col - 1)] != '*')) {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x + Row][y] != '*') {
				x = x + 1;
			}
		}

		if (Count == 4)
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}



			x++;
			Count = 0;
		}
	}

	bool IsGrounded()
	{
		return OnGround;
	}

};
class Piece6 :public Piece {
private:
	int Count;
	bool OnGround;
	int Row, Col;
	char** shape6;
public:
	Piece6()
	{
		Row = 3, Col = 2;

		shape6 = new char* [Row];

		for (int i = 0; i < Row; i++)
		{
			shape6[i] = new char[Col];
		}

		shape6[0][0] = ' ';
		shape6[0][1] = '*';
		shape6[1][0] = ' ';
		shape6[1][1] = '*';
		shape6[2][0] = '*';
		shape6[2][1] = '*';

		Count = 0;
		OnGround = false;
	}

	void shape()
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (shape6[i][j] == '*') {
					map[x + i][y + j] = shape6[i][j];
				}
			}
		}

		Count++;

		if (map[x + Row][y] == '_' || map[x + Row][y] == '*' || map[x + Row][y + 1] == '*')
		{
			OnGround = true;
			return;
		}
		char c = getKey();
		if (c == 'd') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x][y + Col] == '|' || map[x][y + Col] == '*' || map[x + Row][y + Col] == '*') {
				y--;
			}
			y = y + 1;
		}
		if (c == 'a') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			y = y - 1;
			if (map[x][y] == '|' || map[x][y] == '*' || map[x + Row][y] == '*') {
				y++;
			}
		}
		if (c == 's' && (map[x + Row][y] != '*' || map[x + Row][y + (Col - 1)] != '*')) {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x + Row][y] != '*') {
				x = x + 1;
			}
		}

		if (Count == 4)
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}

			x++;
			Count = 0;
		}

	}

	bool IsGrounded()
	{
		return OnGround;
	}

};

class Piece7 :public Piece {
private:
	int Count;
	bool OnGround;
	int Row, Col;
	char** shape7;
public:
	Piece7()
	{
		Row = 3, Col = 2;

		shape7 = new char* [Row];

		for (int i = 0; i < Row; i++)
		{
			shape7[i] = new char[Col];
		}

		shape7[0][0] = '*';
		shape7[0][1] = ' ';
		shape7[1][0] = '*';
		shape7[1][1] = ' ';
		shape7[2][0] = '*';
		shape7[2][1] = '*';

		Count = 0;
		OnGround = false;
	}

	void shape()
	{
		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (shape7[i][j] == '*') {
					map[x + i][y + j] = shape7[i][j];
				}
			}
		}

		Count++;

		if (map[x + Row][y] == '_' || map[x + Row][y] == '*' || map[x + Row][y + 1] == '*')
		{
			OnGround = true;
			return;
		}

		char c = getKey();
		if (c == 'd') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x][y + Col] == '|' || map[x][y + Col] == '*' || map[x + Row][y + Col] == '*') {
				y--;
			}
			y = y + 1;
		}
		if (c == 'a') {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			y = y - 1;
			if (map[x][y] == '|' || map[x][y] == '*' || map[x + Row][y] == '*') {
				y++;
			}
		}
		if (c == 's' && (map[x + Row][y] != '*' || map[x + Row][y + (Col - 1)] != '*')) {
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}
			if (map[x + Row][y] != '*') {
				x = x + 1;
			}
		}
		if (Count == 4)
		{
			for (int i = 0; i < Row; i++)
			{
				for (int j = 0; j < Col; j++)
				{
					map[x + i][y + j] = ' ';
				}
			}

			x++;
			Count = 0;
		}

	}

	bool IsGrounded()
	{
		return OnGround;
	}



};