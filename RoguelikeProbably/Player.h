#pragma once
#include "PanelObject.h";

class Player:public PanelObject
{
public:
		Player();
		Player(int, int);
		void MoveVertically(int);
		void MoveHorizontally(int);

};

