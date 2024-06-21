#include "Dice.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Dice::Dice()
{
    srand(time(nullptr));
}

int Dice::roll()
{
    return rand() % 18 + 2;
}
