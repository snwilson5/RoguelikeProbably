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

public://These are unique in that they are statically accessable

	enum CellType {floor, openDoor, item, enemy, player, closedDoor, wall, theVoid};
	static const int MaxMapLength = 20;
	//This seems to be an oddity. Adding an extra space so that the map screen height and width "match"
	static const int MaxMapWidth = 60;//Extra character for new line character \n 

private:
	string map;//Shoot for 30x20
	string lastRoundMap;
	string roundMap;

	int ConvertXYToStringPosition(int,int) const;
	void ConvertStringPositionToXYPosition(int, int&, int&);
	

	void RemoveDoorCharactersAndCreateDoorObjects();
	
public:
	Map(string);
	Map();
	void AddToLocation(char specificCharacter, int x, int y);
	string GetMapOutput();
	CellType GetCellType(int x, int y) const;
	CellType GetCellType(char) const;
	void RefreshMap();
};

