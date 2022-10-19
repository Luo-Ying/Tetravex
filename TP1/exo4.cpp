#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

vector<thread> pool;
int count = 0;
mutex m;

void displayNumPair()
{
    // cout << "Les nombres pairs(de 0 à 1000): " << endl;
    for (int i = 0; i < 1001; i++)
    {
        pool.push_back(
            thread(
                [i]()
                {
                    m.lock();
                    count++;
                    i % 2 == 0 && cout << "Thread " << count << ": un nombre pair -> " << i << endl;
                    m.unlock();
                }));
    }
    cout << endl;
}

void displayNumOdd()
{
    // cout << "Les nombres impaires(de 0 à 1000): " << endl;
    for (int i = 0; i < 1001; i++)
    {
        pool.push_back(
            thread(
                [i]()
                {
                    m.lock();
                    count++;
                    i % 2 != 0 && cout << "Thread " << count << ": un nombre impaire -> " << i << endl;
                    m.unlock();
                }));
    }
    cout << endl;
}

int main()
{

    displayNumPair();
    cout << " --------------------------------- " << endl;
    displayNumOdd();
    for (thread &t : pool)
    {
        t.join();
    }
}