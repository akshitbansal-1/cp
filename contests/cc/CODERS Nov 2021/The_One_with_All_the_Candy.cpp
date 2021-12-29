/*
    Written by: akshitforever
*/

// #include<iostream>
// #include<algorithm>
// #include<vector>
#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin>>v[i];
        int m = INT_MAX;
        for (int j = n - 1; j >= 0; j--) {
            m = min(v[j], m);
        }
        m++;
        int ans = 0;
        for (int j = 0; j < n ; j++) {
            ans += min(v[j], m);
        }
        cout<<ans<<endl;

    }
}