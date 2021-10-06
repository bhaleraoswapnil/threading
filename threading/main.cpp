//
//  main.cpp
//  threading
//
//  Created by Swapnil Bhalerao on 23/09/21.
//
//  future promise: pass value from parent thread to child thread.

#include <iostream>
#include <future>
using namespace std;

int factorial(std::future<int> &f)
{
    //cout << "Child thread ID :" << std::this_thread::get_id() << endl;
    int result = 1;
    int inputVal = f.get();
    for (int i = 1; i <= inputVal; i++)
    {
        result = result * i;
    }

    return result;
}
int main(int argc, const char *argv[])
{
    // insert code here...
    std::promise<int> p; // promise between parent and child thread.
    std::future<int> f;  // pass future to child thread to get value from parent thread.
    f = p.get_future();

    std::future<int> fu = std::async(std::launch::async, factorial, std::ref(f));
    p.set_value(4);

    cout << "factorial == " << fu.get() << endl;
    return 0;
}
