#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
#define int long long int
int n, k;
vector<pair<int, int > > v;
int calc(int m) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (m <= v[i].first) res += 0;
        else {
            // double adding = ceil(double(min(v[i].second + 1, m) - v[i].first) / double(i + 1));
            // cout<<"Adding: "<<adding<<endl;
            res += ceil(double(min(v[i].second + 1, m) - v[i].first) / double(i + 1));
        }
        // cout<<res<<endl;
    }
    return res;
}
int32_t main() {
    cin>>n>>k;
    k--;
    v.assign(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) {
        v[i].first = i + 1;
        v[i].second = n * (i + 1);
    }
    int l = 1, r = 1e11;
    // int i = 100;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        // cout<<"M: "<<m<<endl;
        int x = calc(m);
        if (x <= k) l = m;
        else r = m;
    }
    cout<<l;
    return 0;
}