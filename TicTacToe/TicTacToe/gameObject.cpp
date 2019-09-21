#include "gameObject.h"
#include<iostream>

gameObject::gameObject(void)
{
	size = 4;
	whoesTurn = 1;
	token = 'O';
	gameBoard = new char*[size];
	//gameBoardChar = '-';
	initBoard();
	

	/*
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gameBoard[i][j] = i;
		}
	}

	//print
	std::cout << "Initial Game Board" << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << gameBoard[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	
	*/
}

gameObject::~gameObject(void)
{

}

void gameObject::initBoard(void)
{
	//dynamic allocation
	//gameBoard = new int*[size];
	
	for (int i = 0; i < size; i++)
	{
		gameBoard[i] = new char[size];
	}

	// fill
	/*
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gameBoard[i][j] = i;
		}
	}

	//print
	std::cout << "Initial Game Board" << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << gameBoard[i][j]<<"\t";
		}
		std::cout<<std::endl;
	}
	*/



	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			gameBoard[i][j] = '_';
		}
	}

	//print
	std::cout << "Initial Game Board" << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << gameBoard[i][j] << "\t";
		}
		std::cout << std::endl;
	}


}


void gameObject::whoesTurnFun()
{
	++whoesTurn;
	if (whoesTurn %2 == 0)
	{
		token = 'X';
	}
	else
	{
		token = 'O';
	}
}

void gameObject::updategameBoard(int i, int j)
{
	gameBoard[i][j] = token;
	
	for (int k = 0; k < 4; k++)
	{
		for (int l = 0; l < 4; l++)
		{
			std::cout << gameBoard[k][l] << "\t";
		}
		std::cout << std::endl;
	}
	
}