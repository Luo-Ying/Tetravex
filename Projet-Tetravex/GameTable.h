#include "library.h"
#include "GameCard.h"

class GameTable
{
private:
    int width;
    int height;
    vector<vector<GameCard *>> table;

public:
    GameTable();
    GameTable(int width, int height);
    int getWidth();
    int getHeight();
    void putCard(GameCard *card, int row, int column);
    void removeCard(int row, int column);
    vector<vector<GameCard *>> getTable();
    bool isCaseAvaileble(int row, int col);
    bool isMatchWithTop(GameCard *card, int row, int column);
    bool isMatchWithBottom(GameCard *card, int row, int column);
    bool isMatchWithLeft(GameCard *card, int row, int column);
    bool isMatchWithRight(GameCard *card, int row, int column);
    void displayTable();
};