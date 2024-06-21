#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"
#include "Files/FileHandler.h"

using namespace std;

Player* loadPlayerInfo() {
    try {
        char buffer[Player::BUFFER_SIZE];
        FileHandler fileHandler = FileHandler();
        fileHandler.readFromFile("PlayerInfo.data", buffer, Player::BUFFER_SIZE);
        return Player::unserialize(buffer);
    } catch(const runtime_error& e) {
        return new Player("Lexioor", 50, 10, 7, 8);
    }
}

int main() {
    Player *player = loadPlayerInfo();
    Enemy *enemy = new Enemy("Goblin", 15, 5, 2, 5);
    Enemy *enemy2 = new Enemy("Orc", 15, 5, 2, 5);

    vector<Character*> participants;

    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat *combat = new Combat(participants);
    combat->doCombat();

    delete player;
    delete enemy;
    delete combat;
    return 0;
}

// RUN CODE
// g++ main.cpp Player/Player.cpp Enemy/Enemy.cpp Combat/Combat.cpp Combat/Action.cpp Character/Character.cpp Files/FileHandler.cpp Dice/Dice.cpp -o main ; ./main.exe