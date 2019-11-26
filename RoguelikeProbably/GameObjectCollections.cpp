#include "GameObjectCollections.h"

using namespace std;

GameObjectCollections* GameObjectCollections::instance;
GameObjectCollections::GameObjectCollections()
{
	//TODO
}

Map::CellType GameObjectCollections::GetCellType(int x, int y)
{
	Map::CellType highestType = globalMap.GetCellType(x, y);//<- Get the default

	for (int i = 0; i < _enemies.size(); i++)
	{
		if (x == _enemies[i].GetXPos() && y == _enemies[i].GetYPos())
		{
			Map::CellType tempType = globalMap.GetCellType(_enemies[i].GetIcon());
			if ((int)highestType < (int)tempType)
				highestType = tempType;
		}
	}

	for (int i = 0; i < _items.size(); i++)
	{
		if (x == _items[i].GetXPos() && y == _items[i].GetYPos())
		{
			Map::CellType tempType = globalMap.GetCellType(_items[i].GetIcon());
			if ((int)highestType < (int)tempType)
				highestType = tempType;
		}
	}

	for (int i = 0; i < _doors.size(); i++)
	{
		if (x == _doors[i].GetXPos() && y == _doors[i].GetYPos())
		{
			Map::CellType tempType = globalMap.GetCellType(_doors[i].GetIcon());
			if ((int)highestType < (int)tempType)
				highestType = tempType;
		}
	}
	return highestType;
}

void GameObjectCollections::AddActor(Enemy enemy)
{
	_enemies.push_back(enemy);
}

void GameObjectCollections::AddItem(ItemPanel item)
{
	_items.push_back(item);
}

void GameObjectCollections::AddDoor(Door door)
{
	_doors.push_back(door);
}

void GameObjectCollections::RemoveEnemy(Enemy* enemy)
{
	//TODO
}

void GameObjectCollections::RemoveItem(ItemPanel* itemPanel)
{
	//TODO
}

void GameObjectCollections::RemoveDoor(Door* door)
{
}

//Gives all AI actors their turn. Paints all "tiles" to the screen
void GameObjectCollections::GiveAllActions()
{
	for (int i = 0; i < _enemies.size(); i++)
	{
		//Give the enemies an action. Print their locations
		_enemies[i].TakeAction();
		globalMap.AddToLocation(_enemies[i].GetIcon(), _enemies[i].GetXPos(), _enemies[i].GetYPos());
	}

	for (int i = 0; i < _items.size(); i++)
	{
		globalMap.AddToLocation(_items[i].GetIcon(), _items[i].GetXPos(), _items[i].GetYPos());
	}

	for (int i = 0; i < _doors.size(); i++)
	{
		globalMap.AddToLocation(_doors[i].GetIcon(), _doors[i].GetXPos(), _doors[i].GetYPos());
	}
}

void GameObjectCollections::PaintPlayer()
{
	globalMap.AddToLocation(character.GetIcon(), character.GetXPos(), character.GetYPos());
}

void GameObjectCollections::AddMessage(string message)
{
	_messages += "  ";//2 spaces between messages for now. May change to new line
	_messages += message;
}

string GameObjectCollections::GetMessages() const
{
	return _messages;
}

void GameObjectCollections::ClearMessages()
{
	_messages = "";
}

Door* GameObjectCollections::GetDoorAtPosition(int x, int y)
{
	for (int i = 0; i < _doors.size(); i++)
	{
		if (_doors[i].GetXPos() == x && _doors[i].GetYPos() == y)
			return &_doors[i];
	}
	return nullptr;
}



//sounded fun messing around with generics, but i might just change this to seperate Get Methods.
//template<class myType> myType* GameObjectCollections::GetObjectAtPosition(int x, int y)
//{
//	if (myType == Door)
//	{
//		for (int i = 0; i < _doors.size(); i++)
//		{
//			if (_doors[i].GetXPos() == x && _doors[i].GetYPos() == y)
//				return _doors[i];
//		}
//	}
//
//	return nullptr;
//}
