#pragma once

#include "Entity.h"

class Ninja : public Entity
{
public:
	Ninja();
	~Ninja();
	// to attack other will lose health based on damage.
	//to defend mitigate damage taken using mArmor varaition.
	void Attack(Entity& other)override;
	void Defend(int damage)override;

};

Ninja::Ninja()
{
	mName = "Scorpion";
	mHealth = 100000000;
	mDamage = 2000000;
	mArmor = 200000;
	mSpeed = 5000;
}

Ninja::~Ninja()
{
}


void Ninja::Attack(Entity& other)
{
	Entity::Attack(other);
}
void Ninja::Defend(int damage)
{
	Entity::Defend(damage);
}

