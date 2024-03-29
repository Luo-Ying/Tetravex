#include "library.h"
#include "GameTable.h"

class Tetravex
{
private:
    GameTable gameTable = *new GameTable();
    vector<GameCard *> listCard;

public:
    Tetravex(string fileName);
    bool putCard(int itemCard, int row, int column);
    void removeCard(int row, int column);
    GameTable getGameTable();
    vector<GameCard *> getListCard();
};