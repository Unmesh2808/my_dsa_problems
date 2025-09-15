#include <vector>
#include<string>
#include <sstream>
#include<iostream>
#include <map>

std::vector<std::string> tokens;
std::string sentence = "Hi, Unmesh Is my Name";

std::istringstream iss(sentence);
std::string word;

void count_occur(std::string str){
    std::istringstream istring(str);
    std::map<std::string, int> m1;
    while(istring >> word){
        m1[word] +=1;
    }
    for (auto pair : m1){
        std::cout << pair.first << " : " <<pair.second <<std::endl;
    }
}

int main(){
while(iss >> word){
    tokens.push_back(word);
}

for (auto iter = tokens.rbegin(); iter!=tokens.rend();++iter){
    std::cout<< *iter <<" ";
}
std::cout<<std::endl;

count_occur("What what what what what");

return 0;
}
 
