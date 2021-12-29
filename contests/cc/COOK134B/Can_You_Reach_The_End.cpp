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
    vi v(n + 1, -1);
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin>>a>>b;
        vp.pb(make_pair(a, b));
        v[a] = b;
    }
    bool b = 0;
    for (int i = 0; i < n; i++) {
        b = false;
        int x = vp[i].first - 1, y = vp[i].second + 1;
        int x1 = vp[i].first + 1, y1 = vp[i].second - 1;
        while (x >= 1 && y <= n) {
            if (v[x] != y) {
                // cout<<x<<" "<<y<<endl;
                b = true;
                break;
            }
            v[x] = -1;
            x--,y++;
        }
        while (!b && x1 <= n && y1 >= 1) {
            if (v[x1] != y1) {
                // cout<<x1<<" "<<y1<<endl;
                b = true;
                break;
            }
            v[x1] = -1;
            x1++, y1--;
        }
        if (!b) {
            cout<<"NO\n";
            return;
        }
    }
    
    cout<<"YES\n";
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
