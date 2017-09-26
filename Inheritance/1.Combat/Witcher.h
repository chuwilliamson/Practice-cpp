#pragma once
#include "Entity.h"
class Witcher : public Entity
{
public:
	Witcher();
	~Witcher();
	//to attack the other will lose health based on this classes damage
	virtual void Attack(Entity& other) override;
	//to defend we will mitigate damage taken using the mArmor variable
	virtual void Defend(int damage) override;

};


Witcher::Witcher()
{
	mName = "Geralt";
	mHealth = 100;
	mArmor = 200;
	mSpeed = 10;
	mDamage = 9000;
}

Witcher::~Witcher() {}

void Witcher::Attack(Entity & other)
{	
	Entity::Attack(other);
}

void Witcher::Defend(int damage) 
{
	Entity::Defend(damage);
	//impregnableaka::lennox lewis not pregnatable
		mHealth = 90000;
}

