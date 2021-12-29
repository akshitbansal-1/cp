#include<iostream>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int n, k;
vector<int> v;
bool check(int m) {
    int s = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > m) return false;
        s += v[i];
        if (s > m) {
            c++;
            s = v[i];
        }
    }
    c++;
    return c <= k;
}


void solve(int start, int end) {
    int ans = 0;
    while (start + 1 < end) {
        int m = (start + end) / 2;
        if (check(m)) {
            end = m;
        } else {
            start = m;
        }
    }
    cout << end;
}
int32_t main() {
    cin>>n;
    cin>>k;
    v.assign(n, 0);
    int m = 0, s = 0;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
        m = max(m, v[i]);
        s += v[i];
    }
    solve(m, s);
}

