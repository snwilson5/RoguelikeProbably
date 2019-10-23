#pragma once
//This is an interface for ANYTHING that takes actions during the round excluding the character.
//The is the core for all AI functionality
class IAutonymousActor
{
public:
	virtual void TakeAction() = 0;
};

