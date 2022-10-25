#include "library.h"
#include "GameTable.h"
// #include "GameCard.h"

class Tetravex
{
private:
    // vector<vector<int>> data;
    GameTable gameTable = *new GameTable();
    // GameCard gameCard;
    vector<GameCard> listCard;
    // int sizeLine = width * sizeof(int);
    // int size = height * sizeof(int);

public:
    Tetravex(string nameFile);
};