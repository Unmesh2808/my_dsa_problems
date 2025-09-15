#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

std::condition_variable cv;
std::mutex m1, m2;
bool go = false;

void print_odd(int n){
    std::unique_lock<mutex> q1(m1);
    for (int i = 1; i<n; i+=2){
        cv.wait(q1, [&] {return go;});
        if (i%2 != 0){
            std::cout<< i <<" ";
            go=false;
            cv.notify_all();
        }
    }
}

void print_even(int n){
    std::unique_lock<mutex> q1(m1);
    for (int i = 0; i<n; i+=2){
        cv.wait(q1, [&] {return !go;});
        if (i%2 == 0){
            std::cout<< i <<" ";
            go=true;
            cv.notify_all();
        }
    }

}

int main(){
    std::thread t_odd(print_odd, 10);
    std::thread t_even(print_even, 10);

    {
        unique_lock<mutex> lock(m1);
        go = false;
        cv.notify_all();
    }

    // if (t_odd.joinable() && t_even.joinable())
    // {
    t_odd.join();
    t_even.join();
    // }

    return 0;
}
