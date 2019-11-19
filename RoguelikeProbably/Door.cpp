#include "Door.h"

Door::Door(int x, int y, bool bOpen) :PanelObject(x, y, bOpen ? 'ï' : '?')
{
	_open = bOpen;
}

void Door::OpenDoor()
{
	_open = true;
	_icon = '/';
}
