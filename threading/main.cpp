//
//  main.cpp
//  threading
//
//  Created by Swapnil Bhalerao on 23/09/21.
//
//  Big Array sum using multiple threads.
//  Each thread should handle min 1000 array fields.

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;
std::mutex mu;
#define ARRAY_SIZE 10000
int sum_array[ARRAY_SIZE] = {0};

int sum_fun(int start_index, int _size)
{

    int subset_sum = 0;
    for (int i = start_index; i < start_index + _size; i++)
    {
        subset_sum = subset_sum + sum_array[i];
    }
    mu.lock();
    cout << "Thread ID == " << std::this_thread::get_id() << " " << start_index << " " << _size << endl;
    cout << "subset sum == " << subset_sum << endl;
    mu.unlock();

    return subset_sum;
}

int main(int argc, const char *argv[])
{
    // insert code here...

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sum_array[i] = 2;
    }

    // check how many Thread required to perform sum.
    int no_of_thread_supported_system = std::thread::hardware_concurrency();
    int each_thread_to_process = ARRAY_SIZE / no_of_thread_supported_system;

    int start_index = 0;
    std::thread *ptr;
    ptr = new std::thread[no_of_thread_supported_system];

    for (int i = 0; i < no_of_thread_supported_system; i++)
    {
        std::thread thread_obj(sum_fun, start_index, each_thread_to_process);
        start_index = start_index + each_thread_to_process;

        ptr[i] = std::move(thread_obj);
    }

    for (int i = 0; i < no_of_thread_supported_system; i++)
    {
        if (ptr[i].joinable())
        {
            ptr[i].join();
        }
    }
    delete[] ptr;

    return 0;
}
