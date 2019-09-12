#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Fighter {
private:
	
	int attack;
	int defense;
	int intelligence;
public:
	string name;
	int health;
	Fighter(string name, int health, int attack, int defense, int intelligence) {
		this->name = name;
		this->health = health;
		this->attack = attack;
		this->defense = defense;
		this->intelligence = intelligence;
	}
	void ToString() {
		cout << "Fighter " << this->name << " has " << this->health << " health " << this->attack << " attack " << this->defense << " defense " << this->intelligence << " intelligence. " << endl;
	}
	int Attack(){
		return rand() % this->attack;
		//Randomizes attakc?
	}
	int Defense() {
		return rand() % this->defense;
		//randomizes defense?
	}
};
class Battle {
public:
	static void StartFight(Fighter &A, Fighter &B) {
		int dmg;
		while (true)
		{
			dmg = A.Attack() - B.Defense();
			if (dmg < 0)
				dmg = 0;
			B.health -= dmg;
			if (B.health < 0)
				B.health = 0;
			cout << A.name << " does " << dmg << " damage to " << B.name << "leaving them with " << B.health << " hp." << endl;
			if (B.health <= 0)
			{
				cout << "Game Over." << A.name << " wins the fight." << endl;
				break;
			}
			dmg = B.Attack() - A.Defense();
			
			if (dmg < 0)
				dmg = 0;
			A.health -= dmg;
			if (A.health < 0)
				A.health = 0;
			cout << B.name << " does " << dmg << " damage to " << A.name << "leaving them with " << A.health << " hp." << endl;
			if (A.health <= 0)
			{
				cout << "Game Over. " << B.name << " wins the fight." << endl;
				break;
			}
		}
	}
};

int main()
{
	srand(time(NULL));
	Battle Fight;
	
	Fighter Hulk("Hulk", 10, 7, 8, 5);
	Hulk.ToString();
	Fighter Hulk2("Hulk2", 10, 7, 8, 5);
	Hulk2.ToString();
	Fight.StartFight(Hulk, Hulk2);

}