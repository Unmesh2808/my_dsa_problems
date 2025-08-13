// Write a function to serialize and deserialize a simple object in C++.
#include<fstream>
#include<iostream>
#include<string>

using namespace std;

class Serial {
private:
    string name;
    int age;

public:
    Serial(){}
    // constuctor
    Serial(const string& name, int age) : name(name), age(age){}

    void get_info()
    {
        cout<<" name = "<<name<<endl;
        cout<<" age = " <<age<<endl;
    }

    void serialize(const string& filename){
        ofstream file(filename, ios::binary);
        if (!file.is_open()){
            cerr<<"failed to open the file-----------\n";
            return;
        }
        file.write(reinterpret_cast<const char*>(this),sizeof(*this));
        file.close();

    }

    static Serial de_serialize(const string& filename){
    
        Serial obj("", 0);
        ifstream file(filename, ios::binary);
        
        if(!file.is_open()){
            cerr<<"failed to open the file-----------\n";
            return obj;
        }
        file.read(reinterpret_cast<char*>(&obj),sizeof(obj));
        file.close();
        return obj;
    }


};
int main(){
    Serial object1("Alice", 23);
    object1.serialize("data.bin");

    Serial new_obj = Serial::de_serialize("data.bin");
    new_obj.get_info();
    return 0;
}