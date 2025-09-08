#include <iostream>
#include<vector>

using namespace std;

int main(){
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> unique;
        for (int i=0;i<n;i++){
            auto it = find(unique.begin(),unique.end(),nums[i]);
            if (it==unique.end()){
                unique.push_back(nums[i]);
            }
        }
        int ans = unique.size();
        int diff = n-ans;
        
        for (int i=0;i<diff;i++) unique.push_back(0);

        nums = unique;
        return ans;
    }

    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for (int j=1;j<nums.size();j++){
            if (nums[i]!=nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
    return 0;
}