//
// Created by Victor Navarro on 15/02/24.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>
#include "../Dice/Dice.h"

using namespace std;

class Character
{
protected:
    string name;
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    int defenseMode;

    Dice dice;

public:
    Character(const char *_name, int _health, int _attack, int _defense, int _speed, bool _isPlayer, int _defenseMode);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    bool flee(Character *target);
    string getName();
    int getHealth();
    int getAttack();
    int getDefense();
    int getDefenseMode();
    bool getIsPlayer();
    int getSpeed();
    string toString();

    bool canDefend();
    void defend();
    void nerfDefenseMode();
};

#endif // RPG_CHARACTER_H
