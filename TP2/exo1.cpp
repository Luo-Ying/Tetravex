#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <functional>
#include <atomic>
#include <condition_variable>
#include <vector>

using namespace std;

atomic<double> sum;
mutex m;
queue<function<void()>> lst_task;
condition_variable cv;
vector<thread> pool;
condition_variable cv2;

void formulaire(int n)
{
    for (double i = 1.0; i <= n; i++)
    {

        lst_task.push([i]()
                      {
                        lock_guard<mutex> lock(m);
                        double molecule = 1.0, denominator = 1.0;
                        for (double j = 1.0; j <= i; j++)
                        {
                            molecule *= (-1.0);
                            denominator *= j;
                        }
                        sum.store(sum.load() + (molecule / denominator)); 
                        cout << "value:" << sum.load() << endl; });
        cv.notify_one();
    }
}

void pushPool(int k)
{
    for (int i = 0; i < k; i++)
    {
        pool.push_back(
            thread(
                []()
                {
                    while (true)
                    {
                        unique_lock<mutex> lk(m);
                        // if (!lst_task.empty())
                        // {
                        cv.wait(lk, [&]
                                { return !lst_task.empty(); });
                        function<void()> f = lst_task.front();
                        lst_task.pop();
                        lk.unlock();
                        f();
                        lk.lock();
                        cv2.notify_one();
                        // }
                        // else
                        // {
                        //     break;
                        // }
                    }
                }));
    }
}

int main()
{
    sum.store(1.0);
    int n = 5;
    int nt = 2;
    pushPool(nt);
    formulaire(n); // n = 5 : 0.366667
    unique_lock<mutex> lk2(m);
    cv2.wait(lk2, [&]
             { return lst_task.empty(); });
}