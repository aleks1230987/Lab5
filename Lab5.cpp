#include <iostream>
#include <string>
using namespace std;

class Human {
public: 
    string Name;
    int Level;

    Human() {
        Name = "Unknown";
        Level = 1;
    }
    Human(string name, int level) {
        Name = name;
        Level = level;
    }

    string GetName() {
        return Name;
    }
    int GetLevel() {
        return Level;
    }
    virtual void SetName(string name) {
        Name = "";
    }
};

class Staff : public virtual Weapon {
public:
    int Dmg;
    int Durability;

    Staff() {
        Dmg = 10;
        Durability = 10;
    }

    void Take() override {
        cout << "You took staff" << endl;
    }
    void Use() override {
        Durability -= 1;
        if (Durability <= 0) {
            cout << "Your staff broken" << endl;
        }
    }
    int GetDmg() {
        return Dmg;
    }
};

class Weapon {
public:
    virtual void Take() = 0;
    virtual void Use() = 0;
    virtual int GetDmg() = 0;
};

class Sword: public virtual Weapon {
public:
    int Dmg = 5;
    int Durability;

    Sword() {
        Dmg = 5;
        Durability = 40;
    }

    void Take() override {
        cout << "You took sword" << endl;
    }
    void Use() override {
        Durability -= 1;
        if (Durability <= 0) {
            cout << "Your sword broken" << endl;
        }
    }

    int GetDmg() {
        return Dmg;
    }
};

class Bow : public virtual Weapon {
public:
    int Dmg;
    int Durability;

    Bow() {
        Dmg = 7;
        Durability = 20;
    }

    void Take() override {
        cout << "You took bow" << endl;
    }
    void Use() override {
        Durability -= 1;
        if (Durability <= 0) {
            cout << "Your bow broken" << endl;
        }
    }
    int GetDmg() {
        return Dmg;
    }
};

class Warrior : public virtual Human {
public:
    int HealthPoints;
    int Damage;
    string Name;

    Warrior(string name) {
        HealthPoints = 40;
        Damage = 1;
        Name = name;
    }

    void TakeWeapon(Weapon& weapon) {
        Damage += weapon.GetDmg();
        weapon.Take();
    }

    void UseWeapon(Weapon& weapon) {
        weapon.Use();
    }

    int GetHP() {
        return HealthPoints;
    }
    int GetDmg() {
        return Damage;
    }
    void SetHp(int HP) {
        HealthPoints = HP;
    }
    void SetDamage(int dm) {
        Damage = dm;
    }

    void SetName(string name) override {
        Name = name;
    }
};

class Ranger : public virtual Human {
public:
    int HealthPoints;
    int Damage;
    string Name;

    Ranger(string name) {
        HealthPoints = 25;
        Damage = 2;
        Name = name;
    }

    void TakeWeapon(Weapon& weapon) {
        Damage += weapon.GetDmg();
        weapon.Take();
    }

    void UseWeapon(Weapon& weapon) {
        weapon.Use();
    }

    int GetHP() {
        return HealthPoints;
    }
    int GetDmg() {
        return Damage;
    }
    void SetHp(int HP) {
        HealthPoints = HP;
    }
    void SetDamage(int dm) {
        Damage = dm;
    }
    void SetName(string name) override {
        Name = name;
    }
};

class Mage : public virtual Human {
public:
    int HealthPoints;
    int Damage;
    string Name;

    Mage(string name) {
        HealthPoints = 15;
        Damage = 3;
        Name = name;
    }

    void TakeWeapon(Weapon& weapon) {
        Damage += weapon.GetDmg();
        weapon.Take();
    }

    void UseWeapon(Weapon& weapon) {
        weapon.Use();
    }

    int GetHP() {
        return HealthPoints;
    }
    int GetDmg() {
        return Damage;
    }
    void SetHp(int HP) {
        HealthPoints = HP;
    }
    void SetDamage(int dm) {
        Damage = dm;
    }
    void SetName(string name) override {
        Name = name;
    }
};

class Enemy {
public:
    int Count;
    Enemy() {
        Count = 1;
    }
    Enemy(int k) {
        Count = k;
    }

    int GetCount() {
        return Count;
    }
};

class Bandit: public virtual Human, public virtual Enemy {
    int HealthPoints;
    int Level;
    int Damage;

    Bandit() {
        HealthPoints = 12;
        Level = 1;
        Damage = 2;
    }
    Bandit(int level) {
        HealthPoints = 12 + 2 * level;
        Level = level;
        Damage = 2 + level;
    }
};

int main()
{
    Warrior voin("Geralt");
    Human chel;
    Mage mag("Gendalf");

    cout << voin.GetHP() << endl;
    mag.SetName("NewGendalf");
    cout << chel.GetLevel() << endl;

    Sword sword;
    Staff staff;
    mag.TakeWeapon(staff);
    cout << mag.GetDmg() << endl;
    voin.TakeWeapon(sword);
    voin.UseWeapon(sword);

    Bandit bandit1();

}
