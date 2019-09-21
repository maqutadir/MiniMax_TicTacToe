#pragma once
#include "stdio.h"
#include "stdlib.h"
#include<iostream>
#include "GL/glew.h"
#include "GL/glut.h"
#include "gameObject.h"


#define WIN_WIDTH	1100
#define WIN_HEIGHT	900


class gameApp
{
public:
	~gameApp();
	gameApp();
	int initGraphics(int argc, char** argv, int winPosx, int winPosy);
	virtual int gameLoop(void);					// start the game loop
	gameObject *myBoard = new gameObject();
	void updateTurn();
	void updateBoard(int x, int y);
	void drawX(int, int);
	void drawO(int, int);
	char retrunToken();
	char valueMyBoardValue(int, int);
	void displayGameWon(char);
	bool checkBoard(int, int);
	bool isMoveLeft();
	int evaluate();
	int minimax(int, bool);
	void bestmove();
	void checkWin();
	char plyr;
	char opp;

private:
	int wId;		//the window handle
					//static gameApp *myApp;

protected:
	static void renderFrame();	//renderFrame
	static void reshapeFun(int width, int height);
	static void mouseFun(int button, int state, int x, int y);
	static void timerFun(int timerEvent);
};