#pragma once
#include <string>
#include "IAutonymousActor.h"
#include "PanelObject.h";

using namespace std;


class Enemy : public IAutonymousActor, public PanelObject
{
private:
	string _name;
	char _icon;

	int strength;
	int constitution;
	int dexterity;

public:
	Enemy(int xPos, int yPos, char icon);

	void TakeAction();

};

