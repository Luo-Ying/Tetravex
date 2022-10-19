#include <iostream>
#include <thread>
#include <unistd.h>
#include <condition_variable>

using namespace std;

int count = 0;
mutex cv_m;
condition_variable cv;

void counter()
{
    while (1)
    {
        sleep(1);
        {
            lock_guard<mutex> lock(cv_m); // 等同于开头放lock结尾放unlock, garder le programme pour l'instant.
            count++;
            cout << count << " seconde ..." << endl;
            count == 5 && cout << "Il faut ouvrir les vannes." << endl;
        } // 大括号避免虚假唤醒
        cv.notify_one();
    }
}

void signals()
{
    while (1)
    {
        unique_lock<mutex> lock(cv_m); // 将wait锁住避免多次触发
        cv.wait(lock, [&]
                { return count >= 5; });
        cout << "L'eau est déjà lancé." << endl;
        count = 0;
    }
}

int main()
{
    thread t1(counter), t2(signals);
    t1.join();
    t2.join();
}