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
	string map[20];//Shoot for 30x20
public:
	Map(string[20]);
	void GetCellType(int x, int y) const;
	void AddToLocation(CellType type, char specificCharacter, int x, int y);
	string GetMapOutput();

};

