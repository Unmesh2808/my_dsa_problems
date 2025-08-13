// implement a thread-safe singleton in C++

#include<mutex>

using namespace std;

class Singleton{
private:
    Singleton(){}
    static Singleton* instanceptr;
    static mutex mtx;
public:
    Singleton(const Singleton& obj) = delete;
    static Singleton* get_instance(){
        if (instanceptr == nullptr){
            lock_guard<mutex> lock(mtx);
            if(instanceptr == nullptr)
                instanceptr = new Singleton();
        }
        return instanceptr;
    }
};

// Meyer's Singleton (stack allocation automatic delete)
class Singleton{
private:
    Singleton(){}
    Singleton(const Singleton& obj) = delete;
    Singleton& operator=(const Singleton& object) = delete;
public:
    static Singleton& get_instance(){
        static Singleton instance_ptr;
        return instance_ptr;
    }
};