#pragma once
#include <string>
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
	enum CellType {floor, door, item, enemy, player, wall};

private:
	char** map;
public:
	void LoadMap(char**, int lenX, int lenY);
	void GetCellType(int x, int y) const;
	void AddToLocation(CellType type, char specificCharacter, int x, int y);

	string GetMap();

};

