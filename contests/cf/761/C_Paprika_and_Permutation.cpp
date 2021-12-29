/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<priority_queue>
#include<algorithm>
using namespace std;
#define int long long int
void solve() {
    int n, c = 0;
    cin>>n;
    priority_queue<int> pq1, pq2;
    vector<int> in(n);
    for (int i = 0; i < n; i++) cin>>in[i];
    vector<int> v(n + 1, 0);
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (in[i] <= n && v[i] == 0) {
            v[i] = 1;
        } else pq1.insert(nums[i]);
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) pq2.push(i);
    }
    int t = pq2.size();
    while (t--) {
        c++;
        int x1 = pq1.top();
        int x2 = pq2.top();
        if (x1 < (x2 + 1) / 2) {
            pq1.pop();
            pq2.pop();
        }
    }
    if (t == -1) {
        cout<<c<<endl;
    } else {
        cout<<-1<<endl;
    }

}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}