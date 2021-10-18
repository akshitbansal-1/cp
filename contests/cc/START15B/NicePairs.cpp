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
    string s;
    cin>>s;
    int c = 0;
    FOR(i, n) {
        FOR(j, 10) {
            if (j > 0 && i + j < n) {
                if (abs(s[i] - s[i + j]) == j) c++;
            }
        }
    }
    cout<<c<<endl;

}
int32_t main() {
    int t;
    cin>>t;
    FOR(i, t) {
        solve();
    }
}
