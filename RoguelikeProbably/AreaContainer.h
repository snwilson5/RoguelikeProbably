#pragma once
#include "Map.h"
#include "Enemy.h"
#include "ItemPanel.h"
#include "Door.h"
#include <vector>

using namespace std;

class AreaContainer
{
private:
	Map _map;
	vector<Enemy> _enemies; //Enemies on screen
	vector<ItemPanel> _items; //Items on screen
	vector<Door> _doors;

public:
	AreaContainer(string map);

	Map* GetMap();
	vector<Enemy>* GetEnemies();
	vector<ItemPanel>* GetItems();
	vector<Door>* GetDoors();
};

