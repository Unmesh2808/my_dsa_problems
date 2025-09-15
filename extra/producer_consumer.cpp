// scenario to share data between two threads

#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include<queue>

std::queue<std::string> log_msgs;
std::condition_variable cv;
std::mutex mtx;
bool data = false;


void producer(){
    for (int i=0;i<5;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::string str = "log_msg #" + std::to_string(i);
        {
            std::lock_guard<std::mutex> lock1(mtx);
            log_msgs.push(str);
            std::cout << "Producer added to the queue... " << str <<std::endl; ;
        }
        cv.notify_one(); //notify queue not empty
    }
    {
        std::lock_guard<std::mutex> lock1(mtx);
        data=true; //boolean to close the other thread as the adding has been completed
    }
    cv.notify_one(); //notify that adding has been completed
}

void consumer(){
    while (true)
    {
        std::unique_lock<std::mutex> lock2(mtx);
        cv.wait(lock2, [] { return !log_msgs.empty() || data == true; });
        while(!log_msgs.empty()){
            std::string str1 = log_msgs.front();
            log_msgs.pop();
            lock2.unlock();
            std::cout<<"consumer read the queue  emptied... " << str1 <<std::endl;;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            lock2.lock();
        }
        if (data) break;
    }
    std::cout << "Consumer [Done]\n";

}

int main(){
    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;

}