#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int n, k;
vector<pair<int, int> > v;
double check(double m) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        s += abs(m - v[i].first) / v[i].second;
    }
    cout<<s<<endl;
    return s;
}

//unfinished
void solve(double start, double end) {
    double ans = 0;
    double delta = 1e-9;
    // cout<<start<<" "<<end;
    for (int i = 0; i <=50; i++) {
        double m = (start + end) / 2.0;
        double t = check(m);
        double t1 = check(m + 1);
        if (t <= t1) {
            end = m;
        } else {
            start = m;
        }
    }
    cout <<start << end;
}
int32_t main() {
    cin>>n;
    // cin>>k;
    v.assign(n, make_pair(0, 0));
    int mi = 1e9, ma = -1e9;
    for (int i = 0; i < n; i++) {
        cin>>v[i].first;
        cin>>v[i].second;
        mi = min(mi, v[i].first);
        ma = max(ma, v[i].first);
    }
    solve(-1e9, 1e9);
}

