//
//  main.cpp
//  threading
//
//  Created by Swapnil Bhalerao on 23/09/21.
//

#include <iostream>
#include <thread>

using namespace std;
void fun()
{
    cout << "child thread ..." << std::this_thread::get_id() << endl;
}
int main(int argc, const char *argv[])
{
    // insert code here...
    std::cout << "main thread  ...";
    std::cout << std::this_thread::get_id() << endl;
    thread t1(fun);
    t1.join();
    return 0;
}
