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
    int n, h, sum = 0;
    cin>>h>>n;
    vi v(n), diff(n);
    vin(v, n);
    FOR(i, n) {
        // cout<<v[i]<<" ";
        diff[i] = h - v[i];
        sum += v[i];
    }
    sort(all(v));
    // FOR(i, n) cout<<v[i]<<" ";
    // cout<<endl;
    int cat = 0, mice = n - 1;
    while (mice >= 0 && cat < v[mice]) {
        cat += h - v[mice--];
    }
    // if (cat < mice && cat <=)
    cout<<n - mice - 1<<endl;

}
int32_t main() {
    int t;
    cin>>t;
    FOR(i, t) {
        solve();
    }
}
