#include "Map.h"

void Map::RefreshMap()
{
	roundMap = map;
}

int Map::ConvertXYToActualStringPosition(int _x, int _y) const
{
	return (_y* MaxMapWidth + _x * 2);
}

Map::Map(string inMap)
{
	map = inMap;
	RefreshMap();
}

Map::Map()
{
}

Map::CellType Map::GetCellType(int x, int y) const
{
	int actualPosition = Map::ConvertXYToActualStringPosition(x, y);
	return GetCellType(roundMap[actualPosition]);
}

void Map::AddToLocation(char specificCharacter, int x, int y)
{
	if (GetCellType(specificCharacter) > GetCellType(x, y))
	{
		int actualPosition = ConvertXYToActualStringPosition(x, y);
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
	default:
		return Map::floor;
	}
}