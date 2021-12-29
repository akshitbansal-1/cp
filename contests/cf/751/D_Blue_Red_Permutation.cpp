#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define f first
#define s second
template <class T>
class Graph{
    public:
    vector<vector<T>> adj;
    vector<bool> vis;
    Graph(int n){adj.assign(n,vector<T>());vis.assign(n, false);}
    void add(T a, T b){adj[a].pb(b),adj[b].pb(a);}
    void dfs(T src);
};
template <class T>
void Graph<T>::dfs(T src){
    Graph::vis[src] = true;
    for (T x: Graph::adj[src]){dfs(x);}
}
#define all(x) x.begin(), x.end()
#define vb vector<bool>
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FORC(i, n, cond) for (int i = 0; i < n && cond; i++)
#define vin(v, n) for (int i = 0; i < n; i++) cin>>v[i];
#define umii unordered_map<int, int>
#define mii map<int, int>
#define usi unordered_set<int>


void solve() {
    int n;
    cin>>n;
    vector<pair<int, char>> vp(n);
    for (int i = 0; i < n; i++) {
        cin>>vp[i].first;
    }
    string s;
    cin>>s;
    for (int i = 0; i < n; i++) {
        vp[i].second = s[i];
    }
    sort(all(vp), greater<pair<int, char>>());

    for (int i = 0; i < n; i++) {
        cout<<vp[i].first<<" ";
    }
    cout<<endl;
    for (int i = 0; i < n; i++) {
        cout<<vp[i].second<<" ";
    }
    cout<<endl;
}
int32_t main() {
    int t;
    cin>>t;
    FOR(i, t) {
        solve();
    }
}