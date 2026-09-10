#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Weapon {
protected:
    string requiredOwner;

public:
    Weapon(string owner) : requiredOwner(owner) {}

    virtual void useWeapon() const = 0;
    virtual string getName() const = 0;

    string getRequiredOwner() const {
        return requiredOwner;
    }
    virtual ~Weapon() = default;
};
