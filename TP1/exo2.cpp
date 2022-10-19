#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class Matrice
{
private:
    vector<vector<int>> A;
    vector<vector<int>> B;

public:
    vector<vector<int>> rsl;

    Matrice(vector<vector<int>> A, vector<vector<int>> B)
    {
        this->A = A;
        this->B = B;
        for (int i = 0; i < A.size(); i++)
        {
            vector<int> init;
            for (int j = 0; j < A.size(); j++)
            {
                init.push_back(0);
            }
            this->rsl.push_back(init);
        }
    }

    void product()
    {
        if (this->A[0].size() == this->B.size())
        {
            vector<thread> pool;
            int m = -1, n = -1;
            for (int i = 0; i < this->A.size(); i++)
            {
                m += 1;
                n = -1;
                for (int j = 0; j < this->B[0].size(); j++)
                {
                    n += 1;
                    pool.push_back(
                        thread([this, m, n, i, j]()
                               {
                                   for (int ind = 0; ind < this->B.size(); ind++)
                                   {
                                       this->rsl[m][n] += this->A[i][ind] * this->B[ind][j];
                                   }
                               }));
                }
            }
            for (thread &t : pool)
            {
                t.join();
            }
        }
        else
        {
            cout << "They are not match to product" << endl;
        }
    }
};

int main()
{
    vector<vector<int>> A = {
        {1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> B = {
        {10, 11}, {20, 21}, {30, 31}};
    // vector<vector<int>> A = {
    //     {-1, 4}, {2, 3}};
    // vector<vector<int>> B = {
    //     {9, -3}, {6, 1}};
    Matrice M(A, B);
    M.product();
    for (int i = 0; i < M.rsl.size(); i++)
    {
        for (int j = 0; j < M.rsl[0].size(); j++)
        {
            cout << M.rsl[i][j] << " ";
        }
        cout << endl;
    }
}