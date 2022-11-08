#include "Tetravex.h"

int main()
{
    Tetravex tetravex = Tetravex("data.txt");
    tetravex.putCard(&tetravex.getListCard()[5], 2, 1);
    // for (int i = 0; i < tetravex.getGameTable().getTable().size(); i++)
    // {
    //     for (int j = 0; j < tetravex.getGameTable().getTable()[i].size(); j++)
    //     {
    //         cout << tetravex.getGameTable().getTable()[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << &tetravex.getGameTable().getTable()[2][1] << endl;
    // cout << tetravex.getGameTable().getTable()[2][1]->getLeft() << endl;
    // cout << tetravex.getGameTable().getTable()[2][1]->getTop() << endl;
    // cout << tetravex.getGameTable().getTable()[2][1]->getRight() << endl;
    // cout << tetravex.getGameTable().getTable()[2][1]->getBottom() << endl;
}