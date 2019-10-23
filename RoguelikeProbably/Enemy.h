#pragma once
#include <string>
#include "IAutonymousActor.h"
using namespace std;


class Enemy : public IAutonymousActor
{
private:
	string _name;
	char _character;

	int strength;

};

