// scenario to share data between two POSIX threads
#include<iostream>
#include<queue>
#include<pthread.h>
#include<unistd.h>
#include<chrono>
#include <thread>


std::queue<std::string> msgs_log;
pthread_mutex_t p_mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t p_cv = PTHREAD_COND_INITIALIZER;
bool data = false;

void* producer(void* arg){
    for (int i=0;i<5;i++){
        sleep(1);

        std::string str = "log_message #" + std::to_string(i);
        pthread_mutex_lock(&p_mtx);
        msgs_log.push(str);
        std::cout << "producer_pushed_msgs "<<str<<"\n";
        pthread_cond_signal(&p_cv);
        pthread_mutex_unlock(&p_mtx);
    }

    {
        pthread_mutex_lock(&p_mtx);
        data = true;
        pthread_cond_signal(&p_cv);
        pthread_mutex_unlock(&p_mtx);
    }
    return nullptr;
}
void* consumer(void* arg){
    while (true){
        pthread_mutex_lock(&p_mtx);
        while(msgs_log.empty() && !data){
            pthread_cond_wait(&p_cv, &p_mtx);
        }
        while (!msgs_log.empty()){
            std::string str1 = msgs_log.front();
            msgs_log.pop();
            pthread_mutex_unlock(&p_mtx);
            std::cout << "Consumer processing " << str1 << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            pthread_mutex_lock(&p_mtx);
        }
        if(data){
            pthread_mutex_unlock(&p_mtx);
            break;
        }
        pthread_mutex_unlock(&p_mtx);

    }
    std::cout<<"consumer_done...\n";
    return nullptr;
}

int main(){
    pthread_t prod_thread, cons_thread;
    pthread_create(&prod_thread, nullptr, producer, nullptr);
    pthread_create(&cons_thread, nullptr, consumer, nullptr);

    pthread_join(prod_thread, nullptr);
    pthread_join(cons_thread, nullptr);

    pthread_mutex_destroy(&p_mtx);
    pthread_cond_destroy(&p_cv);
    return 0;
}
