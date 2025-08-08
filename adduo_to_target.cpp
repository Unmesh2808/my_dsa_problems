#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

vector<std::pair<int, int>> get_the_pairs(vector<int> s1, int target){
    sort(s1.begin(), s1.end());
    int left = 0;
    int right = s1.size() - 1;
    vector<std::pair<int, int>> v1;
    while(left < right){
        int sum = s1[left] + s1[right];
        if (sum == target){
            v1.push_back({s1[left], s1[right]});
            left<right? left++:right--;
        }
        else if (sum < target) 
            left++;
        else 
            right--;
    }
    return v1;
}


int main(){
    vector<int> s1 = {1, 5, 7, -1, 5};
    int target = 6;
    vector<std::pair<int, int>> result = get_the_pairs(s1, target);
    
    for (std::pair p1 : result){
        std::cout << p1.first << ", " << p1.second <<endl;
    }

    return 0;
}
