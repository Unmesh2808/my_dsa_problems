#include<iostream>
#include<vector>

//my solution:
int find_single(std::vector<int>& nums){
    unordered_map<int,int> freq;
    for (int a : nums){
        freq[a]++;
    }
    for (int a : nums){
        if(freq[a] == 1) return a;
    }
    return -1;
}

int main() {
    std::vector<int> nums = {1,2,4,2,1};
    int xor_n = 0;
    for(int i=0;i < nums.size();i++){
        xor_n = xor_n^nums[i]; // performs bit wise XOR operation on each num in vector
    }
    std::cout<<xor_n;
    return 0;
}