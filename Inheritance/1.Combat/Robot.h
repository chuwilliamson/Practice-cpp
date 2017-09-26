#pragma once
#include "Entity.h"
class Robot : public Entity
{
public:
	Robot();
	~Robot();
	//To attack th other will lose health based on this classes damage
	virtual void Attack(Entity& other) override;
	//To defend we will mitigate damage taken using the mArmor variable
	virtual void Defend(int damage) override;
};
Robot::Robot()
{
	mName = "Zero";
	mHealth = 100000000000;
	mDamage = 100000000000;
	mArmor = 25;
	mSpeed = 100;
}
Robot::~Robot()
{
}
void Robot::Attack(Entity & other)
{
	Entity::Attack(other);
}
void Robot::Defend(int damage)
{	
	Entity::Defend(damage);
}