/*Entity class
*-Ninja
-Ryu
variable Scorpion
-Spartan
-Robot
-Nord
-Dragon
-Witcher
*/

#include "includes.h"


int main()
{
	int NUMPARTICIPANTS = 7;
	Entity** participants = new Entity*[NUMPARTICIPANTS];

	participants[0] = new Witcher();
	participants[1] = new Spartan();
	participants[2] = new Ninja();
	participants[3] = new Assassin();
	participants[4] = new Soldier();
	participants[5] = new Nord();
	participants[6] = new Robot();


	int counter = 0;


	double currT = std::clock() / (double)CLOCKS_PER_SEC;
	double duration = currT;
	double prevT = currT;
	double deltaT = currT - prevT;
	double cooldown = 1;
	double timer = cooldown;
	while (duration < 10000)
	{
		prevT = currT;
		currT = std::clock() / (double)CLOCKS_PER_SEC;
		deltaT = currT - prevT;
		timer -= deltaT;

		if (timer <= 0)
		{
			timer = cooldown;
			std::cout << "ROUND::" << counter << std::endl;

			int current = rand() % NUMPARTICIPANTS;
			int next = rand() % NUMPARTICIPANTS;
			Entity* attacker = participants[current];
			while (attacker->mHealth > 0)
			{
				current = rand() % NUMPARTICIPANTS;
				attacker = participants[current];
			}

			Entity* defender = participants[next];
			while (defender->mHealth > 0 && current != next)
			{
				next = rand() % NUMPARTICIPANTS;
				defender = participants[next];
			}

			attacker->Attack(*defender);
			std::cout << "|Attacker|";
			attacker->DisplayInfo();
			std::cout << "|Defender|";
			defender->DisplayInfo();

			counter++;
		}
	}

	return 0;
}
