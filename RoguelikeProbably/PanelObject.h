#pragma once
//This Base class is used for any object that contains a position on the map
class PanelObject
{
protected:
	int _xPos;
	int _yPos;
	char _icon;
public:
	PanelObject(int xPos, int yPos, char icon);
	char GetIcon();
	int GetXPos();
	int GetYPos();
};

