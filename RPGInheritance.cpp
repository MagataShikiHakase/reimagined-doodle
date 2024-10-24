#include <iostream>

using namespace std;

class Weapon {
public:
	virtual int GetAttack() const = 0;
	virtual string GetName() const = 0;
};
class Sword : public Weapon {
	int attack;
public:
	Sword(int attack) : attack(attack) {}
	int GetAttack() const override { return attack; }
	string GetName() const override { return "sword"; }
};
class Dagger : public Weapon {
	int attack;
public:
	Dagger(int attack) : attack(attack) {}
	int GetAttack() const override { return attack; }
	string GetName() const override { return "dagger"; }
};

class Character {
	string name;
	int defense, health;
public:
	Character(string& name, int defense, int health) : name(name), defense(defense), health(health){}
	virtual ~Character(){}
	virtual void Attack(Character& target){}
	void TakeDamage(int damage) {
		health -= damage;
	}
	int GetDefense() { return defense; }
	int GetHealth() { return health; }
	string GetName() { return name; }
	virtual void PrintHealth() {
		cout << name << " has " << health << " health " << endl;
	}
};
class Hero : public Character {
	Weapon* weapon;
public:
	Hero(string name, int defense, int health, Weapon* weapon) : Character(name,defense,health), weapon(weapon){}
	void Attack(Character& target) override {
		int damage = weapon->GetAttack() - target.GetDefense();
		target.TakeDamage(damage);
		cout << GetName() << " has inflicted " << damage << " damage on " << target.GetName() << endl;
}
	void EnableWeapon(Weapon* weapon) {
		weapon = weapon;
		cout << GetName() << " has gripped a " << weapon->GetName() << endl;
	}
	void PrintHealth() override {
		cout << GetName() << " has " << GetHealth() << " health" << endl;
	}
};
class Enemy : public Character {
	int attack;
public:
	Enemy(string name, int defense, int attack, int health) : Character(name, defense, health), attack(attack){}
	void Attack(Character& target) override {
		int damage = attack - target.GetDefense();
		if (damage < 0) {
			damage = 0;
		}
		target.TakeDamage(damage);
		cout << GetName() << " has inflicted " << damage << " damage on " << target.GetName() << endl;
	}
};



int main() {
	Sword sword(/*attack=*/8);
	Dagger dagger(/*dagger=*/2);

	Enemy crab("crab", /*defense=*/5, /*attack=*/3, /*health=*/10);
	Hero hero("bob", /*defense=*/1, /*health=*/10, &sword);

	hero.EnableWeapon(&dagger);
	// Prints:
	//   bob has gripped a dagger

	hero.EnableWeapon(&sword);
	// Prints:
	//   bob has gripped a sword

	hero.Attack(crab);
	// Prints:
	//   bob has inflicted 3 damage on crab

	crab.Attack(hero);
	// Prints:
	//   crab has inflicted 2 damage on bob

	crab.PrintHealth();
	// Prints:
	//   crab has 7 health

	hero.PrintHealth();
	// Prints:
	//   bob has 8 health
}

//bob has gripped a dagger
//bob has gripped a sword
//bob has inflicted 3 damage on crab
//crab has inflicted 2 damage on bob
//crab has 7 health
//bob has 8 health
