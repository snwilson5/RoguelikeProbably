#include "PanelObject.h"

PanelObject::PanelObject(int xPos, int yPos, char icon)
{
	_xPos = xPos;
    _yPos = yPos;
	_icon = icon;
}

char PanelObject::GetIcon()
{
	return _icon;
}

int PanelObject::GetXPos()
{
	return _xPos;
}

int PanelObject::GetYPos()
{
	return _yPos;
}
