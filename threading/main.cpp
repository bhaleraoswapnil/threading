//
//  main.cpp
//  threading
//
//  Created by Swapnil Bhalerao on 23/09/21.
//
//  use of condition variable.
//  1_Producer and 1_Consumer problem

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
using namespace std;
std::mutex mu;
std::condition_variable cond_var;

std::deque<int> q;

void producer_one()
{
    int data = 20;
    while (data > 0)
    {
        cout<<"-p-\n";
        unique_lock<std::mutex> ul(mu);
        cout<<"produce\n";
        q.push_front(data);
        data--;
        ul.unlock();
        cond_var.notify_one();
    }
    cout<<"p";
}

void consumer_one()
{
    int data = 0;
    while (data != 1)
    {
        cout<<"-c-\n";
        unique_lock<std::mutex> ul(mu);
        if (!q.empty())
        {
            data = q.back();
            cout << "consume => " << q.back() << endl;
            q.pop_back();
            ul.unlock();
        }
        else
        {
            cond_var.wait(ul);
        }
    }
    cout<<"c";
}

int main(int argc, const char *argv[])
{
    // insert code here...

    std::thread T2(consumer_one);
    std::thread T1(producer_one);
    

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
