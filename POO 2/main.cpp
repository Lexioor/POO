#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

int main() {
    while(true) {
        Player *player = new Player("Lexioor", 100, 8, 4, 10);
        Enemy *enemy = new Enemy("SAT", 50, 5, 2, 5, 10);

        cout << player->toString() << endl;
        cout << enemy->toString() << endl;

        cout << "=====================" << endl;

        while(player->isAlive() && enemy->isAlive()) {
            player->doAttack(enemy);
            if (!enemy->isAlive()) break; // Si el enemigo muere, salimos del bucle
            enemy->doAttack(player);
            if (!player->isAlive()) break; // Si el jugador muere, salimos del bucle
        }

        cout << player->toString() << endl;
        cout << enemy->toString() << endl;

        if (!player->isAlive()) {
            cout << "El jugador ha muerto. Fin del juego." << endl;
            delete player;
            delete enemy;
            break; // Salimos del bucle principal
        } else if (!enemy->isAlive()) {
            cout << "El enemigo ha muerto. Continuamos con el siguiente enemigo." << endl;
            delete player;
            delete enemy;
        }
    }
    return 0;
}
