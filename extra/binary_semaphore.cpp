#include<iostream>
#include<thread>
#include<semaphore>

using namespace std;

std::binary_semaphore sem(0);

void worker_thread(){
    cout<<"worker thread started waiting for signaling ....\n";
    sem.acquire();
    cout<<"Worker thread continues ... \n";

}
int main(){
    std::thread T1(worker_thread);

    std::this_thread::sleep_for(std::chrono::seconds(2));
    sem.release();
    T1.join();
    return 0;
}
