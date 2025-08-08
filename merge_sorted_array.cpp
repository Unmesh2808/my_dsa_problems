#include <vector>
#include<iostream>
#include<utility>
#include<algorithm>


using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{       
    int count=0;
    for(int i=m-n;i<m;i++){
        nums1[i] = nums2[count];
        count++;
        if (count==n) break;
    }  
    sort(nums1.begin(), nums1.end()); 
}
int main(){
    vector<int> num1 = {1,2,3,0,0,0};
    vector<int> num2 = {2,5,6};

    merge(num1, num1.size(), num2, num2.size());

    for (int a : num1){
        cout << a <<"\n";
    }

    return 0;
}
