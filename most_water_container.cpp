/*You are given an integer array height of length n. There are n vertical lines drawn 
such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container 
contains the most water.
Return the maximum amount of water a container can store.*/

#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int max_area(vector<int> heights){
    int lp = 0;
    int rp = heights.size()-1;
    int max_a = 0;
    while(lp<rp){
        int wt = rp-lp;
        int ht = std::min(heights[lp],heights[rp]);
        int area = wt*ht;
        max_a = std::max(max_a,area); 
        heights[lp]<heights[rp] ? lp++ : rp--; 
    }
    return max_a;
}

int main(){
    vector<int> v1 = {1,8,6,2,5,4,8,3,7};

    std::cout<<"max area : "<<max_area(v1)<<endl;
    return 0;
}