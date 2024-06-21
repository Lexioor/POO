//
// Created by Victor Navarro on 15/02/24.
//

#include "Enemy.h"
#include "../Utils.h"
#include <iostream>

using namespace std;
using namespace combat_utils;

Enemy::Enemy(string _name, int _health, int _attack, int _defense, int _speed) : Character(_name.c_str(), _health, _attack, _defense, _speed, false, 0)
{
    expGift = 50;
    healthOG = _health;
}

void Enemy::doAttack(Character *target)
{
    target->takeDamage(getRolledAttack(attack));
}

void Enemy::takeDamage(int damage)
{
    int trueDamage = damage - defense;
    health -= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;
    if (health <= 0)
    {
        cout << name << " has been defeated!" << endl;
    }
}

int Enemy::getExperience()
{
    return expGift;
}

Character *Enemy::selectTarget(vector<Player *> possibleTargets)
{
    // target with less health
    int lessHealth = 9999999;
    Character *target = nullptr;
    for (auto character : possibleTargets)
    {
        if (character->getHealth() < lessHealth)
        {
            lessHealth = character->getHealth();
            target = character;
        }
    }
    return target;
}

Action Enemy::takeAction(vector<Player *> partyMembers)
{
    Action currentAction;
    currentAction.speed = getSpeed();

    if (health < (0.15 * healthOG))
    {
        if (rand() % 10 <= 4)
        {
            if (!canDefend())
            {
                Character *target = selectTarget(partyMembers);
                currentAction.target = target;
                currentAction.action = [this, target]()
                {
                    doAttack(target);
                };
            }
            else
            {
                cout << name << " has defended." << endl;
                currentAction.target = nullptr;
                currentAction.action = [this]()
                {
                    defend();
                };
            }
        }
    }
    else
    {
        Character *target = selectTarget(partyMembers);
        currentAction.target = target;
        currentAction.action = [this, target]()
        {
            doAttack(target);
        };
    }

    return currentAction;
}