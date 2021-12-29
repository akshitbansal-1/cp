/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int f(vector<int> &v, int m, int n) {
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += min(v[i + 1] - v[i], m);
    }
    sum += m;
    return sum;
}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n, h;
        cin>>n>>h;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin>>v[i];
        if (h <= n) {
            cout<<1<<endl;
            continue;
        }
        sort(v.begin(), v.end());
        int l = 1, u = h + 1;
        int ans = 0;
        while (l <= u) {
            int m = (l + u) / 2;
            int x = f(v, m, n);
            // cout<<m<<endl;;
            if (h > x) {
                l = m + 1;
            } else if (h == x) {
                ans = m;
                break;
            } else {
                ans = m;
                u = m - 1;
            }
        }
        cout<<ans<<endl;
    }
}