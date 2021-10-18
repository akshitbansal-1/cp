//https://codeforces.com/problemset/problem/580/C
//unfinished
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
vector<int> v;
vector<bool> vis;
int ans;
vector<vector<int> > t;
void dfs(int src, bool count, int cats) {
    // cout<<src<<endl;
    if (cats > m) return;
    if (t[src].size() == 0) ans++;
    for (int x: t[src]) {
        // cout<<src<<"->"<<x<<endl;
        int curr = v[x];
        if (v[x] && count) curr += cats;
        else curr = 0;
        dfs(x, v[src] == 1, curr);
    }
}
int main() {
    ans = 0;
    cin>>n>>m;
    v.assign(n + 1, 0);
    vis.assign(n + 1, false);
    for (int i = 1; i <= n; i++) cin>>v[i];
    t.assign(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;cin>>a>>b;
        t[a].push_back(b);
    }
    if (t[1].size())
        dfs(1, v[1] == 1, v[1]);
    cout<<ans;
}