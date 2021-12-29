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
        int n = 3;
        vector<int> v(3);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        int a = v[0], b = v[1];
        int diff = b - a;
        int ans = a;
        ans += diff;
        v[2] -= diff;
        cout<<ans + v[2] / 2<<endl;
    }
}