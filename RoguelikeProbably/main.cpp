#pragma once
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include "GameMaps.cpp"
#include "Player.h"
#include "GameObjectCollections.h"
using namespace std;

//Created by Stevan Wilson
/* Copyright (c) 2019 Stevan Wilson */

#pragma region Method stubs
void KeyDetection();
void Repaint();
void PlayerArrowsPressed(int, int);
void PlayerUsePressed();
void CharacterPrint();
#pragma endregion


static GameObjectCollections* gameObjects = GameObjectCollections::GetInstance();
int numberOfTurns = 0;

int main()
{
	//CharacterPrint();
	//char c = (char)232;
	//char c = '';
	//return 0;
	//gameObjects->globalMap = &Map(GameMaps::Map_0_0());
	//AreaContainer area1(GameMaps::Map_0_0());
	//gameObjects->LoadArea(&area1);
	gameObjects->AddMessage("Welcome to ASCII Warrior.");
	gameObjects->AddMessage("You have recieved word that your king is trapped in his throne room by two dread knights. You must rescue him.");
	gameObjects->PaintToMapAndGiveAllActions(false);
	gameObjects->PaintPlayer();

	while (true)
	{
		Repaint();
		if (gameObjects->character.GetCurrentHealth() <= 0)
		{
			cout << endl << endl << endl << "Game Over! Please play again." << endl;
			exit(EXIT_SUCCESS);
		}
		KeyDetection();//Player Action
		gameObjects->PaintToMapAndGiveAllActions(true);//Everything Else
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
		else if (GetAsyncKeyState(VK_SPACE))
		{
			gameObjects->AddMessage("You wait a turn");
			bPressed = true;
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
			PlayerUsePressed();
			bPressed = true;
		}
	}
	gameObjects->PaintPlayer();
}

void Repaint()
{
	system("cls");
	cout << gameObjects->globalMap->GetMapOutput();
	cout << "Turns: " << numberOfTurns++
		<< "   Health: " << gameObjects->character.GetCurrentHealth() << "/" << gameObjects->character.GetMaxHealth()
		<< "   Strength: " << gameObjects->character.GetStrength() << endl;
	cout << gameObjects->GetMessages();
	gameObjects->globalMap->RefreshMap();
	gameObjects->ClearMessages();
	Sleep(100);//This was processing too quickly and detecting the same key press multiple times. Slowed it for 1/10th of a second
}

void PlayerArrowsPressed(int x, int y)
{
	int intendedX = gameObjects->character.GetXPos() + x;
	int intendedY = gameObjects->character.GetYPos() - y;
	Map::CellType type = gameObjects->GetCellType(intendedX, intendedY);
	Door* targetDoor = nullptr;//Must be declared outside of the case.
	Enemy* enemy = nullptr;
	ItemPanel* item = nullptr;
	//floor, door, item, enemy, player, wall
	switch (type)//Decides what happens depending on the type of tile
	{
	case Map::floor:
	case Map::openDoor:
	case Map::plant:
		//Move
		gameObjects->character.Move(x, y);
		break;

	case Map::closedDoor:
		//Open the door
		targetDoor = gameObjects->GetDoorAtPosition(intendedX, intendedY);
		if (targetDoor == nullptr)//<- What?
			gameObjects->character.Move(x, y);
		else
		{
			targetDoor->OpenDoor();
			gameObjects->AddMessage("You opened the door.");
		}
		break;

	case Map::lockedDoor:
		gameObjects->AddMessage("That door is locked.");
		break;

	case Map::item:
		item = gameObjects->GetItemAtPosition(intendedX, intendedY);
		gameObjects->character.Move(x, y);
		gameObjects->AddMessage("You see an " + item->GetDescription() + ".");
		break;

	case Map::mapUp:
		gameObjects->SwitchMaps(0, -1);
		break;

	case Map::mapDown:
		gameObjects->SwitchMaps(0, 1);
		break;

	case Map::mapLeft:
		gameObjects->SwitchMaps(-1, 0);
		break;

	case Map::mapRight:
		gameObjects->SwitchMaps(1, 0);
		break;

	case Map::enemy:
		enemy = gameObjects->GetEnemyAtPosition(intendedX, intendedY);
		enemy->ChangeHealth(-gameObjects->character.GetStrength());
		gameObjects->AddMessage("You did " + to_string(gameObjects->character.GetStrength()) + " damage to the " + enemy->GetName() + ".");
		if (enemy->GetCurrentHealth() <= 0)
		{
			gameObjects->AddMessage("You killed the " + enemy->GetName());
			gameObjects->RemoveEnemy(enemy);
		}
		break;

	case Map::player:
		//What?
		break;

	case Map::bed:
		gameObjects->AddMessage("You see your bed.\n");
		break;

	case Map::tree:
		gameObjects->AddMessage("There's a tree in your way.\n");
		break;

	case Map::wall:
		gameObjects->AddMessage("A Wall blocks your path.\n");
		break;

	case Map::caveWall:
		gameObjects->AddMessage("You see the wall of a cave. It's slightly damp.\n");
		break;

	case Map::theVoid:
		gameObjects->AddMessage("You would fall into an endless void.\n");
		break;

	case Map::mountain:
		gameObjects->AddMessage("These mountains are impassable.\n");
		break;

	case Map::gameComplete:
		if (gameObjects->AreThereEnemiesOnThisMap())
		{
			gameObjects->AddMessage("The dread knights must be defeated before continuing.");
			break;
		}
		cout << endl << endl << endl << "You won!!" << endl;
		cout << "Thank you for playing!" << endl;
		cout << "Written by Stevan Wilson." << endl;
		exit(EXIT_SUCCESS);
		break;
	}
}

void PlayerUsePressed()
{
	int x = gameObjects->character.GetXPos();
	int y = gameObjects->character.GetYPos();
	Map::CellType type = gameObjects->GetCellType(x, y);
	ItemPanel* item = nullptr;
	switch (type)
	{
	case Map::item:
		item = gameObjects->GetItemAtPosition(x, y);
		if (item != nullptr)
		{
			item->UseItem();
			gameObjects->RemoveItem(item);
		}
		break;

	case Map::plant:
		gameObjects->AddMessage("You see a plant.");
		break;

	case Map::openDoor:
		gameObjects->AddMessage("You are in an open doorway.");
		break;

	default:
		gameObjects->AddMessage("You see nothing of interest.");
		break;
	}
}


//Prints Every Ascii Character (Debug purposes)
void CharacterPrint()
{
	for (int i = 0; i < 256; i++)
	{
		cout << char(i) << " - " << i << endl;
	}
}