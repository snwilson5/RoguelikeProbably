#include <iostream>
#include <windows.h>
#include <winuser.h>
#include "Map.h"
#include "TestMaps.cpp"
#include "Player.h"
#include "GameObjectCollections.h"
using namespace std;

#pragma region Method stubs

void KeyDetection();
void Repaint();
void PlayerArrowsPressed(int, int);
void CharacterPrint();
#pragma endregion

static Map globalMap = Map(TestMaps::testMap1());
static string messages = "";

static Player character(2,12);
static GameObjectCollections gameObjects;

int main()
{
	//CharacterPrint();
	//char c176 = (char)176;
	//return 0;
	globalMap = Map(TestMaps::testMap2());
	globalMap.AddToLocation(character.GetIcon(), character.GetXPos(), character.GetYPos());

	while (true)
	{
		Repaint();
		KeyDetection();//Player Action
		gameObjects.GiveAllActions();
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
			//cout << "up" << endl;
			PlayerArrowsPressed(0, 1);
			bPressed = true;
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			//cout << "down" << endl;
			PlayerArrowsPressed(0, -1);
			bPressed = true;
		}
		else if (GetAsyncKeyState(VK_LEFT))
		{
			//cout << "left" << endl;
			PlayerArrowsPressed(-1, 0);
			bPressed = true;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			//cout << "right" << endl;
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
	//cout<<character.getCharacteristicsOutput()<<endl;
	cout << messages;
	globalMap.RefreshMap();
	messages = "";
	Sleep(100);//This was processing too quickly and detecting the same key press multiple times. Slowed it for 1/10th of a second
}

void PlayerArrowsPressed(int x, int y)
{
	Map::CellType type = globalMap.GetCellType(character.GetXPos() + x, character.GetYPos() - y);
	//floor, door, item, enemy, player, wall
	switch (type)
	{
	case Map::floor:
		//Move
		character.Move(x, y);
		break;

	case Map::door:
		//Move for now. This will be 2 turns. Open the door and then go through the door.
		character.Move(x, y);
		break;

	case Map::item:
		//move
		character.Move(x, y);
		break;

	case Map::enemy:
		//Attack Here
		break;

	case Map::player:
		//What?
		break;

	case Map::wall:
		messages += "A Wall blocks your path.\n";
		break;

	case Map::theVoid:
		messages += "You would fall into an endless void.\n";
		break;
	}
}

//Prints Every Ascii Character
void CharacterPrint()
{
	for (int i = 0; i < 256; i++)
	{
		cout << char(i) << " - " << i << endl;
	}
}