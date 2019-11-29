#include "AreaContainer.h"

AreaContainer::AreaContainer(string map)
{
	_map = map;
	_doors = _map.RemoveDoorCharactersAndCreateDoorObjects();
	_enemies = _map.RemoveEnemyCharactersAndCreateEnemyObjects();
}

Map* AreaContainer::GetMap()
{
	return &_map;
}

vector<Enemy>* AreaContainer::GetEnemies()
{
	return &_enemies;
}

vector<ItemPanel>* AreaContainer::GetItems()
{
	return &_items;
}

vector<Door>* AreaContainer::GetDoors()
{
	return &_doors;
}
