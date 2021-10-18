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
#define FOR(i, n) for (int i = 0; i < n; i++)
#define vin(v, n) for (int i = 0; i < n; i++) cin>>v[i];

void solve() {
    int n;
    cin>>n;
    if (n == 0) {cout<<2<<endl<<"1 1"<<endl;return;}
    int j = 1;
    vi v;
    for (int i = 61; i >= 0; i--) {
        if (j % 2 == 1 && (1ll << i) & n) {
            v.pb((1ll << i + 1) - 1);
            j++;
        } else if (j % 2 == 0 && ((1ll << i) & n) == 0) {
            v.pb((1ll << i + 1) - 1);
            j++;
        }
    }
    cout<<v.size()<<endl;
    int x = 0;

    FOR(i, v.size()) cout<<v[i]<<" ";
    cout<<endl;

}
int32_t main() {
    int t;
    cin>>t;
    FOR(i, t) {
        solve();
    }
}
