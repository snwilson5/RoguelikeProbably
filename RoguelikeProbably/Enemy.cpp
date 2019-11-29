#include "Enemy.h"
#include "GameObjectCollections.h"

void Enemy::ActOblivious()//Only attack if player is right there.
{
	GameObjectCollections* gameObjects = GameObjectCollections::GetInstance();
	if (gameObjects->GetDistance(*this, gameObjects->character) <= 1.0)
	{
		int damage = (rand() % _strength) + 1;
		gameObjects->character.ChangeHealth(-damage);
		gameObjects->AddMessage(_name + " did " + to_string(damage) + " to you");
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
	case 1:
		intendedX--;
	case 2:
		intendedY++;
	case 3:
		intendedY--;
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
}

int Enemy::GetCurrentHealth()
{
	return _health;
}

string Enemy::GetName()
{
	return _name;
}


