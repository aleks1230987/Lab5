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
