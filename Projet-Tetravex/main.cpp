#include "Tetravex.h"

int main()
{
    Tetravex tetravex = Tetravex("data.txt");

    cout << "Put succès? " << tetravex.putCard(1, 1, 1) << endl;
    cout << "Put succès? " << tetravex.putCard(2, 2, 1) << endl;

    tetravex.getGameTable().displayTable();

    cout << &tetravex.getGameTable().getTable()[2][1] << endl;

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

    tetravex.removeCard(2, 1);

    cout << "après remove -------- " << endl;

    tetravex.getGameTable().displayTable();

    cout << "état de card 1: isused = " << tetravex.getListCard()[1]->getIsUsed() << endl;
    cout << "état de card 2: isused = " << tetravex.getListCard()[2]->getIsUsed() << endl;

    tetravex.resetGameTable();

    cout << "après reset table -------- " << endl;

    tetravex.getGameTable().displayTable();

    cout << "état de card 1: isused = " << tetravex.getListCard()[1]->getIsUsed() << endl;
}