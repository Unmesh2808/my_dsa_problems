#include <iostream>
#include <algorithm>
#include<string>
#include <vector>

//C++ function to reverse words in a string without using extra space.

using namespace std;

void reverse_words(string& str){
    std::reverse(str.begin(),str.end());
    size_t start=0;
    for (size_t i=0;i<=str.length();i++){
        if(i == str.size() || str[i] == ' '){
            std::reverse(str.begin() + start, str.begin()+i);
            start = i+1;
        }
    }
}

int main(){
    string str = "you only live once";
    reverse_words(str);

    cout<< str <<endl;
    return 0;
}