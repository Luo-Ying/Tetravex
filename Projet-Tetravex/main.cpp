#include "Tetravex.h"
#include <queue>

Tetravex tetravex = Tetravex("data.txt");

void gameTest()
{
    cout << "Put succès? " << tetravex.putCard(1, 1, 1) << endl;
    cout << "Put succès? " << tetravex.putCard(2, 2, 1) << endl;

    tetravex.getGameTable().displayTable();

    cout << &tetravex.getGameTable().getTable()[1][1] << endl;

    cout << "card 1 left:" << tetravex.getGameTable().getTable()[1][1]->getLeft() << endl;
    cout << "card 1 top:" << tetravex.getGameTable().getTable()[1][1]->getTop() << endl;
    cout << "card 1 right:" << tetravex.getGameTable().getTable()[1][1]->getRight() << endl;
    cout << "card 1 bottom:" << tetravex.getGameTable().getTable()[1][1]->getBottom() << endl;
    cout << endl;
    cout << "card 1 left:" << tetravex.getListCard()[2]->getLeft() << endl;
    cout << "card 1 top:" << tetravex.getListCard()[2]->getTop() << endl;
    cout << "card 1 right:" << tetravex.getListCard()[2]->getRight() << endl;
    cout << "card 1 bottom:" << tetravex.getListCard()[2]->getBottom() << endl;

    cout << "état de card 1: isused = " << tetravex.getListCard()[1]->getIsUsed() << endl;
    cout << "état de card 2: isused = " << tetravex.getListCard()[2]->getIsUsed() << endl;

    tetravex.removeCard(1, 1);

    cout << "après remove -------- " << endl;

    tetravex.getGameTable().displayTable();

    cout << "état de card 1: isused = " << tetravex.getListCard()[1]->getIsUsed() << endl;
    cout << "état de card 2: isused = " << tetravex.getListCard()[2]->getIsUsed() << endl;

    tetravex.resetGameTable();

    cout << "après reset table -------- " << endl;

    tetravex.getGameTable().displayTable();

    cout << "état de card 1: isused = " << tetravex.getListCard()[1]->getIsUsed() << endl;
}

bool playGame(int row, int col)
{
    for (int i = 0; i < int(tetravex.getListCard().size()); i++)
    {
        if (tetravex.putCard(i, row, col))
        {
            if (col < tetravex.getGameTable().getWidth() - 1)
            {
                bool isPlaced = playGame(row, col + 1);
                if (!isPlaced)
                {
                    tetravex.removeCard(row, col);
                }
                else
                {
                    return true;
                }
            }
            else
            {
                if (row < tetravex.getGameTable().getHeight() - 1)
                {
                    bool isPlaced = playGame(row + 1, 0);
                    if (!isPlaced)
                    {
                        tetravex.removeCard(row, col);
                    }
                    else
                    {
                        return true;
                    }
                }
                else
                {
                    // cout << "row ??????????????????????????????" << row << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    // gameTest();
    auto start = high_resolution_clock::now();

    if (playGame(0, 0))
    {
        cout << "Table result: " << endl;
        tetravex.getGameTable().displayTable();
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Le temps pris par la fonction: " << duration.count() / 1000000 << " secondes" << endl;

    return 0;
}