#include <iostream>

using namespace std;
// O(n) this wont work if power is greater than 10^8 [for ex pow(2^24) now 2^24 > 10^8]
double myPow(double x, int n) {
    double value = 1;
    int m = std::abs(n);
    while(m!=0){
        value = value * x;
        m--;
    }
    if(n<0){
        return 1/value;
    }
    return value;
}

//O(log n)
double myPow_(double x, int n) {
    if (n==0){return 1.0;}
    if(x==0){return 0.0;}
    if(x==-1 && n%2==0) return 1;
    if(x==-1 && n%2!=0) return -1;

    
    long binform=n;

    if(n<0){
        x = 1/x;
        binform = -binform;
    }

    double ans = 1;

    while(binform > 0){
        if (binform % 2 == 1){
            ans *= x;
        }
        x *=x;
        binform /= 2;
        // cout<<binform<<endl;
    }
    return ans;
}

int main(){
    double c = 5;
    int p = 8;
    std::cout << myPow_(c,p);
}