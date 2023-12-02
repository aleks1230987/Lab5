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
