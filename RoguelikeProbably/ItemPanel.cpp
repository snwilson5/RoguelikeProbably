#include "ItemPanel.h"
#include "GameObjectCollections.h"

ItemPanel::ItemPanel(int xPos, int yPos, char icon, itemType type, int magnitude, string description) :PanelObject(xPos, yPos, icon)
{
	_type = type;
	_magnitude = magnitude;
	_description = description;
}

void ItemPanel::UseItem()
{
	GameObjectCollections* gameObjects = GameObjectCollections::GetInstance();
	gameObjects->AddMessage("You used the " + _description + ".");
	switch (_type)
	{
	case strength:
		gameObjects->character.IncreaseStrength(_magnitude);
		gameObjects->AddMessage("Your strength increased!");
		break;
	case maxHealth:
		gameObjects->character.IncreaseMaxHealth(_magnitude);
		gameObjects->AddMessage("Your maximum health increased!");
	case curHealth:
		gameObjects->character.ChangeHealth(_magnitude);
		gameObjects->AddMessage("It restored " + to_string(_magnitude) + " health");
		break;
	}
}

string ItemPanel::GetDescription()
{
	return _description;
}


