#include<iostream>
#include<vector>
#include<climits>

using namespace std;

// brute force method
int get_max_sum(vector<int> v1){
    int n = v1.size();
    int maxSum = INT_MIN;
    for (int st=0;st<n;st++){
        int currSum=0;
        for(int end=st;end<n;end++){
            currSum += v1[end];
            maxSum = max(currSum,maxSum);
        }
    }
    return maxSum;
}

//Kadane's algo----- if sum is getting < 0 then ignore the negative value and start from 0
void get_max(vector<int> v1){
    int curr_sum=0, max_sum = INT_MIN;
    for (int val : v1){
        curr_sum += val;
        max_sum = max(curr_sum, max_sum);
        if (curr_sum<0){
            curr_sum=0;
        }
    }
    cout<<max_sum<<"\n";
}


int main(){
    vector<int> v1 = {1,2,3,-4,5,6};
    // int max_sum = get_max_sum(v1);
    get_max(v1);
    // cout<<max_sum<<endl;
    return 0;
}