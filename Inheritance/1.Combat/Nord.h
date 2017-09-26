#pragma once
#include<iostream>
#include"Entity.h"
class Nord : public Entity
{
public:
	Nord();
	~Nord();
	//To attack the other will ose health based on this class's damage.
	virtual void Attack(Entity& other) override;
	//To defend we will mitigate damge taken using the mArmor variable.
	virtual void Defend(int damage) override;
};
Nord::Nord()
{
	mName = "Ulfric";
	mHealth = 300;
	mArmor = 35;
	mSpeed = 420;
	mDamage;
}

Nord::~Nord()
{
}

void Nord::Attack(Entity & other)
{
	Entity::Attack(other);
}

void Nord::Defend(int damage)
{
	Entity::Defend(damage);
}