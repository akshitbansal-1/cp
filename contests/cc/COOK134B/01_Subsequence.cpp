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
    vi v(n), v2, v3;
    vin(v, n);
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) v2.pb(v[i]);
        else v3.pb(v[i]);
    }
    sort(all(v2), greater<int>());
    sort(all(v3));
    for (int i = 0; i < n / 2; i++) {
        cout<<v2[i]<<" ";
        cout<<v3[i]<<" ";
    }
    if (n % 2){
        cout << v2[n/2];
    }
    for (int i = n / 2 - 2; i >= 0; i--) {
        v3[i] += v3[i + 1];
    }
    cout<<endl;
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        ans += v2[i] * v3[i];
    }
    

    cout<<ans<<endl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    FOR(i, t) {
        solve();
    }
}
