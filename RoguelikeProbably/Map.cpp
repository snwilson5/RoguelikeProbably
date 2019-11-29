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
	x = (pos - y * MaxMapWidth) / 2;
}

Map::Map(string inMap)
{
	map = inMap;
	//RemoveDoorCharactersAndCreateDoorObjects();
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

	case 'C':
		return Map::caveWall;

	case '°':
		return Map::theVoid;

	case '¿':
		return Map::lockedDoor;

	case '?':
		return Map::closedDoor;

	case 'ï':
		return Map::openDoor;

	case 'M':
		return Map::mountain;

	case '>':
		return Map::mapRight;
	case '<':
		return Map::mapLeft;
	case '^':
		return Map::mapUp;
	case 'v':
		return Map::mapDown;

	case '[':
	case ']':
		return Map::bed;

	case 'T':
		return Map::tree;

	case '¥':
		return Map::plant;

	case '|'://Weapon
	case '0'://Potion
		return Map::item;

	case 'g':
	case 'ê':
		return Map::enemy;

	default:
		return Map::floor;
	}
}

vector<Door> Map::RemoveDoorCharactersAndCreateDoorObjects()
{
	vector<Door> doors;
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
			doors.push_back(door);
		}
	}
	return doors;
}

vector<Enemy> Map::RemoveEnemyCharactersAndCreateEnemyObjects()
{
	vector<Enemy> enemies;
	for (int i = 0; i < map.length(); i++)
	{
		CellType currentType = GetCellType(map[i]);
		if (currentType == enemy)
		{
			char enemyCharacter = map[i];
			map[i] = ' ';
			int x = 0;
			int y = 0;
			ConvertStringPositionToXYPosition(i, x, y);
			Enemy* curEnemy = nullptr;
			switch (enemyCharacter)
			{
			case 'g':
				curEnemy = new Enemy(x, y, enemyCharacter, Enemy::oblivious, "Goblin", 2, 5);
				break;
			case 'ê':
				curEnemy = new Enemy(x, y, enemyCharacter, Enemy::oblivious, "Slime", 1, 7);
				break;
			}
			if (curEnemy != nullptr)
			{
				enemies.push_back(*curEnemy);
				delete(curEnemy);
			}
		}
	}
	return enemies;
}
