#include<iostream>
#include<vector>

using namespace std;

void nextPermutation(vector<int>& A) {
    int pivot = -1, n = A.size();
    // finding the pivot index
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            pivot = i;
            break;
        }
    }
    if(pivot==-1){
        reverse(A.begin(),A.end());
        return;
    }
    // finding the next large value after pivot
    for(int i=n-1; i>pivot;i--){
        if(A[pivot] < A[i]){
            swap(A[i],A[pivot]);
            break;
        }
    }
    // reversing all the values after pivot is swapped to get the next higher value than the one in the org vector
    // alternate
    // reverse(A.begin() + pivot + 1,A.end());
    
    int i=pivot+1, j = n-1;
    while(i<=j){
        swap(A[i],A[j]);
        i++;
        j--;   
    }
}
