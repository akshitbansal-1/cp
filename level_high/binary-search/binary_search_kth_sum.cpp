#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
#define int long long int
int n, k;
vector<int> v1, v2;
int calc(int m) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int tsum = (i + 1) * (v1[i] + v2[i]);
        if (m <= tsum) res += 0;
        else res += pow(i + 1, 2);
    }
    return res;
}
int32_t main() {
    cin>>n>>k;
    k--;
    v1.assign(n, 0);
    v2.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin>>v1[i];
    }
    for (int i = 0; i < n; i++) {
        cin>>v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; i++) {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++) {
        cout<<v2[i]<<" ";
    }
    cout<<endl;
    for (int i = 1; i < n; i++) {
        v2[i] = v2[i] + v2[i - 1];
        v1[i] = v1[i] + v1[i - 1];
    }
    for (int i = 0; i < n; i++) {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++) {
        cout<<v2[i]<<" ";
    }
    cout<<endl;
    int l = 1, r = 2 * n * n + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        int x = calc(m);
        if (x <= k) l = m;
        else r = m;
    }
    cout<<l;
    return 0;
}