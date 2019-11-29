#pragma once
#include <string>
#include "IAutonymousActor.h"
#include "PanelObject.h"

using namespace std;


class Enemy : public IAutonymousActor, public PanelObject
{
public:
	enum AIType{passive, oblivious, aggressive};
private:
	string _name;
	AIType _type;

	int _strength;
	int _health;
	//int dexterity;

	void ActOblivious();
	void MoveRandom();

public:
	Enemy(int xPos, int yPos, char icon, AIType type, string name, int strength, int health);

	void TakeAction();
	void ChangeHealth(int amount);
	int GetCurrentHealth();
	string GetName();

};

