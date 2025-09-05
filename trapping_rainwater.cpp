#include<vector>
#include<iostream>
using namespace std;

int get_amount_trapped(vector<int> vect){
    int n = vect.size();
    vector<int> lmax(n,0);
    vector<int> rmax(n,0);
    lmax[0] = vect[0];
    rmax[n-1] = vect[n-1];

    for (int i=1; i<n; i++){
        lmax[i] = max(lmax[i-1], vect[i]); 
    }
    for (int i=n-2; i>=0; i--){
        rmax[i] = max(rmax[i+1],vect[i]);
    }
    int ans=0;
    for(int i=0; i<n; i++){
        ans += min(lmax[i],rmax[i]) - vect[i];
    }
    return ans;
}


int main()
{
    vector<int> vec = {4,2,0,3,2,5};
    int rain_water = get_amount_trapped(vec);

    cout << rain_water<<endl;
    return 0;
} 