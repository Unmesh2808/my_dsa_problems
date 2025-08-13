// Write a C++ function to simulate a message queue between two threads.
#include<queue>
#include<thread>
#include<iostream>
#include <condition_variable>
#include<mutex>
#include <chrono>

using namespace std;

queue<string> log_messages;
condition_variable cv;
mutex mtx;
bool data_aval = false;

void queue_send(){
    for (int i=0;i<5;i++){
        string str = "log_message----> " + to_string(i);
        {
            lock_guard<mutex> lock(mtx);
            log_messages.push(str);
            cout<<"ADDING mesgs to he queue \n";
        }
        this_thread::sleep_for(chrono::milliseconds(500));
        cv.notify_one();
    }
    {
        lock_guard<mutex> lock(mtx);
        data_aval = true;
    }
    cv.notify_one();
}

void queue_receive(){
    while (true){
        unique_lock<mutex> lock2(mtx);
        cv.wait(lock2, [] {return data_aval==true || !log_messages.empty();});
        while(!log_messages.empty()){
            string str1 = log_messages.front();
            log_messages.pop();
            lock2.unlock();
            cout<<"messages read by the receiver----->" << str1 <<endl;
            this_thread::sleep_for(chrono::milliseconds(300));
            lock2.lock();
        }
        if (data_aval) break;
    }
    cout<< "receiver done"<< endl;
}

int main(){
    thread send(queue_send);
    thread receive(queue_receive);

    if (send.joinable() && receive.joinable()){
        send.join();
        receive.join();
    }
    return 0;
}