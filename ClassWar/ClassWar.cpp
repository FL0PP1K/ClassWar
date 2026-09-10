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
class WizardStaff : public Weapon {
public:
    WizardStaff() : Weapon("Чарівник") {}
    void useWeapon() const override { cout << "випускає магічну вогняну кулю!" << endl; }
    string getName() const override { return "Магічний посох"; }
};
class WizardGrimoire : public Weapon {
public:
    WizardGrimoire() : Weapon("Чарівник") {}
    void useWeapon() const override { cout << "читає заборонене заклинання з прадавньої книги!" << endl; }
    string getName() const override { return "Гримуар Таємниць"; }
};

class KnightSword : public Weapon {
public:
    KnightSword() : Weapon("Лицар") {}
    void useWeapon() const override { cout << "здійснює потужний випад гострим королівським мечем!" << endl; }
    string getName() const override { return "Королівський меч"; }
};
class KnightHammer : public Weapon {
public:
    KnightHammer() : Weapon("Лицар") {}
    void useWeapon() const override { cout << "трощить ворога важким бойовим молотом!" << endl; }
    string getName() const override { return "Важкий молот"; }
};

class ElfBow : public Weapon {
public:
    ElfBow() : Weapon("Ельф") {}
    void useWeapon() const override { cout << "пускає влучну стрілу з гнучкого ельфійського лука!" << endl; }
    string getName() const override { return "Ельфійський лук"; }
};
class ElfDaggers : public Weapon {
public:
    ElfDaggers() : Weapon("Ельф") {}
    void useWeapon() const override { cout << "наносить серію блискавичних ударів парними кинджалами!" << endl; }
    string getName() const override { return "Парні кинджали"; }
};

class TrollClub : public Weapon {
public:
    TrollClub() : Weapon("Троль") {}
    void useWeapon() const override { cout << "б'є величезною грубою дубиною з розмаху!" << endl; }
    string getName() const override { return "Величезна дубина"; }
};
class TrollBoulder : public Weapon {
public:
    TrollBoulder() : Weapon("Троль") {}
    void useWeapon() const override { cout << "кидає важкий каміннюк у ворогів!" << endl; }
    string getName() const override { return "Важкий валун"; }
};

class Character {
protected:
    string name;
    string description;
    string typeName;
    Weapon* weapon;
public:
    Character(string n, string desc, string t)
        : name(n), description(desc), typeName(t), weapon(nullptr) {
    }
    void display() const {
        cout << "Герой: " << name << " (" << description << ")" << endl;
    }
    bool equipWeapon(Weapon* newWeapon) {
        if (newWeapon->getRequiredOwner() == this->typeName) {
            if (weapon != nullptr) {
                delete weapon;
            }
            weapon = newWeapon;
            cout << "Успішно озброєно: " << weapon->getName() << "!" << endl;
            return true;
        }
        else {
            cout << "Ця зброя не підходить цьому персонажу!" << endl;
            return false;
        }
    }
    void fight() const {
        if (weapon) {
            cout << name << " ";
            weapon->useWeapon();
        }
        else {
            cout << name << " б'ється голими руками (немає зброї)!" << endl;
        }
    }
    virtual ~Character() {
        if (weapon) delete weapon;
    }
};

class Wizard : public Character {
public:
    Wizard() : Character("Чарівник", "Мудрий майстер магії", "Чарівник") {}
};
class Knight : public Character {
public:
    Knight() : Character("Лицар", "Відважний воїн у броні", "Лицар") {}
};
class Elf : public Character {
public:
    Elf() : Character("Ельф", "Влучний лісовий стрілець", "Ельф") {}
};
class Troll : public Character {
public:
    Troll() : Character("Троль", "Дика і страшна сила", "Троль") {}
};