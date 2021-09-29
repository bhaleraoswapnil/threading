//
//  main.cpp
//  threading
//
//  Created by Swapnil Bhalerao on 23/09/21.
//
//  use of condition variable.
//  Print even number by one thread and odd number by other thread.

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
std::mutex mu;
std::condition_variable cond_var;

int var = 0;

void even_number()
{
    while (var <= 20)
    {
        std::unique_lock<std::mutex> ul(mu);
        if (var % 2 == 0)
        {
            cout << "even thread => " << var << endl;
            var++;
            cond_var.notify_one();
        }
        else
        {
            cout<<"even waiting\n";
            cond_var.wait(ul);
        }
    }
}

void odd_number()
{
    while (var <= 20)
    {
        std::unique_lock<std::mutex> ul(mu);
        if (var % 2 != 0)
        {
            cout << "odd  thread => " << var << endl;
            var++;
            cond_var.notify_one();
        }
        else
        {
            cout<<"odd  waiting\n";
            cond_var.wait(ul);
        }
    }
}

int main(int argc, const char *argv[])
{
    // insert code here...

    std::thread T1(even_number);
    std::thread T2(odd_number);

    if (T1.joinable())
    {
        T1.join();
    }

    if (T2.joinable())
    {
        T2.join();
    }
    return 0;
}
