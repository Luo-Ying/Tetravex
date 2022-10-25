#include "GameCard.h"

GameCard::GameCard() {}

GameCard::GameCard(vector<int> data)
{
    this->left = data[0];
    this->top = data[1];
    this->right = data[2];
    this->bottom = data[3];
    this->isUsed = false;
}

int GameCard::getLeft()
{
    return this->left;
}

int GameCard::getRight()
{
    return this->right;
}

int GameCard::getTop()
{
    return this->top;
}

int GameCard::getBottom()
{
    return this->bottom;
}

void GameCard::setIsUsed(bool isUsed)
{
    this->isUsed = isUsed;
}

bool GameCard::getIsUsed()
{
    return this->isUsed;
}