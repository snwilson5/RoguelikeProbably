#pragma once
#include "Door.h"
#include <string>
#include <vector>
#include "Enemy.h"
using namespace std;


//This Class is the container for the map ex:
/*
#####
#@  #
#   #
#   #
#####
*/
class Map
{

public://These are unique in that they are statically accessable

	enum CellType { floor, plant, openDoor, item, enemy, mapUp, mapDown, mapLeft, mapRight, gameComplete,  player, closedDoor, lockedDoor, bed, tree, wall, caveWall, mountain, theVoid };
	static const int MaxMapLength = 20;
	//This seems to be an oddity. Adding an extra space so that the map screen height and width "match"
	static const int MaxMapWidth = 60;//Extra character for new line character \n 

private:
	string map;//Shoot for 30x20
	string lastRoundMap;
	string roundMap;

	int ConvertXYToStringPosition(int, int) const;
	void ConvertStringPositionToXYPosition(int, int&, int&);




public:
	Map(string);
	Map();
	void AddToLocation(char specificCharacter, int x, int y);
	string GetMapOutput();
	CellType GetCellType(int x, int y) const;
	CellType GetCellType(char) const;
	void RefreshMap();
	vector<Door> RemoveDoorCharactersAndCreateDoorObjects();
	vector<Enemy> RemoveEnemyCharactersAndCreateEnemyObjects();
};

