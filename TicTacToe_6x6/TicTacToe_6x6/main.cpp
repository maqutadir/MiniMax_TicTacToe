#include "GL\glew.h"
#include "GL\glut.h"
#include "gameApp.h"

// DEFINES and MACROS
#define WIN_POS_X	30
#define WIN_POS_Y	10
//#define WIN_WIDTH	500
//#define WIN_HEIGHT	400

int main(int argc, char** argv)
{

	gameApp *myGame = new gameApp();


	// initialize OpenGL 
	myGame->initGraphics(argc, argv, WIN_POS_X, WIN_POS_Y);

	myGame->gameLoop();
}