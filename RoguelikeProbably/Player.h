#pragma once
#include "PanelObject.h"

class Player:public PanelObject
{
public:
		Player();
		Player(int, int);
		void Move(int x, int y);
		void OverridePosition(int x, int y);
};

