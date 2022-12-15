#include "library.h"
#include "GameTable.h"

class Tetravex
{
private:
    GameTable gameTable = *new GameTable();
    vector<GameCard *> listCard;

public:
    Tetravex();
    Tetravex(vector<vector<int>> data);
    bool putCard(GameCard *card, int row, int column);
    void removeCard(int row, int column);
    GameTable getGameTable();
    vector<GameCard *> getListCard();
    void resetGameTable();
};