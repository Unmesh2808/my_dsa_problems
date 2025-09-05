#include <iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int left = 0;
    int right  = nums.size()-1;
    while (left<right){
        if(nums[left]==target) return left;
        else if(nums[right]==target) return right;
        else if(nums[right]>target) right--;
        else if (nums[left]<target) left++;
    }
    return -1;
}
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end  = nums.size()-1;
        while (start<=end){
            int mid = start + (end-start)/2;
            if (nums[mid]==target) return mid;

            if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target <= nums[mid]){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
            else {
                if(nums[mid]<=target && target<=nums[end]){
                    start = mid+1;
                }
                else{
                    end = mid-1;
                }
            }

        }
        return -1;
    }
};

int main(){
    vector<int> vec{4,5,6,7,0,1,2,3};
    cout << search(vec, 7)<<endl;

    return 0;
}