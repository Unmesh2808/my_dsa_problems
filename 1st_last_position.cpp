#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ans;
    auto iter = find(nums.begin(),nums.end(), target);
    if(iter==nums.end()){
        return {-1,-1};
    }
    ans.push_back(iter-nums.begin());
    for (int i=nums.size()-1;i>=0;i--){
        if (nums[i]==target){
            ans.push_back(i);
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> vec2 = {1,2,3,3,3,3,4,5};
    vector<int> vec1 = searchRange(vec2,3);
    for(int a : vec1){
        cout << a<<" ";
    }
    return 0;
}
