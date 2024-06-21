//
// Created by Victor Navarro on 15/02/24.
//

#include "Player.h"
#include <iostream>
#include "../Files/FileHandler.h"
#include "../Dice/Dice.h"
#include <limits>

using namespace std;

Player::Player(string _name, int _health, int _attack, int _defense, int _speed) : Character(_name.c_str(), _health, _attack, _defense, _speed, true, 0)
{
    level = 1;
    experience = 0;
    requiredExp = 0;
    coins = 0;
    healthOG = _health;
}

void Player::saveProgress()
{
    char *buffer = this->serialize();
    FileHandler fileHandler = FileHandler();

    fileHandler.writeToFile("PlayerInfo.data", buffer, Player::BUFFER_SIZE);
    cout << "Partida guardada..." << endl;
}

void Player::doAttack(Character *target)
{
    int diceValue = dice.roll();
    float multiplier = (1.0 + (diceValue / 10.0));
    int totalAttack = attack * multiplier;
    cout << "El dado ha salido: " << diceValue << ". El ataque total es: " << totalAttack << endl;
    target->takeDamage(totalAttack);
}

void Player::takeDamage(int damage)
{
    int trueDamage = damage - defense;

    health -= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;

    if (health <= 0)
    {
        cout << name << " has been defeated!" << endl;
    }
}

void Player::gainExperience(int exp)
{
    experience += exp;

    while (experience >= requiredExp)
    {
        level++;
        experience -= requiredExp;
        requiredExp += 100;

        int action = 0;

        do
        {
            cout << "Select a stat to improve: " << endl
                 << "1. Damage (" << attack << ") > " << (attack + 10) << endl
                 << "2. Defense (" << defense << ") > " << (defense + 10) << endl
                 << "3. Health (" << healthOG << ") > " << (healthOG + 10) << endl
                 << "4. Speed (" << speed << ") > " << (speed + 10) << endl;

            while (!(cin >> action))
            {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch (action)
            {
            case 1:
                attack += 10;
                break;
            case 2:
                defense += 10;
                break;
            case 3:
                healthOG += 10;
                break;
            case 4:
                speed += 10;
                break;
            default:
                cout << "Invalid action. Please enter a valid number." << endl;
                action = 0;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            break;
        } while (action < 1 || action > 4);
    }
}

Character *Player::selectTarget(vector<Enemy *> possibleTargets)
{
    int selectedTarget = 0;
    cout << "Select a target: " << endl;
    for (int i = 0; i < possibleTargets.size(); i++)
    {
        cout << i << ". " << possibleTargets[i]->getName() << endl;
    }

    // TODO: Add input validation
    cin >> selectedTarget;
    return possibleTargets[selectedTarget];
}

Action Player::takeAction(vector<Enemy *> enemies)
{
    int action = 0;
    cout << "Select an action: " << endl
         << "1. Attack" << endl
         << "2. Defend" << endl;
        //  << "3. Save Player Progress" << endl;

    // TODO: Validate input
    cin >> action;
    Action currentAction;
    Character *target = nullptr;

    switch (action)
    {
    case 1:
        target = selectTarget(enemies);
        currentAction.target = target;
        currentAction.action = [this, target]()
        {
            doAttack(target);
        };
        break;
    case 2:
        if (!canDefend())
        {
            cout << "You've defended yourself, it's time to attack" << endl;
            target = selectTarget(enemies);
            currentAction.target = target;
            currentAction.action = [this, target]()
            {
                doAttack(target);
            };
        }
        else
        {
            cout << "You have chosen to defend" << endl;
            currentAction.target = nullptr;
            currentAction.action = [this]()
            {
                defend();
            };
        }
        break;
    // case 3:
    //     saveProgress();
    //     return takeAction(enemies);
    //     break;
    default:
        cout << "Invalid action" << endl;
        return takeAction(enemies);
        break;
    }

    return currentAction;
}

char *Player::serialize()
{
    char *iterator = buffer;

    // Serializar nombre
    size_t nameLength = name.length();
    memcpy(iterator, &nameLength, sizeof(nameLength));
    iterator += sizeof(nameLength);
    memcpy(iterator, name.c_str(), nameLength);
    iterator += nameLength;

    // Serializar los demás atributos
    memcpy(iterator, &health, sizeof(health));
    iterator += sizeof(health);
    memcpy(iterator, &attack, sizeof(attack));
    iterator += sizeof(attack);
    memcpy(iterator, &defense, sizeof(defense));
    iterator += sizeof(defense);
    memcpy(iterator, &speed, sizeof(speed));
    iterator += sizeof(speed);
    memcpy(iterator, &isPlayer, sizeof(isPlayer));
    iterator += sizeof(isPlayer);
    memcpy(iterator, &level, sizeof(level));
    iterator += sizeof(level);
    memcpy(iterator, &experience, sizeof(experience));
    iterator += sizeof(experience);

    return buffer;
}

Player *Player::unserialize(char *buffer)
{
    char *iterator = buffer;
    size_t nameLength;
    memcpy(&nameLength, iterator, sizeof(nameLength));
    iterator += sizeof(nameLength);

    char nameBuffer[nameLength + 1];
    memcpy(nameBuffer, iterator, nameLength);
    iterator += nameLength;
    nameBuffer[nameLength] = '\0'; // Null terminator

    int health, attack, defense, speed, level, experience;
    bool isPlayer;

    memcpy(&health, iterator, sizeof(health));
    iterator += sizeof(health);
    memcpy(&attack, iterator, sizeof(attack));
    iterator += sizeof(attack);
    memcpy(&defense, iterator, sizeof(defense));
    iterator += sizeof(defense);
    memcpy(&speed, iterator, sizeof(speed));
    iterator += sizeof(speed);
    memcpy(&isPlayer, iterator, sizeof(isPlayer));
    iterator += sizeof(isPlayer);
    memcpy(&level, iterator, sizeof(level));
    iterator += sizeof(level);
    memcpy(&experience, iterator, sizeof(experience));
    iterator += sizeof(experience);

    return new Player(nameBuffer, health, attack, defense, speed);
}
