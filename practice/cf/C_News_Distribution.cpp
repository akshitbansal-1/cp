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

int find(int a, vi &v) {
    if (a != v[a]) v[a] = find(v[a], v);
    return v[a];
}

void _union(int a, int b, vi &v, vi &r) {
    a = find(a, v);
    b = find(b, v);
    if (a != b) {
        r[a] += r[b];
    }
    v[b] = v[a];
}



void solve() {
    int n;
    cin>>n;
    vi v(n + 1, -1), r(n + 1, 1);
    FOR(i, n + 1) v[i] = i;
    int m;
    cin>>m;
    while (m--) {
        int k;
        cin>>k;
        int prev = -1;
        while (k--) {
            int a;
            cin>>a;
            if (prev == -1) prev = a;
            _union(prev, a, v, r);
        }
    }
    for(int i = 1; i <= n; i++) cout<<r[find(i, v)]<<" ";

}
int32_t main() {
    int t;
    t = 1;
    FOR(i, t) {
        solve();
    }
}
