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
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int q;
    cin >> q;

    vector<vector<int>> takes(n+1, vi(n));
    unordered_map<int, int> mp, mp1;

    for (int i = 0; i < n; i++){
        takes[0][i] = v[i];
        mp[v[i]] += 1;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j < n; j++){
            takes[i][j] = mp[takes[i-1][j]];
            mp1[takes[i][j]] += 1;
        }
        mp.clear();
        mp = mp1;
        mp1.clear();
    }

    while(q--){
        int a, b;
        cin >> a >> b;

        int idx = min(b, n);
        cout << takes[idx][a-1] << "\n";
    }
}
int32_t main() {
    int t;
    cin>>t;
    FOR(i, t) {
        solve();
    }
}
