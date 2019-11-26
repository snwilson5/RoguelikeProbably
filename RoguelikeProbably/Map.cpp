#include "Map.h"
#include "Door.h"
#include "GameObjectCollections.h"

void Map::RefreshMap()
{
	roundMap = map;
}

int Map::ConvertXYToStringPosition(int _x, int _y) const
{
	return (_y * MaxMapWidth + _x * 2);
}

void Map::ConvertStringPositionToXYPosition(int pos, int& x, int& y)
{
	y = pos / MaxMapWidth;
	x = (pos - y* MaxMapWidth) / 2;
}

Map::Map(string inMap)
{
	map = inMap;
	RemoveDoorCharactersAndCreateDoorObjects();
	RefreshMap();
}

Map::Map()
{
}

Map::CellType Map::GetCellType(int x, int y) const
{
	int actualPosition = Map::ConvertXYToStringPosition(x, y);
	char c = roundMap[actualPosition];
	return GetCellType(roundMap[actualPosition]);
}

void Map::AddToLocation(char specificCharacter, int x, int y)
{
	if (GetCellType(specificCharacter) > GetCellType(x, y))
	{
		int actualPosition = ConvertXYToStringPosition(x, y);
		roundMap[actualPosition] = specificCharacter;
	}
}

string Map::GetMapOutput()
{
	return roundMap;
}

Map::CellType Map::GetCellType(char c) const
{
	switch (c)
	{
	case '@':
		return Map::player;
	case '#':
		return Map::wall;
	case '°':
		return Map::theVoid;
	case '?':
		return Map::closedDoor;
	case 'ï':
		return Map::openDoor;
	default:
		return Map::floor;
	}
}

void Map::RemoveDoorCharactersAndCreateDoorObjects()
{
	for (int i = 0; i < map.length(); i++)
	{
		CellType currentType = GetCellType(map[i]);
		if (currentType == closedDoor || currentType == openDoor)
		{
			map[i] = ' ';
			int x = 0;
			int y = 0;
			ConvertStringPositionToXYPosition(i, x, y);
			Door door(x, y, currentType == openDoor);
			GameObjectCollections::GetInstance()->AddDoor(door);
		}
	}
}