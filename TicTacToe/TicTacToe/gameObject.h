#pragma once
class gameObject {
public:
	int size;	//size of the game board for now 4X4
	char** gameBoard;
	//char gameBoardChar;
	//int gameBoard[4][4];
	int whoesTurn;
	char token;
	gameObject();
	~gameObject();
	void initBoard();
	void whoesTurnFun();
	void updategameBoard(int , int );
	
};