#include "gameApp.h"
#include <algorithm>  

gameApp * myApp = new gameApp;

gameApp::gameApp(void)
{
	plyr = 'X';
	opp = 'O';
}

gameApp::~gameApp(void)
{

}

int gameApp::initGraphics(int argc, char** argv, int winPosx, int winPosy)
{
	//  initialize GLUT and pass it the command variables
	glutInit(&argc, argv);

	//sglutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// Set the window
	// instruct openGL where to put the window on the screen
	glutInitWindowPosition(winPosx, winPosy);

	// instruct openGL what window size to use
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);

	// create the fist window and obtain a handle to it 
	wId = glutCreateWindow("Tic Tac Toe");

	GLenum res = glewInit();
	if (res != GLEW_OK) {
		std::cout << "Error - \n" << glewGetErrorString(res);
		return (-1);
	}

	// print OpenGL information
	printf("Renderer: %s \n", glGetString(GL_RENDERER));
	printf("OpenGL version: %s \n", glGetString(GL_VERSION));
	printf("OpenGL shading language version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));



	glutReshapeFunc(reshapeFun);
	glutDisplayFunc(renderFrame);
	glutMouseFunc(mouseFun);
	glutTimerFunc(10, timerFun, 1);
}

void gameApp::renderFrame(void)
{
	// clear the window and fill it with white colour
	// set up gl colour to white
	glClearColor(1.0, 1.0, 1.0, 0.0);
	// clearing up the canvas with the specific colour
	glClear(GL_COLOR_BUFFER_BIT);
	// swap the buffers (using double buffers

	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	//Vertical Lines
	glVertex2f(300, 200);
	glVertex2f(300, 800);
	glVertex2f(450, 200);
	glVertex2f(450, 800);
	glVertex2f(600, 200);
	glVertex2f(600, 800);
	glVertex2f(750, 200);
	glVertex2f(750, 800);
	glVertex2f(900, 200);
	glVertex2f(900, 800);
	//Horizontal Lines
	glVertex2f(150, 500);
	glVertex2f(1050, 500);
	glVertex2f(150, 400);
	glVertex2f(1050, 400);
	glVertex2f(150, 300);
	glVertex2f(1050, 300);
	glVertex2f(150, 600);
	glVertex2f(1050, 600);
	glVertex2f(150, 700);
	glVertex2f(1050, 700);

	char c;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{

			c = myApp->valueMyBoardValue(i, j);
			if (c == 'X')
				myApp->drawX(i, j);
			else if (c == 'O')
				myApp->drawO(i, j);
		}
	}

	glEnd();

	glutSwapBuffers();
}

int gameApp::gameLoop()
{
	//enter glut main loop
	glutMainLoop();
	return 0;
}

void gameApp::reshapeFun(int width, int height)
{
	//
	/* use the full view port */
	glViewport(0, 0, width, height);

	/* use 2D orthographic parallel projection */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, WIN_WIDTH, 0.0, WIN_HEIGHT);
}

void gameApp::mouseFun(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//std::cout << "x coordinate: "<<x<< std::endl;
		//std::cout << "y coordinate: " << y << std::endl;
	}


	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		std::cout << "x coordinate: " << x << std::endl;
		std::cout << "y coordinate: " << y << std::endl;

		char tok;

		//if (x >= 150 && x <= 750) 
		//{
		//if (y >= 200 && y <= 600)
		//{
		//myApp->updateTurn();
		//}
		//}

		tok = myApp->retrunToken();

		if (x >= 150 && x <= 300)
		{
			

			if (y >= 600 && y <= 700)
			{
				myApp->updateBoard(5, 0);
				myApp->updateTurn();
			}

			else if (y >= 500 && y < 600)
			{
				if (myApp->checkBoard(5, 0))
				{
					myApp->updateBoard(4, 0);
					myApp->updateTurn();
				}
			}
			else if (y >= 400 && y < 500)
			{
				if (myApp->checkBoard(4, 0))
				{
					myApp->updateBoard(3, 0);
					myApp->updateTurn();
				}
			}
			else if (y >= 300 && y < 400)
			{
				if (myApp->checkBoard(3, 0))
				{
					myApp->updateBoard(2, 0);
					myApp->updateTurn();
				}
			}
			else if (y >= 200 && y <= 300)
			{
				if (myApp->checkBoard(2, 0))
				{
					myApp->updateBoard(1, 0);
					myApp->updateTurn();
				}
			}

			else if (y >= 100 && y <= 200)
			{
				if (myApp->checkBoard(1, 0))
				{
					myApp->updateBoard(0, 0);
					myApp->updateTurn();
				}
			}
		}
		else if (x >= 300 && x < 450)
		{
			if (y >= 600 && y <= 700)
			{
				myApp->updateBoard(5, 1);
				myApp->updateTurn();
			}

			else if (y >= 500 && y < 600)
			{
				if (myApp->checkBoard(5, 1))
				{
					myApp->updateBoard(4, 1);
					myApp->updateTurn();
				}
			}
			else if (y >= 400 && y < 500)
			{
				if (myApp->checkBoard(4, 1))
				{
					myApp->updateBoard(3, 1);
					myApp->updateTurn();
				}
			}
			else if (y >= 300 && y < 400)
			{
				if (myApp->checkBoard(3, 1))
				{
					myApp->updateBoard(2, 1);
					myApp->updateTurn();
				}
			}
			else if (y >= 200 && y <= 300)
			{
				if (myApp->checkBoard(2, 1))
				{
					myApp->updateBoard(1, 1);
					myApp->updateTurn();
				}
			}

			else if (y >= 100 && y <= 200)
			{
				if (myApp->checkBoard(1, 1))
				{
					myApp->updateBoard(0, 1);
					myApp->updateTurn();
				}
			}
		}
		else if (x >= 450 && x < 600)
		{
			if (y >= 600 && y <= 700)
			{
				myApp->updateBoard(5, 2);
				myApp->updateTurn();
			}

			else if (y >= 500 && y < 600)
			{
				if (myApp->checkBoard(5, 2))
				{
					myApp->updateBoard(4, 2);
					myApp->updateTurn();
				}
			}
			else if (y >= 400 && y < 500)
			{
				if (myApp->checkBoard(4, 2))
				{
					myApp->updateBoard(3, 2);
					myApp->updateTurn();
				}
			}
			else if (y >= 300 && y < 400)
			{
				if (myApp->checkBoard(3, 2))
				{
					myApp->updateBoard(2, 2);
					myApp->updateTurn();
				}
			}
			else if (y >= 200 && y <= 300)
			{
				if (myApp->checkBoard(2, 2))
				{
					myApp->updateBoard(1, 2);
					myApp->updateTurn();
				}
			}

			else if (y >= 100 && y <= 200)
			{
				if (myApp->checkBoard(1, 2))
				{
					myApp->updateBoard(0, 2);
					myApp->updateTurn();
				}
			}
		}
		else if (x >= 600 && x < 750)
		{
			if (y >= 600 && y <= 700)
			{
				myApp->updateBoard(5, 3);
				myApp->updateTurn();
			}

			else if (y >= 500 && y < 600)
			{
				if (myApp->checkBoard(5, 3))
				{
					myApp->updateBoard(4, 3);
					myApp->updateTurn();
				}
			}
			else if (y >= 400 && y < 500)
			{
				if (myApp->checkBoard(4, 3))
				{
					myApp->updateBoard(3, 3);
					myApp->updateTurn();
				}
			}
			else if (y >= 300 && y < 400)
			{
				if (myApp->checkBoard(3, 3))
				{
					myApp->updateBoard(2, 3);
					myApp->updateTurn();
				}
			}
			else if (y >= 200 && y <= 300)
			{
				if (myApp->checkBoard(2, 3))
				{
					myApp->updateBoard(1, 3);
					myApp->updateTurn();
				}
			}

			else if (y >= 100 && y <= 200)
			{
				if (myApp->checkBoard(1, 3))
				{
					myApp->updateBoard(0, 3);
					myApp->updateTurn();
				}
			}
		}

		else if (x >= 750 && x < 900)
		{
			if (y >= 600 && y <= 700)
			{
				myApp->updateBoard(5, 4);
				myApp->updateTurn();
			}

			else if (y >= 500 && y < 600)
			{
				if (myApp->checkBoard(5, 4))
				{
					myApp->updateBoard(4, 4);
					myApp->updateTurn();
				}
			}
			else if (y >= 400 && y < 500)
			{
				if (myApp->checkBoard(4, 4))
				{
					myApp->updateBoard(3, 4);
					myApp->updateTurn();
				}
			}
			else if (y >= 300 && y < 400)
			{
				if (myApp->checkBoard(3, 4))
				{
					myApp->updateBoard(2, 4);
					myApp->updateTurn();
				}
			}
			else if (y >= 200 && y <= 300)
			{
				if (myApp->checkBoard(2, 4))
				{
					myApp->updateBoard(1, 4);
					myApp->updateTurn();
				}
			}

			else if (y >= 100 && y <= 200)
			{
				if (myApp->checkBoard(1, 4))
				{
					myApp->updateBoard(0, 4);
					myApp->updateTurn();
				}
			}
		}

		else if (x >= 900 && x < 1050)
		{
			if (y >= 600 && y <= 700)
			{
				myApp->updateBoard(5, 5);
				myApp->updateTurn();
			}

			else if (y >= 500 && y < 600)
			{
				if (myApp->checkBoard(5, 5))
				{
					myApp->updateBoard(4, 5);
					myApp->updateTurn();
				}
			}
			else if (y >= 400 && y < 500)
			{
				if (myApp->checkBoard(4, 5))
				{
					myApp->updateBoard(3, 5);
					myApp->updateTurn();
				}
			}
			else if (y >= 300 && y < 400)
			{
				if (myApp->checkBoard(3, 5))
				{
					myApp->updateBoard(2, 5);
					myApp->updateTurn();
				}
			}
			else if (y >= 200 && y <= 300)
			{
				if (myApp->checkBoard(2, 5))
				{
					myApp->updateBoard(1, 5);
					myApp->updateTurn();
				}
			}

			else if (y >= 100 && y <= 200)
			{
				if (myApp->checkBoard(1, 5))
				{
					myApp->updateBoard(0, 5);
					myApp->updateTurn();
				}
			}
		}

	}

}

void gameApp::updateTurn()
{
	//std::cout << "The turn is now of: ";
	myBoard->whoesTurnFun();
	//std::cout << "The turn is now of: " << myBoard->whoesTurn;
	std::cout << "Token is now: " << myBoard->token << std::endl;
}

void gameApp::updateBoard(int s, int t)
{
	myBoard->updategameBoard(s, t);
}

char gameApp::retrunToken()
{
	return myBoard->token;
}

void gameApp::drawX(int i, int j)
{
	int x_11, y_11, x_12, y_12, x_21, y_21, x_22, y_22;

	//Vertical Lines
	if (i == 5 && j == 0)
	{
		x_11 = 300; y_11 = 200;
		x_12 = 150; y_12 = 300;
		x_21 = 300; y_21 = 300;
		x_22 = 150; y_22 = 200;
	}
	if (i == 4 && j == 0)
	{
		x_11 = 300; y_11 = 300;
		x_12 = 150; y_12 = 400;
		x_21 = 300; y_21 = 400;
		x_22 = 150; y_22 = 300;
	}
	if (i == 3 && j == 0)
	{
		x_11 = 300; y_11 = 400;
		x_12 = 150; y_12 = 500;
		x_21 = 300; y_21 = 500;
		x_22 = 150; y_22 = 400;
	}
	if (i == 2 && j == 0)
	{
		x_11 = 300; y_11 = 500;
		x_12 = 150; y_12 = 600;
		x_21 = 300; y_21 = 600;
		x_22 = 150; y_22 = 500;
	}
	if (i == 1 && j == 0)
	{
		x_11 = 300; y_11 = 600;
		x_12 = 150; y_12 = 700;
		x_21 = 300; y_21 = 700;
		x_22 = 150; y_22 = 600;
	}
	if (i == 0 && j == 0)
	{
		x_11 = 300; y_11 = 700;
		x_12 = 150; y_12 = 800;
		x_21 = 300; y_21 = 800;
		x_22 = 150; y_22 = 700;
	}
	if (i == 5 && j == 1)
	{
		x_11 = 450; y_11 = 200;
		x_12 = 300; y_12 = 300;
		x_21 = 450; y_21 = 300;
		x_22 = 300; y_22 = 200;
	}
	if (i == 4 && j == 1)
	{
		x_11 = 450; y_11 = 300;
		x_12 = 300; y_12 = 400;
		x_21 = 450; y_21 = 400;
		x_22 = 300; y_22 = 300;
	}
	if (i == 3 && j == 1)
	{
		x_11 = 450; y_11 = 400;
		x_12 = 300; y_12 = 500;
		x_21 = 450; y_21 = 500;
		x_22 = 300; y_22 = 400;
	}
	if (i == 2 && j == 1)
	{
		x_11 = 450; y_11 = 500;
		x_12 = 300; y_12 = 600;
		x_21 = 450; y_21 = 600;
		x_22 = 300; y_22 = 500;
	}
	if (i == 1 && j == 1)
	{
		x_11 = 450; y_11 = 600;
		x_12 = 300; y_12 = 700;
		x_21 = 450; y_21 = 700;
		x_22 = 300; y_22 = 600;
	}
	if (i == 0 && j == 1)
	{
		x_11 = 450; y_11 = 700;
		x_12 = 300; y_12 = 800;
		x_21 = 450; y_21 = 800;
		x_22 = 300; y_22 = 700;
	}
	if (i == 5 && j == 2)
	{
		x_11 = 600; y_11 = 200;
		x_12 = 450; y_12 = 300;
		x_21 = 600; y_21 = 300;
		x_22 = 450; y_22 = 200;
	}
	if (i == 4 && j == 2)
	{
		x_11 = 600; y_11 = 300;
		x_12 = 450; y_12 = 400;
		x_21 = 600; y_21 = 400;
		x_22 = 450; y_22 = 300;
	}
	if (i == 3 && j == 2)
	{
		x_11 = 600; y_11 = 400;
		x_12 = 450; y_12 = 500;
		x_21 = 600; y_21 = 500;
		x_22 = 450; y_22 = 400;
	}
	if (i == 2 && j == 2)
	{
		x_11 = 600; y_11 = 500;
		x_12 = 450; y_12 = 600;
		x_21 = 600; y_21 = 600;
		x_22 = 450; y_22 = 500;
	}
	if (i == 1 && j == 2)
	{
		x_11 = 600; y_11 = 600;
		x_12 = 450; y_12 = 700;
		x_21 = 600; y_21 = 700;
		x_22 = 450; y_22 = 600;
	}
	if (i == 0 && j == 2)
	{
		x_11 = 600; y_11 = 700;
		x_12 = 450; y_12 = 800;
		x_21 = 600; y_21 = 800;
		x_22 = 450; y_22 = 700;
	}
	if (i == 5 && j == 3)
	{
		x_11 = 750; y_11 = 200;
		x_12 = 600; y_12 = 300;
		x_21 = 750; y_21 = 300;
		x_22 = 600; y_22 = 200;
	}
	if (i == 4 && j == 3)
	{
		x_11 = 750; y_11 = 300;
		x_12 = 600; y_12 = 400;
		x_21 = 750; y_21 = 400;
		x_22 = 600; y_22 = 300;
	}
	if (i == 3 && j == 3)
	{
		x_11 = 750; y_11 = 400;
		x_12 = 600; y_12 = 500;
		x_21 = 750; y_21 = 500;
		x_22 = 600; y_22 = 400;
	}
	if (i == 2 && j == 3)
	{
		x_11 = 750; y_11 = 500;
		x_12 = 600; y_12 = 600;
		x_21 = 750; y_21 = 600;
		x_22 = 600; y_22 = 500;
	}
	if (i == 1 && j == 3)
	{
		x_11 = 750; y_11 = 600;
		x_12 = 600; y_12 = 700;
		x_21 = 750; y_21 = 700;
		x_22 = 600; y_22 = 600;
	}
	if (i == 0 && j == 3)
	{
		x_11 = 750; y_11 = 700;
		x_12 = 600; y_12 = 800;
		x_21 = 750; y_21 = 800;
		x_22 = 600; y_22 = 700;
	}
	if (i == 5 && j == 4)
	{
		x_11 = 900; y_11 = 200;
		x_12 = 750; y_12 = 300;
		x_21 = 900; y_21 = 300;
		x_22 = 750; y_22 = 200;
	}
	if (i == 4 && j == 4)
	{
		x_11 = 900; y_11 = 300;
		x_12 = 750; y_12 = 400;
		x_21 = 900; y_21 = 400;
		x_22 = 750; y_22 = 300;
	}
	if (i == 3 && j == 4)
	{
		x_11 = 900; y_11 = 400;
		x_12 = 750; y_12 = 500;
		x_21 = 900; y_21 = 500;
		x_22 = 750; y_22 = 400;
	}
	if (i == 2 && j == 4)
	{
		x_11 = 900; y_11 = 500;
		x_12 = 750; y_12 = 600;
		x_21 = 900; y_21 = 600;
		x_22 = 750; y_22 = 500;
	}
	if (i == 1 && j == 4)
	{
		x_11 = 900; y_11 = 600;
		x_12 = 750; y_12 = 700;
		x_21 = 900; y_21 = 700;
		x_22 = 750; y_22 = 600;
	}
	if (i == 0 && j == 4)
	{
		x_11 = 900; y_11 = 700;
		x_12 = 750; y_12 = 800;
		x_21 = 900; y_21 = 800;
		x_22 = 750; y_22 = 700;
	}
	if (i == 5 && j == 5)
	{
		x_11 = 1050; y_11 = 200;
		x_12 = 900; y_12 = 300;
		x_21 = 1050; y_21 = 300;
		x_22 = 900; y_22 = 200;
	}
	if (i == 4 && j == 5)
	{
		x_11 = 1050; y_11 = 300;
		x_12 = 900; y_12 = 400;
		x_21 = 1050; y_21 = 400;
		x_22 = 900; y_22 = 300;
	}
	if (i == 3 && j == 5)
	{
		x_11 = 1050; y_11 = 400;
		x_12 = 900; y_12 = 500;
		x_21 = 1050; y_21 = 500;
		x_22 = 900; y_22 = 400;
	}
	if (i == 2 && j == 5)
	{
		x_11 = 1050; y_11 = 500;
		x_12 = 900; y_12 = 600;
		x_21 = 1050; y_21 = 600;
		x_22 = 900; y_22 = 500;
	}
	if (i == 1 && j == 5)
	{
		x_11 = 1050; y_11 = 600;
		x_12 = 900; y_12 = 700;
		x_21 = 1050; y_21 = 700;
		x_22 = 900; y_22 = 600;
	}
	if (i == 0 && j == 5)
	{
		x_11 = 1050; y_11 = 700;
		x_12 = 900; y_12 = 800;
		x_21 = 1050; y_21 = 800;
		x_22 = 900; y_22 = 700;
	}
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(x_11, y_11);
	glVertex2f(x_12, y_12);
	glVertex2f(x_21, y_21);
	glVertex2f(x_22, y_22);
}

void gameApp::drawO(int i, int j)
{
	int r = 40;
	int cx, cy;
	if (i == 5 && j == 0)
	{
		cx = 225;
		cy = 250;
	}
	if (i == 4 && j == 0)
	{
		cx = 225;
		cy = 350;
	}
	if (i == 3 && j == 0)
	{
		cx = 225;
		cy = 450;
	}
	if (i == 2 && j == 0)
	{
		cx = 225;
		cy = 550;
	}
	if (i == 1 && j == 0)
	{
		cx = 225;
		cy = 650;
	}
	if (i == 0 && j == 0)
	{
		cx = 225;
		cy = 750;
	}
	if (i == 5 && j == 1)
	{
		cx = 375;
		cy = 250;
	}
	if (i == 4 && j == 1)
	{
		cx = 375;
		cy = 350;
	}
	if (i == 3 && j == 1)
	{
		cx = 375;
		cy = 450;
	}
	if (i == 2 && j == 1)
	{
		cx = 375;
		cy = 550;
	}
	if (i == 1 && j == 1)
	{
		cx = 375;
		cy = 650;
	}
	if (i == 0 && j == 1)
	{
		cx = 375;
		cy = 750;
	}
	if (i == 5 && j == 2)
	{
		cx = 525;
		cy = 250;
	}
	if (i == 4 && j == 2)
	{
		cx = 525;
		cy = 350;
	}
	if (i == 3 && j == 2)
	{
		cx = 525;
		cy = 450;
	}
	if (i == 2 && j == 2)
	{
		cx = 525;
		cy = 550;
	}
	if (i == 1 && j == 2)
	{
		cx = 525;
		cy = 650;
	}
	if (i == 0 && j == 2)
	{
		cx = 525;
		cy = 750;
	}
	if (i == 5 && j == 3)
	{
		cx = 675;
		cy = 250;
	}
	if (i == 4 && j == 3)
	{
		cx = 675;
		cy = 350;
	}
	if (i == 3 && j == 3)
	{
		cx = 675;
		cy = 450;
	}
	if (i == 2 && j == 3)
	{
		cx = 675;
		cy = 550;
	}
	if (i == 1 && j == 3)
	{
		cx = 675;
		cy = 650;
	}
	if (i == 0 && j == 3)
	{
		cx = 675;
		cy = 750;
	}
	if (i == 5 && j == 4)
	{
		cx = 825;
		cy = 250;
	}
	if (i == 4 && j == 4)
	{
		cx = 825;
		cy = 350;
	}
	if (i == 3 && j == 4)
	{
		cx = 825;
		cy = 450;
	}
	if (i == 2 && j == 4)
	{
		cx = 825;
		cy = 550;
	}
	if (i == 1 && j == 4)
	{
		cx = 825;
		cy = 650;
	}
	if (i == 0 && j == 4)
	{
		cx = 825;
		cy = 750;
	}
	if (i == 5 && j == 5)
	{
		cx = 975;
		cy = 250;
	}
	if (i == 4 && j == 5)
	{
		cx = 975;
		cy = 350;
	}
	if (i == 3 && j == 5)
	{
		cx = 975;
		cy = 450;
	}
	if (i == 2 && j == 5)
	{
		cx = 975;
		cy = 550;
	}
	if (i == 1 && j == 5)
	{
		cx = 975;
		cy = 650;
	}
	if (i == 0 && j == 5)
	{
		cx = 975;
		cy = 750;
	}
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < 360; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(360);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	}
	glEnd();
}

char gameApp::valueMyBoardValue(int i, int j)
{
	char ch;
	ch = myBoard->gameBoard[i][j];
	return ch;
}

bool gameApp::checkBoard(int i, int j)
{
	char ch;
	ch = myBoard->gameBoard[i][j];
	if (ch == 'X' or ch == 'O')
		return true;
	else
		return false;
}

bool gameApp::isMoveLeft()
{
	char ch;
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			ch = myBoard->gameBoard[i][j];
			if (ch == '_')
				return true;
		}
	}
	return false;
}

void gameApp::timerFun(int timerEvent)
{
	static int frameNumber = 0;
	frameNumber++;

	glutPostRedisplay();
	
	if (myApp->retrunToken() == 'X')
	{
		//std::cout << "Human should make a move!";
		myApp->checkWin();
	}

	else if (myApp->retrunToken() == 'O')
	{	
		std::cout << "The computer is going to make a move" << std::endl;
		myApp->bestmove();
		std::cout << "The computer made a move" << std::endl;
		myApp->checkWin();
	}



	glutTimerFunc(15, timerFun, frameNumber);

}

void gameApp::checkWin()
{
	char ch1, ch2, ch3, ch4;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//horizontal
			ch1 = myApp->valueMyBoardValue(i, j);
			ch2 = myApp->valueMyBoardValue(i, j + 1);
			ch3 = myApp->valueMyBoardValue(i, j + 2);
			ch4 = myApp->valueMyBoardValue(i, j + 3);
			if (ch1 == 'X' && ch2 == 'X' && ch3 == 'X' && ch4 == 'X')
			{

				myApp->displayGameWon(ch1);
				//return 10;
			}
			if (ch1 == 'O' && ch2 == 'O' && ch3 == 'O' && ch4 == 'O')
			{

				myApp->displayGameWon(ch1);
				//return -10;
			}
			//diagonal from top to bottom "\"

			if ((i == j && i <= 2) || ((i - j) == 1 && i <= 2) || ((j - i) == 1 && i <= 1) || (i == 2 && j == 0) || (i == 0 && j == 2))
			{
				ch1 = myApp->valueMyBoardValue(i, j);
				ch2 = myApp->valueMyBoardValue(i + 1, j + 1);
				ch3 = myApp->valueMyBoardValue(i + 2, j + 2);
				ch4 = myApp->valueMyBoardValue(i + 3, j + 3);
				if (ch1 == 'X' && ch2 == 'X' && ch3 == 'X' && ch4 == 'X')
				{

					myApp->displayGameWon(ch1);
					//return 10;
				}
				if (ch1 == 'O' && ch2 == 'O' && ch3 == 'O'&& ch4 == 'O')
				{

					myApp->displayGameWon(ch1);
					//return -10;

				}

			}
			//diagonal from bottom to top "/"
			if (((i + j) == 5 && i > 2) || ((i + j) == 6 && i > 3) || ((i + j) == 4 && i >2) || (i == 5 && j == 2) || (i == 3 && j == 0))
			{
				ch1 = myApp->valueMyBoardValue(i, j);
				ch2 = myApp->valueMyBoardValue(i - 1, j + 1);
				ch3 = myApp->valueMyBoardValue(i - 2, j + 2);
				ch4 = myApp->valueMyBoardValue(i - 3, j + 3);
				if (ch1 == 'X' && ch2 == 'X' && ch3 == 'X' && ch4 == 'X')
				{
					myApp->displayGameWon(ch1);
					//return 10;
				}
				if (ch1 == 'O' && ch2 == 'O' && ch3 == 'O' && ch4 == 'O')
				{
					myApp->displayGameWon(ch1);
					//return -10;
				}
			}

		}

	}
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			ch1 = myApp->valueMyBoardValue(i, j);
			ch2 = myApp->valueMyBoardValue(i + 1, j);
			ch3 = myApp->valueMyBoardValue(i + 2, j);
			ch4 = myApp->valueMyBoardValue(i + 3, j);
			if (ch1 == 'X' && ch2 == 'X' && ch3 == 'X' && ch4 == 'X')
			{
				myApp->displayGameWon(ch1);
				//return 10;
			}
			if (ch1 == 'O' && ch2 == 'O' && ch3 == 'O' && ch4 == 'O')
			{
				myApp->displayGameWon(ch1);
				//return -10;
			}
		}
	}

}

void gameApp::displayGameWon(char c)
{
	if (c == 'X')
		MessageBox(NULL, "Game Won by X!", "Info", MB_OK | MB_ICONEXCLAMATION);

	else
		MessageBox(NULL, "Game Won by O!", "Info", MB_OK | MB_ICONEXCLAMATION);
	exit(0);
}

void gameApp::bestmove()
{
	std::cout << "\nComputer has selected the best move." << std::endl;
	//myBoard->gameBoard[3][1] = myBoard->token;
	int moveVal;
	int bestVal = -1000;
	int row, col;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{

			if ((i == 5 && myBoard->gameBoard[i][j] == '_') || ((i < 5) && (myBoard->gameBoard[i][j] == '_') && (myBoard->gameBoard[i + 1][j] != '_')))
				//if(myBoard->gameBoard[i][j] == '_')
			{
				myBoard->gameBoard[i][j] = myBoard->token;
				std::cout << "Going to make my move here! 11" << std::endl;
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						std::cout << myBoard->gameBoard[i][j] << "\t";
					}
					std::cout << std::endl;
				}
				std::cout << std::endl << "new\n";

				moveVal = minimax(0, false);
				std::cout << "moveVal is: " << moveVal;

				myBoard->gameBoard[i][j] = '_';

				//std::cout << "bestVal is: " << bestVal;
				if (moveVal > bestVal)
				{
					row = i;
					col = j;
	
					bestVal = moveVal;
					
				}

			}


		}
	}
	myBoard->gameBoard[row][col] = myBoard->token;

	myApp->updateTurn();

}


int gameApp::evaluate()
{
	int ch1, ch2, ch3, ch4;
	int count_X = 0;
	int count_O = 0;
	int a, b, c, d;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a = 0;
			b = 0;
			c = 0;
			d = 0;
							//horizontal
				ch1 = myApp->valueMyBoardValue(i, j);
				ch2 = myApp->valueMyBoardValue(i, j + 1);
				ch3 = myApp->valueMyBoardValue(i, j + 2);
				ch4 = myApp->valueMyBoardValue(i, j + 3);
				if ((ch1 == 'X' || ch1 == '_') && (ch2 == 'X' || ch2 == '_') && (ch3 == 'X' || ch3 == '_') && (ch4 == 'X' || ch4 == '_') && (ch1 == 'X' || ch2 == 'X' || ch3 == 'X' || ch4 == 'X'))
				{
					if (ch1 == 'X')
					{
						a++;
					}
					if (ch2 == 'X')
					{
						b++;
					}
					if (ch3 == 'X')
					{
						c++;
					}
					if (ch4 == 'X')
					{
						d++;
					}
					if (a + b + c + d > 2)
					{
						count_O--;
					}
					count_X++;
				}
				if ((ch1 == 'O' || ch1 == '_') && (ch2 == 'O' || ch2 == '_') && (ch3 == 'O' || ch3 == '_') && (ch4 == 'O' || ch4 == '_') && (ch1 == 'O' || ch2 == 'O' || ch3 == 'O' || ch4 == 'O'))
				{
					count_O++;
				}
				if (ch1 == ch2 == ch3 == ch4 == 'O')
				{
					return 20;
				}
				if (ch1 == ch2 == ch3 == ch4 == 'X')
				{
					return -20;
				}

				if ((i == j && i <= 2) || ((i - j) == 1 && i <= 2) || ((j - i) == 1 && i <= 1) || (i == 2 && j == 0) || (i == 0 && j == 2))
				{
					ch1 = myApp->valueMyBoardValue(i, j);
					ch2 = myApp->valueMyBoardValue(i + 1, j + 1);
					ch3 = myApp->valueMyBoardValue(i + 2, j + 2);
					ch4 = myApp->valueMyBoardValue(i + 3, j + 3);
					if ((ch1 == 'X' || ch1 == '_') && (ch2 == 'X' || ch2 == '_') && (ch3 == 'X' || ch3 == '_') && (ch4 == 'X' || ch4 == '_') && (ch1 == 'X' || ch2 == 'X' || ch3 == 'X' || ch4 == 'X'))
					{
						if (ch1 == 'X')
						{
							a++;
						}
						if (ch2 == 'X')
						{
							b++;
						}
						if (ch3 == 'X')
						{
							c++;
						}
						if (ch4 == 'X')
						{
							d++;
						}
						if (a + b + c + d > 2)
						{
							count_O--;
						}
						count_X++;
					}
					if ((ch1 == 'O' || ch1 == '_') && (ch2 == 'O' || ch2 == '_') && (ch3 == 'O' || ch3 == '_') && (ch4 == 'O' || ch4 == '_') && (ch1 == 'O' || ch2 == 'O' || ch3 == 'O' || ch4 == 'O'))
					{
						count_O++;

					}

					if (ch1 == ch2 == ch3 == ch4 == 'O')
					{
						return 20;
					}
					if (ch1 == ch2 == ch3 == ch4 == 'X')
					{
						return -20;
					}

				}

				//diagonal from bottom to top "/"
				if (((i + j) == 5 && i > 2) || ((i + j) == 6 && i > 3) || ((i + j) == 4 && i > 2) || (i == 5 && j == 2) || (i == 3 && j == 0))
				{
					ch1 = myApp->valueMyBoardValue(i, j);
					ch2 = myApp->valueMyBoardValue(i - 1, j + 1);
					ch3 = myApp->valueMyBoardValue(i - 2, j + 2);
					ch4 = myApp->valueMyBoardValue(i - 3, j + 3);
					if ((ch1 == 'X' || ch1 == '_') && (ch2 == 'X' || ch2 == '_') && (ch3 == 'X' || ch3 == '_') && (ch4 == 'X' || ch4 == '_') && (ch1 == 'X' || ch2 == 'X' || ch3 == 'X' || ch4 == 'X'))
					{
						if (ch1 == 'X')
						{
							a++;
						}
						if (ch2 == 'X')
						{
							b++;
						}
						if (ch3 == 'X')
						{
							c++;
						}
						if (ch4 == 'X')
						{
							d++;
						}
						if (a + b + c + d > 2)
						{
							count_O--;
						}
						count_X++;

					}
					if ((ch1 == 'O' || ch1 == '_') && (ch2 == 'O' || ch2 == '_') && (ch3 == 'O' || ch3 == '_') && (ch4 == 'O' || ch4 == '_') && (ch1 == 'O' || ch2 == 'O' || ch3 == 'O' || ch4 == 'O'))
					{
						count_O++;
					}
					if (ch1 == ch2 == ch3 == ch4 == 'O')
					{
						return 20;
					}
					if (ch1 == ch2 == ch3 == ch4 == 'X')
					{
						return -20;
					}
				}
			
		}
	}

	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			
				ch1 = myApp->valueMyBoardValue(i, j);
				ch2 = myApp->valueMyBoardValue(i + 1, j);
				ch3 = myApp->valueMyBoardValue(i + 2, j);
				ch4 = myApp->valueMyBoardValue(i + 3, j);
				if ((ch1 == 'X' || ch1 == '_') && (ch2 == 'X' || ch2 == '_') && (ch3 == 'X' || ch3 == '_') && (ch4 == 'X' || ch4 == '_') && (ch1 == 'X' || ch2 == 'X' || ch3 == 'X' || ch4 == 'X'))
				{
					if (ch1 == 'X')
					{
						a++;
					}
					if (ch2 == 'X')
					{
						b++;
					}
					if (ch3 == 'X')
					{
						c++;
					}
					if (ch4 == 'X')
					{
						d++;
					}
					if (a + b + c + d > 2)
					{
						count_O--;
					}
					count_X++;
				}
				if ((ch1 == 'O' || ch1 == '_') && (ch2 == 'O' || ch2 == '_') && (ch3 == 'O' || ch3 == '_') && (ch4 == 'O' || ch4 == '_') && (ch1 == 'O' || ch2 == 'O' || ch3 == 'O' || ch4 == 'O'))
				{
					count_O++;
				}
				if (ch1 == ch2 == ch3 == ch4 == 'O')
				{
					return 20;
				}
				if (ch1 == ch2 == ch3 == ch4 == 'X')
				{
					return -20;
				}
		}
	}
	//std::cout << "Count X is: " << count_X << std::endl;
	//std::cout << "Count O is: " << count_O << std::endl;
	//std::cout << "Returning: " << count_O - count_X << std::endl;
	return count_O-count_X;
}

int gameApp::minimax(int depth, bool isMax)
{
	int score = 0;
	if (depth == -1)
	{
		std::cout << std::endl << "depth is now: "<<depth<<std::endl;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				std::cout << myBoard->gameBoard[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << "new\n";
	}
	//std::cout << "Here!" << std::endl;
	if (depth == 5)
	{
		 score = evaluate();


	}

	if (score > 0)
	{

		return score;
	}
	if (score < 0)
	{

		return score;
	}

	//tie
	if (myApp->isMoveLeft() == false)
		return 0;

	//std::cout << "IsMax is: " << isMax;
	if (isMax && depth <= 5)
	{
		int best = -1000;

		for (int i = 5; i >= 0; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (i == 5)
				{
					if (myBoard->gameBoard[i][j] == '_')
					{
						myBoard->gameBoard[i][j] = opp;
						//myApp->updateTurn();
						
						best = std::max(best, minimax(depth + 1, !isMax));
						//minimax(depth + 1, !isMax);
						myBoard->gameBoard[i][j] = '_';
					}
				}

				if (i < 5)
				{
					if ((myBoard->gameBoard[i][j] == '_') && (myBoard->gameBoard[i + 1][j] != '_'))
					{
						myBoard->gameBoard[i][j] = opp;
						//myApp->updateTurn();

						best = std::max(best, minimax(depth + 1, !isMax));
						//minimax(depth + 1, !isMax);
						myBoard->gameBoard[i][j] = '_';

					}
				}
			}
		}
		//std::cout << "Best: " << best << std::endl;
		return best;
		
	}

	if (!isMax && depth <= 5)
	{
		//std::cout << "Here!";
		int best = 1000;


		for (int i = 5; i >= 0; i--)
		{
			for (int j = 0; j < 6; j++)
			{
				if (i == 5)
				{
					if (myBoard->gameBoard[i][j] == '_')
					{
						myBoard->gameBoard[i][j] = plyr;
						//myApp->updateTurn();

						best = std::min(best, minimax(depth + 1, !isMax));
						//minimax(depth + 1, !isMax);
						myBoard->gameBoard[i][j] = '_';
					}
				}

				if (i < 5)
				{
					if ((myBoard->gameBoard[i][j] == '_') && (myBoard->gameBoard[i + 1][j] != '_'))
					{
						myBoard->gameBoard[i][j] = plyr;
						//myApp->updateTurn();

						best = std::min(best, minimax(depth + 1, !isMax));
						//minimax(depth + 1, !isMax);

						myBoard->gameBoard[i][j] = '_';

					}
				}
			}


		}
		return best;

	}

}