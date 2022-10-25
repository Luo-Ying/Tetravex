#include "library.h"

class GameCard
{
private:
    int left;
    int top;
    int right;
    int bottom;

public:
    GameCard();
    GameCard(vector<int> data);
    int GetLeft();
    int GetTop();
    int GetRight();
    int GetBottom();
};