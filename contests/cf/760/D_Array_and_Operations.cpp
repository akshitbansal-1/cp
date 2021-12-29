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
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin>>v[i];
        sort(begin(v), end(v));
        int i = n - k - 1, j = n - 1;
        int ans = 0;
        while (k) {
            ans += v[i] / v[j];
            i--;j--;
            k--;
        }
        while (i >= 0) ans += v[i--];
        cout<<ans<<endl;
    }
}