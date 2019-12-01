#pragma once
#include "PanelObject.h"
#include <string>

using namespace std;
class ItemPanel :public PanelObject
{
public:
	enum itemType { strength, curHealth, maxHealth };
private:
	itemType _type;
	int _magnitude;
	string _description;
public:
	ItemPanel(int xPos, int yPos, char icon, itemType type, int magnitude, string description);
	void UseItem();
	string GetDescription();
};

