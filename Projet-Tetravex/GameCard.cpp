#include "GameCard.h"

GameCard::GameCard(vector<int> data)
{
    this->left = data[0];
    this->top = data[1];
    this->right = data[2];
    this->bottom = data[3];
}

int GameCard::GetLeft()
{
    return this->left;
}

int GameCard::GetRight()
{
    return this->right;
}

int GameCard::GetTop()
{
    return this->top;
}

int GameCard::GetBottom()
{
    return this->bottom;
}