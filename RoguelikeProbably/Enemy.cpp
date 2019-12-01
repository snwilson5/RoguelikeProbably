#include "Enemy.h"
#include "GameObjectCollections.h"

void Enemy::ActOblivious()//Only attack if player is right there.
{
	GameObjectCollections* gameObjects = GameObjectCollections::GetInstance();
	if (gameObjects->GetDistance(*this, gameObjects->character) <= 1.0)
	{
		int damage = (rand() % _strength) + 1;
		gameObjects->character.ChangeHealth(-damage);
		gameObjects->AddMessage(_name + " did " + to_string(damage) + " damage to you");
	}
	else
		MoveRandom();
}

void Enemy::MoveRandom()
{
	GameObjectCollections* gameObjects = GameObjectCollections::GetInstance();
	int moveDirection = rand() % 4;
	int intendedX = _xPos;
	int intendedY = _yPos;
	switch (moveDirection)
	{
	case 0:
		intendedX++;
		break;
	case 1:
		intendedX--;
		break;
	case 2:
		intendedY++;
		break;
	case 3:
		intendedY--;
		break;
	}
	Map::CellType cell = gameObjects->GetCellType(intendedX, intendedY);
	if ((int)cell < int(Map::enemy))//If it's allowed to occupy this space.
	{
		_xPos = intendedX;
		_yPos = intendedY;
	}
}

Enemy::Enemy(int xPos, int yPos, char icon, AIType type, string name, int strength, int health) : PanelObject(xPos, yPos, icon)
{
	_type = type;
	_name = name;
	_strength = strength;
	_health = health;
}

void Enemy::TakeAction()
{
	switch (_type)
	{
	case passive:
	case aggressive:
	case oblivious:
		ActOblivious();
		break;
	}
}

void Enemy::ChangeHealth(int amount)
{
	_health += amount;
	if (_health <= 0)//I died. See if I drop a potion
	{
		if (rand() % 2)//0 or 1
		{
			GameObjectCollections* gameObjects = GameObjectCollections::GetInstance();
			ItemPanel potionDrop = ItemPanel(GetXPos(), GetYPos(), '0', ItemPanel::curHealth, 10, "Health Potion");
			gameObjects->AddItem(potionDrop);
		}
	}
}

int Enemy::GetCurrentHealth()
{
	return _health;
}

string Enemy::GetName()
{
	return _name;
}


