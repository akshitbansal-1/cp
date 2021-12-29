/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
struct st {
    int x, y, d, r, u, l;
};
bool cmp1(const struct st &x, const struct st & y) {
    return x.x < y.x;
}
bool cmp2(const struct st &x, const struct st & y) {
    return x.y < y.y;
}
void solve() {
    int n;
    cin>>n;
    vector<st> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i].x;
        cin>>v[i].y;
        cin>>v[i].d;
        cin>>v[i].r;
        cin>>v[i].u;
        cin>>v[i].l;
    }
    sort(v.begin(), end(v), cmp1);
    int m1 = v[0].x, i;
    for (i = 0; i < n - 1; i++) {
        // if (v[i].x < v[n - 1].x) {
        if (v[i].u == 0) {
            break;
        }
        // }
        // m1 = max(m1, v[i].x);
    }
    for (int j = i + 1; j < n; j++) {
        if (v[j].x > v[i].x && v[j].d == 0) {
            cout<<0<<endl;
            return;
        }
    }
    int ans1 = v[n - 1].x;
    if (i < n) {
        ans1 = v[i].x;
    }

    sort(v.begin(), v.end(), cmp2);
    for (i = 0; i < n - 1; i++) {
        // if (v[i].x < v[n - 1].x) {
        if (v[i].r == 0) {
            break;
        }
        // }
        // m1 = max(m1, v[i].x);
    }
    for (int j = i + 1; j < n; j++) {
        if (v[j].y > v[i].y && v[j].l == 0) {
            cout<<0<<endl;
            return;
        }
    }
    
    int ans2 = v[n - 1].y;
    if (i < n) {
        ans2 = v[i].y;
    }
    cout<<1<<" "<<ans1<<" "<<ans2<<endl;
    // if (m1 < v[n - 1].x )
}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}