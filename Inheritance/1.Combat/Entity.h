#pragma once

class Entity
{
public:
	Entity();
	~Entity();
	virtual void Attack(Entity& other) = 0;
	virtual void Defend(int damage) = 0;
	void DisplayInfo();
	int mDamage;
	int mHealth;
	int mSpeed;
	int mArmor;
	std::string mName;
};

Entity::Entity() : mDamage(0), mHealth(0), mSpeed(0), mArmor(0), mName("<name>")
{}

Entity::~Entity()
{}

void Entity::DisplayInfo()
{
	std::cout << "====" << mName << "=====" << std::endl;
	std::cout << "current health is " << mHealth << std::endl;
	std::cout << "current armor is " << mArmor << std::endl;
	std::cout << "current speed is " << mSpeed << std::endl;
	std::cout << "current damage is " << mDamage << std::endl;
	std::cout << "===============================" << std::endl<<std::endl;
}

///attack an Entity
void Entity::Attack(Entity& other)
{
	other.Defend(mDamage);
}

void Entity::Defend(int damage)
{
	int damageTotal = damage - mArmor;
	mHealth = mHealth - damageTotal;

}

