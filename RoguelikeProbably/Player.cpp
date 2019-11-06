#include "Player.h"

Player::Player():PanelObject(1, 1, '@')
{

}

Player::Player(int x, int y) : PanelObject(x, y, '@')
{
}

void Player::MoveVertically(int iv)
{
	if (iv == 0)
		return;
	//only accepts int for direction
	_yPos += iv >= 0 ? -1 : 1;
}

void Player::MoveHorizontally(int hv)
{
	if (hv == 0)
		return;
	//only accepts int for direction
	_xPos += hv >= 0 ? 1 : -1;
}
