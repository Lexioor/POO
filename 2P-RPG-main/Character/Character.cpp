//
// Created by Victor Navarro on 15/02/24.
//

#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(const char *_name, int _health, int _attack, int _defense, int _speed, bool _isPlayer, int _defenseMode)
{
    name = _name;
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
    defenseMode = _defenseMode;
}

string Character::getName()
{
    return name;
}

int Character::getHealth()
{
    return health;
}

int Character::getAttack()
{
    return attack;
}

int Character::getDefense()
{
    return defense;
}

int Character::getDefenseMode()
{
    return defenseMode;
}

int Character::getSpeed()
{
    return speed;
}

string Character::toString()
{
    return "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed);
}

bool Character::getIsPlayer()
{
    return isPlayer;
}

bool Character::flee(Character *target)
{
    if (this->speed > target->speed)
        return true;

    int chance = rand() % 100;
    return chance > 30;
}

bool Character::canDefend()
{
    if (defenseMode == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Character::defend()
{
    defenseMode = 2;
    int diceValue = dice.roll();
    float multiplier = (1.0 + (diceValue / 10.0));
    int boostedDefense = static_cast<int>(defense * multiplier);
    cout << "El dado ha salido: " << diceValue << ". La defensa total es: " << boostedDefense << endl;
}

void Character::nerfDefenseMode()
{
    if (defenseMode > 0)
    {
        defenseMode -= 1;

        if (defenseMode == 0)
        {
            defense = static_cast<int>(defense * .8);
        }
    }
}