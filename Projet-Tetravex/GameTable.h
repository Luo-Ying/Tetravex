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
    vector<vector<GameCard *>> getTable();
    bool isCaseAvaileble(int row, int col);
};