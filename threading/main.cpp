//
//  main.cpp
//  threading
//
//  Created by Swapnil Bhalerao on 23/09/21.
//
//  future: pass value to child thread and return result to main thread.

#include <iostream>
#include <future>
using namespace std;

int factorial(int inputVal)
{
//    cout << "Child thread ID :" << std::this_thread::get_id() << endl;
    int result = 1;
    for (int i = 1; i <= inputVal; i++)
    {
        result = result * i;
    }
    
    return result;
}
int main(int argc, const char *argv[])
{
    // insert code here...
    int x;
    cout << "Enter value to calculate Factorial\n";
    cin >> x;
    std::future<int> fu = std::async(std::launch::async, factorial, x);
//    cout << "Parent thread ID :" << std::this_thread::get_id() << endl;
    cout << "Factorial from Child Thread = " << fu.get() << endl;
    return 0;
}
