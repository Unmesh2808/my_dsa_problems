// reverse a number 

#include<iostream>
#include<string>

//sizeof will give data type size
//length() and size() will give number of char in the string

int main(){
    int num = 12345;
    std::string str = std::to_string(num);
    std::string str2 ="";
    // std::cout << str.length()<<"\n";
    for (int i=str.length()-1;i>=0;i--){
        str2 = str2 + str[i];
    }
    std::cout << str2 <<" " << str;
    int rev = std::stoi(str2);
    printf("\nog_num-->%d \n rev_num-->%d\n",num,rev);
    
    //without using string functions
    int num1 = 0;
    int rev_num;
    for (int n = num; n != 0; n/=10){
        num1 = n%10;
        rev_num = rev_num*10 + num1;
        // std::cout<<rev_num;
    }
    std::cout<<rev_num;
    return 0;
}