/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int major_num(vector<int> nums){
    int n = nums.size();
    int cand, count=0;
    for (int i=0;i<n;i++){
        if(count==0) cand = nums[i];
        if(nums[i]==cand) 
        {   count++;
            std::cout<<"cand = "<<cand<<endl;
        }
        else count--;
           
    }
    cout<<count<<"\n";
    return cand;     
}

int majorityElement(vector<int>& nums) {
        int n = nums.size()/2+1;
        for (int x : nums){
            int count = std::count(nums.begin(),nums.end(), x);
            if (count>=n){return x;}        
        }
        return -1;
    }

int main(){
    vector<int> nums = {1,2,3,4,5,7,6,6,6};
    int ans = major_num(nums);
    cout<<"major eleme A: "<<ans<<"\n";

    int ans2 = majorityElement(nums);
    cout<<"major eleme B: "<<ans<<"\n";

    return 0;
}