#include<vector>
#include<iostream>
using namespace std;
#define int long long
int n, k;
vector<pair<int, int > > v;
int calc(int m) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (m <= v[i].first) res += 0;
        else res += min(v[i].second + 1, m) - v[i].first;
    }
    return res;
}
int32_t main() {
    cin>>n>>k;
    // k++;
    v.assign(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) cin>>v[i].first>>v[i].second;
    int l = -2 * 1e9, r = 2 * 1e9 + 1;
    // int i = 100;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        int x = calc(m);
        if (x <= k) l = m;
        else r = m;
        // cout<<l<<" "<<r<<endl;
    }
    cout<<l;
    return 0;
}