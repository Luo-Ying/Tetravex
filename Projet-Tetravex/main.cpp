#include "Tetravex.h"

// Tetravex tetravex = Tetravex("data.txt");

// deque<GameCard *> cards;

bool playGame(int row, int col, deque<GameCard> cards, Tetravex tetravex)
{
    for (int i = 0; i < int(cards.size()); i++)
    {
        if (tetravex.putCard(&cards[i], row, col))
        {
            if (col < tetravex.getGameTable().getWidth() - 1)
            {
                bool isPlaced = playGame(row, col + 1, cards, tetravex);
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
                    bool isPlaced = playGame(row + 1, 0, cards, tetravex);
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
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{

    vector<thread> pool;
    mutex m;
    condition_variable cv;

    auto start = high_resolution_clock::now();

    Tetravex tetravex = Tetravex("data.txt");
    deque<GameCard> cards;

    for (int i = 0; i < int(tetravex.getListCard().size()); i++)
    {
        cards.push_front(*tetravex.getListCard()[i]);
    }

    for (int i = 0; i < int(cards.size()); i++)
    {
        // deque<GameCard *> cardsCopy = cards;
        // Tetravex tetravexCopy = tetravex;

        // pool.push_back(thread([i]()
        //                       {
        //                           Tetravex tetravexCopy = Tetravex("data.txt");
        //                           deque<GameCard> cardsCopy;
        //                           for (int i = 0; i < int(tetravexCopy.getListCard().size()); i++)
        //                           {
        //                               cardsCopy.push_front(*tetravexCopy.getListCard()[i]);
        //                           }
        //                           cout << "tour " << i << endl;
        //                           tetravexCopy.putCard(&cardsCopy[i], 0, 0);
        //                           playGame(0, 1, cardsCopy, tetravexCopy);
        //                       }));

        Tetravex tetravexCopy = Tetravex("data.txt");
        deque<GameCard> cardsCopy;
        for (int j = 0; j < int(tetravexCopy.getListCard().size()); j++)
        {
            cardsCopy.push_front(*tetravexCopy.getListCard()[j]);
        }
        cout << "tour " << i << endl;
        tetravexCopy.putCard(&cardsCopy[i], 0, 0);
        if (!playGame(0, 1, cardsCopy, tetravexCopy))
        {
            tetravexCopy.removeCard(0, 0);
        }
    }

    // for (int i = 0; i < int(pool.size()); i++)
    // {
    //     pool[i].join();
    // }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Le temps pris par la fonction: " << duration.count() / 1000000 << " secondes" << endl;

    return 0;
}