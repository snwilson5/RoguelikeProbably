#include "GameObjectCollections.h"

using namespace std;

GameObjectCollections* GameObjectCollections::instance;
GameObjectCollections::GameObjectCollections()
{
	//TODO
}

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
	//TODO
}

void GameObjectCollections::RemoveItem(ItemPanel* itemPanel)
{
	//TODO
}

//Gives all AI actors their turn. Paints all "tiles" to the screen
void GameObjectCollections::GiveAllActions()
{
	for (int i = 0; i < _enemies.size(); i++)
	{
		//Give the enemies an action. Print their locations
		_enemies[i].TakeAction();
		globalMap.AddToLocation(_enemies[i].GetIcon(), _enemies[i].GetXPos(), _enemies[i].GetYPos());
	}

	for (int i = 0; i < _items.size(); i++)
	{
		globalMap.AddToLocation(_items[i].GetIcon(), _items[i].GetXPos(), _items[i].GetYPos());
	}
}

void GameObjectCollections::PaintPlayer()
{
	globalMap.AddToLocation(character.GetIcon(), character.GetXPos(), character.GetYPos());
}

void GameObjectCollections::AddMessage(string message)
{
	_messages += "  ";//2 spaces between messages for now. May change to new line
	_messages += message;
}

string GameObjectCollections::GetMessages() const
{
	return _messages;
}

void GameObjectCollections::ClearMessages()
{
	_messages = "";
}
