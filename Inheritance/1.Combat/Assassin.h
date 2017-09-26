#pragma once
#include "Entity.h"


class Assassin : public Entity
{
public:
	Assassin();
	~Assassin();
	//To attack the other will lose health based on this classes damage
	virtual void Attack(Entity& other) override;
	//To defend we will mitigate damage taken away using the mArmor variable
	virtual void Defend(int damage) override;
};

Assassin::Assassin()
{
	mName = "Ezio";
	mHealth = 10;
	mArmor = 10;
	mSpeed = 50;
	mDamage = 90000000001;
}

Assassin::~Assassin()
{
}

void Assassin::Attack(Entity & other)
{
	Entity::Attack(other);
}

void Assassin::Defend(int damage)
{
	Entity::Defend(damage);
}