import java.util.*;

abstract class Weapon {
  public abstract int getAttack();

  public abstract String getName();
}

class Sword extends Weapon {
  private int attack;

  public Sword(int attack) {
    this.attack = attack;
  }

  public int getAttack() {
    return attack;
  }

  public String getName() {
    return "sword";
  }
}

class Dagger extends Weapon {
  private int attack;

  public Dagger(int attack) {
    this.attack = attack;
  }

  public int getAttack() {
    return attack;
  }

  public String getName() {
    return "dagger";
  }
}

class Character {
  private String name;
  private int defense, health;

  public Character(String name, int defense, int health) {
    this.name = name;
    this.defense = defense;
    this.health = health;
  }

  public void attack(Character target) {
    // No implementation in base class
  }

  public void takeDamage(int damage) {
    health -= damage;
  }

  public int getDefense() {
    return defense;
  }

  public int getHealth() {
    return health;
  }

  public String getName() {
    return name;
  }

  public void printHealth() {
    System.out.println(name + " has " + health + " health");
  }
}

class Hero extends Character {
  private Weapon weapon;

  public Hero(String name, int defense, int health, Weapon weapon) {
    super(name, defense, health);
    this.weapon = weapon;
  }

  public void attack(Character target) {
    int damage = weapon.getAttack() - target.getDefense();
    target.takeDamage(damage);
    System.out.println(getName() + " has inflicted " + damage + " damage on " + target.getName());
  }

  public void enableWeapon(Weapon weapon) {
    this.weapon = weapon;
    System.out.println(getName() + " has gripped a " + weapon.getName());
  }

  public void printHealth() {
    System.out.println(getName() + " has " + getHealth() + " health");
  }
}

class Enemy extends Character {
  private int attack;

  public Enemy(String name, int defense, int attack, int health) {
    super(name, defense, health);
    this.attack = attack;
  }

  public void attack(Character target) {
    int damage = attack - target.getDefense();
    if (damage < 0) {
      damage = 0;
    }
    target.takeDamage(damage);
    System.out.println(getName() + " has inflicted " + damage + " damage on " + target.getName());
  }
}

public class Main {
  public static void main(String[] args) {
    Sword sword = new Sword(8);
    Dagger dagger = new Dagger(2);

    Enemy crab = new Enemy("crab", 5, 3, 10);
    Hero hero = new Hero("bob", 1, 10, sword);

    hero.enableWeapon(dagger);
    // Prints:
    // bob has gripped a dagger

    hero.enableWeapon(sword);
    // Prints:
    // bob has gripped a sword

    hero.attack(crab);
    // Prints:
    // bob has inflicted 3 damage on crab

    crab.attack(hero);
    // Prints:
    // crab has inflicted 2 damage on bob

    crab.printHealth();
    // Prints:
    // crab has 7 health

    hero.printHealth();
    // Prints:
    // bob has 8 health
  }
}