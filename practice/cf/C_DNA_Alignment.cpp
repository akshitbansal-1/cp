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


int pow(int a, int b) {
    int ans = 1;
    while (b) {
        if (b % 2) ans *= a;
        ans = (ans * ans) % (int)(1e9+7);
        b /= 2;
    }
    return ans;
}
int32_t main() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    vi v(26, 0);
    FOR(i, n) v[s[i] - 'A']++;
    int m = 0, c = 0;
    FOR(i, 26) m = max(v[i], m);
    FOR(i, 26) if (v[i] == m) c++;
    // cout<<c<<endl;
    int ans = 0;
    // FOR(i, n) {
        ans = pow(c, n) % (int)(1e9 + 7);
        // cout<<ans<<endl;
    // }
    cout<<ans;
}
