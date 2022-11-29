#include "Tetravex.h"

// Tetravex tetravex = Tetravex("data.txt");

// deque<GameCard *> cards;

// queue<function<void()>> lst_task;
// vector<thread> pool;
// mutex m;
// condition_variable cv;
// condition_variable cv2;

bool *isFinished = new bool;

vector<vector<int>> readFile()
{
    vector<vector<int>> data;
    int choix;
    string filename;
    string line;
    cout << "Entrez votre choix pour la taille de data: " << endl;
    cout << "1 - 5x5" << endl;
    cout << "2 - 6x6" << endl;
    cout << "3 - 7x7" << endl;
    cout << "4 - 8x8" << endl;
    cin >> choix;
    if (choix == 1)
    {
        filename = "data_5x5.txt";
    }
    else if (choix == 2)
    {
        filename = "data_6x6.txt";
    }
    else if (choix == 3)
    {
        filename = "data_7x7.txt";
    }
    else if (choix == 4)
    {
        filename = "data_8x8.txt";
    }
    ifstream ReadFile(filename);
    while (getline(ReadFile, line))
    {
        vector<int> lineData;
        for (int i = 0; i < int(line.length()); i++)
        {
            if (line[i] != ' ')
            {
                lineData.push_back(line[i] - '0');
            }
        }
        data.push_back(lineData);
    }
    ReadFile.close();
    return data;
}

bool playGame(int row, int col, vector<GameCard> cards, Tetravex tetravex)
{
    // cout << *isFinished << endl;
    // cout << cards.size() << endl;
    if (!*isFinished)
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
    else
    {
        return false;
    }
}

int main()
{
    *isFinished = false;

    vector<vector<int>> data = readFile();

    Tetravex tetravex = Tetravex(data);
    vector<GameCard> cards;

    for (int i = 0; i < int(tetravex.getListCard().size()); i++)
    {
        cards.push_back(*tetravex.getListCard()[i]);
    }

    cout << "resultat en séquenciel: " << endl;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < int(cards.size()); i++)
    {
        Tetravex tetravexCopy = Tetravex(data);
        vector<GameCard> cardsCopy;
        for (int i = 0; i < int(tetravexCopy.getListCard().size()); i++)
        {
            cardsCopy.push_back(*tetravexCopy.getListCard()[i]);
        }
        tetravexCopy.putCard(&cardsCopy[i], 0, 0);
        // cout << "card -> " << i << endl;
        if (!playGame(0, 1, cardsCopy, tetravexCopy))
        {
            tetravexCopy.removeCard(0, 0);
        }
        else
        {
            break;
        }
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Le temps pris par la fonction: " << duration.count() / 1000000 << " secondes" << endl;

    return 0;
}