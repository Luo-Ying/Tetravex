#include "library.h"

class GameCard
{
private:
    int left;
    int top;
    int right;
    int bottom;
    bool isUsed;

public:
    GameCard();
    GameCard(vector<int> data);
    void setIsUsed(bool isUsed);
    bool getIsUsed();
    int getLeft();
    int getTop();
    int getRight();
    int getBottom();
};