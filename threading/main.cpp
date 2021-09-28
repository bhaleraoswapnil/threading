//
//  main.cpp
//  threading
//
//  Created by Swapnil Bhalerao on 23/09/21.
//
//  join thread using RAII (Resource Acquisition Is Initialization)

#include <iostream>
#include <thread>

using namespace std;

class my_thread_guard
{
private:
    std::thread &t;

public:
    my_thread_guard(std::thread &T) : t(T)
    {
    }
    ~my_thread_guard()
    {
        if (t.joinable())
        {
            t.join();
        }
    }
    my_thread_guard(const my_thread_guard &) = delete;
    my_thread_guard &operator=(const my_thread_guard &) = delete;
};
void fun()
{
    for (int i = 100; i > 0; i--)
    {
        cout << "child thread = " << i << endl;
    }
}
int main(int argc, const char *argv[])
{
    // insert code here...
    std::thread t1(fun);
    my_thread_guard obj(t1);
    for (int i = 0; i < 100; i++)
    {
        cout << "main thread = " << i << endl;
    }

    return 0;
}
