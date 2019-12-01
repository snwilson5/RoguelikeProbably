#pragma once
#include "PanelObject.h"

class Player:public PanelObject
{
private:
	int max_health = 20;
	int current_health = 20;
	int _damage = 1;

public:
		Player();
		Player(int, int);
		void Move(int x, int y);
		void OverridePosition(int x, int y);
		int GetCurrentHealth();
		int GetMaxHealth();
		int GetStrength();
		void ChangeHealth(int amount);
		void IncreaseStrength(int amount);
		void IncreaseMaxHealth(int amount);
};

