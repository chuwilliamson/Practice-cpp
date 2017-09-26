class Soldier : public Entity
{
public:
	Soldier();
	~Soldier();
	virtual void Attack(Entity & other) override;
	virtual void Defend(int Damage);
};

Soldier::Soldier()
{
	mName = "Commander Sheperd";
	mHealth = 200;
	mArmor = 150;
	mSpeed = 40;
	mDamage = 400;
}

Soldier::~Soldier()
{

}

void Soldier::Attack(Entity & other)
{

	Entity::Attack(other);
}

void Soldier::Defend(int damage)
{
	Entity::Defend(damage);
}