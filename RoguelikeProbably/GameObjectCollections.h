#pragma once
#include <vector>
#include "ItemPanel.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
#include "Door.h"
#include "AreaContainer.h"
#include "GameMaps.cpp"
using namespace std;

//This class manages all current
class GameObjectCollections
{
private:
	vector<Enemy>* _enemies; //Enemies on screen
	vector<ItemPanel>* _items; //Items on screen
	vector<Door>* _doors;
	static GameObjectCollections* instance;
	GameObjectCollections();
	string _messages;
	AreaContainer* areas[3][3];
	int currentAreaX = 0;
	int currentAreaY = 0;
	void LoadMapsAndFirstArea();

public:
	Map* globalMap;
	Player character = Player(6,4);

	static GameObjectCollections* GetInstance()
	{
		if (instance == 0)
			instance = new GameObjectCollections();
		return instance;
	}
	Map::CellType GetCellType(int x, int y);

	void LoadArea(AreaContainer* area);
    
	void AddActor(Enemy enemy);
	void AddItem(ItemPanel item);
	void AddDoor(Door door);

	void RemoveEnemy(Enemy* enemy);
	void RemoveItem(ItemPanel* itemPanel);
	void RemoveDoor(Door* door);

	void PaintToMapAndGiveAllActions(bool bAllowActorsAction);
	void PaintPlayer();

	void AddMessage(string);
	string GetMessages() const;
	void ClearMessages();

	void SwitchMaps(int changeX, int changeY);

	Door* GetDoorAtPosition(int, int);


};

