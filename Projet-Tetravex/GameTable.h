#include "library.h"
#include "GameCard.h"

class GameTable
{
private:
    int width;
    int height;
    vector<vector<GameCard *>> table;

public:
    GameTable(vector<int> data);
};