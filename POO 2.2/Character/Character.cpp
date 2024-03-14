//
// Created by Victor Navarro on 15/02/24.
//

#include "Character.h"
Character::Character(string _name, int _health, int _attack, int _defense, int _speed, bool _isPlayer) {
    name = _name;
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
}

string Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getAttack() {
    return attack;
}

int Character::getDefense() {
    return defense;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    return "Name: " + name + "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed);
}

bool Character::flee(Character* target)
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
    defense = static_cast<int>(defense * 1.2);
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