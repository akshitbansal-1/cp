/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
        sum += v[i];
    }
    int s1 = (n + 1) * n / 2;
    if (sum % s1 != 0) {
        cout<<"NO"<<endl;
        return;
    }
    int s = sum / s1;
    vector<int> temp;
    for (int i = 1; i < n; i++) temp.push_back(v[i] - v[i - 1]);
    temp.push_back(v[0] - v[n - 1]);
    vector<int> a(n, 0);
    for (int i = 1; i <= n; i++) {
        int idx = i % n;
        a[idx] = s - temp[i - 1];
        if (a[idx] % n != 0) {
            cout<<"NO\n";
            return;
        }
        a[idx] /= n;
        if (a[idx] <= 0) {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
    for (int i = 0; i < n; i++) cout<<a[i]<<" ";
    cout<<endl;
}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}