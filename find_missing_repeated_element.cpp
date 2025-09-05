#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

vector<int> finding_miss_rep(vector<vector<int>>& nums){
    int repeated=-1,count=0;
    unordered_map<int,int> freq;

    vector<int> v1={};
    for (const auto& row : nums){
        for (int val : row){
            freq[val]++;
            if(freq[val]==2) {
                repeated=val;
                count = freq[val];
            }    
        }
    }
    v1.push_back(repeated);
    int n = nums.size()*nums.size();
    for(int i=1;i<=n;i++){
        if(freq.find(i) == freq.end()){
            v1.push_back(i);
        }
    }
    // std::cout<<repeated<<" "<<;
    return v1;
}

//alternative solution with less time complexity 
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int missing=-1, repeated=-1, count=0;
    // unordered_map<int,int> freq;
    int n = grid.size();
    int N = n*n;
    vector<int> freq(N+1,0);
    for (const auto& row : grid){
        for (int val : row){
            freq[val]++;
            if(freq[val]==2) {
                repeated=val;
            }    
        }
    }
    for (int i=1;i<=N;i++){
        if(freq[i]==0){
            missing = i;
        }
    }
    
    // std::cout<<repeated<<" "<<;
    return {repeated, missing};
}

int main(){
    vector<vector<int>> nums = {{9,1,7},{8,5,2},{3,4,6}};
    vector<int> ans = finding_miss_rep(nums);
    for(int a : ans){
        cout<<a<<"\n";
    }
    return 0;
}