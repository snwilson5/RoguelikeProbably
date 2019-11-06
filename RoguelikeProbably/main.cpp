#include <iostream>
#include <windows.h>
#include <winuser.h>
#include "Map.h"
#include "TestMaps.cpp"
#include "Player.h"


using namespace std;

void KeyDetection();
void Repaint();
void PlayerArrowsPressed(int, int);
void CharacterPrint();

static Map globalMap = Map(TestMaps::testMap1());;
static Player character;

int main()
{
	//CharacterPrint();
	globalMap = Map(TestMaps::testMap1());
	globalMap.AddToLocation(character.GetIcon(), character.GetXPos(), character.GetYPos());

	while (true)
	{
		Repaint();
		KeyDetection();//Player Action
	}
}


void KeyDetection()
{
	//This is essentially a stop point. The game will not continue until the user chooses an action

	bool bPressed = false;
	while (!bPressed)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			cout << "up" << endl;
			PlayerArrowsPressed(0, 1);
			bPressed = true;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			cout << "down" << endl;
			PlayerArrowsPressed(0, -1);
			bPressed = true;
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			cout << "left" << endl;
			PlayerArrowsPressed(-1, 0);
			bPressed = true;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			cout << "right" << endl;
			PlayerArrowsPressed(1, 0);
			bPressed = true;
		}
	}
	globalMap.AddToLocation(character.GetIcon(), character.GetXPos(), character.GetYPos());
}

void Repaint()
{
	system("cls");
	cout << globalMap.GetMapOutput();
	globalMap.RefreshMap();
}


void PlayerArrowsPressed(int x, int y)
{
	character.MoveHorizontally(x);
	character.MoveVertically(y);
}

//Prints Every Ascii Character
void CharacterPrint()
{
	for (int i = 0; i < 256; i++)
	{
		cout << char(i) << " - "<< i << endl;
	}
}