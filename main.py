class Weapon:
    def __init__(self, attack):
        self.attack = attack
        
    def get_attack(self):
        return self.attack
        
class Sword(Weapon):
    def __init__(self, attack):
        super().__init__(attack)
        
    def get_name(self):
        return "sword"
        
class Dagger(Weapon):
    def __init__(self, attack):
        super().__init__(attack)
        
    def get_name(self):
        return "dagger"
        
class Character:
    def __init__(self, name, defense, health):
        self.name = name
        self.defense = defense
        self.health = health
        
    def attack(self, target):
        pass
        
    def take_damage(self, damage):
        self.health -= damage
        
    def get_defense(self):
        return self.defense
        
    def get_health(self):
        return self.health
        
    def get_name(self):
        return self.name
        
    def print_health(self):
        print(self.name, "has", self.health, "health")
        
class Hero(Character):
    def __init__(self, name, defense, health, weapon):
        super().__init__(name, defense, health)
        self.weapon = weapon
        
    def attack(self, target):
        damage = self.weapon.get_attack() - target.get_defense()
        target.take_damage(damage)
        print(self.get_name(), "has inflicted", damage, "damage on", target.get_name())
        
    def enable_weapon(self, weapon):
        self.weapon = weapon
        print(self.get_name(), "has gripped a", self.weapon.get_name())
        
    def print_health(self):
        print(self.get_name(), "has", self.get_health(), "health")
        
class Enemy(Character):
    def __init__(self, name, defense, attack, health):
        super().__init__(name, defense, health)
        self.attack_power = attack
        
    def attack(self, target):
        damage = self.attack_power - target.get_defense()
        if damage < 0:
            damage = 0
        target.take_damage(damage)
        print(self.get_name(), "has inflicted", damage, "damage on", target.get_name())
        
if __name__ == '__main__':
    sword = Sword(8)
    dagger = Dagger(2)

    crab = Enemy("crab", 5, 3, 10)
    hero = Hero("bob", 1, 10, sword)

    hero.enable_weapon(dagger)
    # Prints:
    #   bob has gripped a dagger

    hero.enable_weapon(sword)
    # Prints:
    #   bob has gripped a sword

    hero.attack(crab)
    # Prints:
    #   bob has inflicted 3 damage on crab

    crab.attack(hero)
    # Prints:
    #   crab has inflicted 2 damage on bob

    crab.print_health()
    # Prints:
    #   crab has 7 health

    hero.print_health()
    # Prints:
    #   bob has 8 health
