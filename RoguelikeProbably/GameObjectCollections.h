#pragma once
#include <vector>
#include "ItemPanel.h"
#include "Enemy.h"
#include "Map.h"
#include "Player.h"
using namespace std;

//This class manages all current
class GameObjectCollections
{
private:
	vector<Enemy> _enemies; //Enemies on screen
	vector<ItemPanel> _items; //Items on screen
	static GameObjectCollections* instance;
	GameObjectCollections();
	string _messages;

public:
	Map globalMap;
	Player character = Player(2,12);

	static GameObjectCollections* GetInstance()
	{
		if (instance == 0)
			instance = new GameObjectCollections();
		return instance;
	}
    
	void AddActor(Enemy enemy);
	void AddItem(ItemPanel item);

	void RemoveEnemy(Enemy* enemy);
	void RemoveItem(ItemPanel* itemPanel);

	void GiveAllActions();
	void PaintPlayer();

	void AddMessage(string);
	string GetMessages() const;
	void ClearMessages();
};

