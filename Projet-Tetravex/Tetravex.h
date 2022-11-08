#include "library.h"
#include "GameTable.h"

class Tetravex
{
private:
    GameTable gameTable = *new GameTable();
    vector<GameCard> listCard;

public:
    Tetravex(string fileName);
    void putCard(GameCard *card, int row, int column);
    GameTable getGameTable();
    vector<GameCard> getListCard();
};