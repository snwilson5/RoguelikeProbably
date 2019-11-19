#pragma once
#include "PanelObject.h"
class Door : public PanelObject
{
public:
	Door(int x, int y, bool bOpen);
	void OpenDoor();
private:
	bool _open;
};

