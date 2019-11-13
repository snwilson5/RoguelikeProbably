#pragma once
#include <iostream>
#include <windows.h>
#include <winuser.h>
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


static GameObjectCollections* gameObjects = GameObjectCollections::GetInstance();

int main()
{
	//CharacterPrint();
	//char c176 = (char)176;
	//return 0;
	gameObjects->globalMap = Map(TestMaps::testMap2());
	gameObjects->PaintPlayer();

	while (true)
	{
		Repaint();
		KeyDetection();//Player Action
		gameObjects->GiveAllActions();//Everything Else
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
	gameObjects->PaintPlayer();
}

void Repaint()
{
	system("cls");
	cout << gameObjects->globalMap.GetMapOutput();
	//cout<<character.getCharacteristicsOutput()<<endl;
	cout << gameObjects->GetMessages();
	gameObjects->globalMap.RefreshMap();
	gameObjects->ClearMessages();
	Sleep(100);//This was processing too quickly and detecting the same key press multiple times. Slowed it for 1/10th of a second
}

void PlayerArrowsPressed(int x, int y)
{
	Map::CellType type = gameObjects->globalMap.GetCellType(gameObjects->character.GetXPos() + x, gameObjects->character.GetYPos() - y);
	//floor, door, item, enemy, player, wall
	switch (type)
	{
	case Map::floor:
		//Move
		gameObjects->character.Move(x, y);
		break;

	case Map::door:
		//Move for now. This will be 2 turns. Open the door and then go through the door.
		gameObjects->character.Move(x, y);
		break;

	case Map::item:
		//move
		gameObjects->character.Move(x, y);
		break;

	case Map::enemy:
		//Attack Here
		break;

	case Map::player:
		//What?
		break;

	case Map::wall:
		gameObjects->AddMessage("A Wall blocks your path.\n");
		break;

	case Map::theVoid:
		gameObjects->AddMessage("You would fall into an endless void.\n");
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