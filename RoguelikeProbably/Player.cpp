#include "Player.h"

Player::Player() :PanelObject(1, 1, '@')
{

}

Player::Player(int x, int y) : PanelObject(x, y, '@')
{
}

void Player::Move(int x, int y)
{
	if (y != 0)
		_yPos += y >= 0 ? -1 : 1;
	if (x != 0)
		_xPos += x >= 0 ? 1 : -1;
}

void Player::OverridePosition(int x, int y)
{
	_xPos = x;
	_yPos = y;
}

int Player::GetCurrentHealth()
{
	return current_health;
}

int Player::GetMaxHealth()
{
	return max_health;
}

int Player::GetStrength()
{
	return _damage;
}

void Player::ChangeHealth(int amount)
{
	current_health += amount;
	if (current_health > max_health)
		current_health = max_health;
	if (current_health < 0)
		current_health = 0;
}
