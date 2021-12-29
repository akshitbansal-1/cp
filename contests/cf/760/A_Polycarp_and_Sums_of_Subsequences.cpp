/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n = 7;
        // cin>>n;
        vector<int> v(n);
        for (int i = 0; i < 7; i++) cin>>v[i];

            cout<<v[0]<<" "<<v[1]<<" "<<v[6] - v[0] - v[1]<<endl;
        // }
    }
}