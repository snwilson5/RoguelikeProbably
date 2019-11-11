#include "GameObjectCollections.h"

void GameObjectCollections::AddActor(Enemy enemy)
{
	_enemies.push_back(enemy);
}

void GameObjectCollections::AddItem(ItemPanel item)
{
	_items.push_back(item);
}

void GameObjectCollections::RemoveEnemy(Enemy* enemy)
{
}

void GameObjectCollections::RemoveItem(ItemPanel* itemPanel)
{
}

void GameObjectCollections::GiveAllActions()
{
}
