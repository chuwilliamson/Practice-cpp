class Spartan : public Entity
{
public:
	Spartan();
	~Spartan();
	//to attack the other will lose health based on this classes damage
	virtual void Attack(Entity& other) override;
	//to defend we will mitigate damage taken using the mArmor variable
	virtual void Defend(int damage) override;
};


Spartan::Spartan()
{
	mName = "MasterChief ";
	mHealth = 300;
	mArmor = 500;
	mSpeed = 15;
	mDamage = 9001;
}

Spartan::~Spartan()
{
}

void Spartan::Attack(Entity & other)
{
	Entity::Attack(other);
}
void Spartan::Defend(int damage)
{
	Entity::Defend(damage);
}