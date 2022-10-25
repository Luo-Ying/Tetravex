#include "library.h"
#include "GameTable.h"

class Tetravex
{
private:
    GameTable gameTable = *new GameTable();
    vector<GameCard> listCard;

public:
    Tetravex(string nameFile);
};