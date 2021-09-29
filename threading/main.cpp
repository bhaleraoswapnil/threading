//
//  main.cpp
//  threading
//
//  Created by Swapnil Bhalerao on 23/09/21.
//
//  use of lock_guard() and unique_lock()
//

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
std::mutex mu_1;
std::mutex mu_2;
int global_count = 0;
void increase_count()
{
    cout << "print from increase_count()\n";

    std::lock_guard<std::mutex> lg(mu_1); // This will lock mutex and unlock after outof scope.
    global_count++;
}

void decrease_count()
{
    cout << "print from decrease_count()\n";

    std::unique_lock<std::mutex> ul(mu_2); // Multiple time we can lock and unlock
    global_count--;

    //    ul.lock();
    //    do operation
    //    ul.unlock();
}

int main(int argc, const char *argv[])
{
    // insert code here...

    std::thread T1(increase_count);
    std::thread T2(decrease_count);

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
