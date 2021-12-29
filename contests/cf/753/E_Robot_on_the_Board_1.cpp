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
    int m,n;
    cin>>n>>m;
    string s;
    cin>>s;
    int i = 0;
    int ml = 0, mr = 0, mt = 0, mb = 0, currx = 0, curry = 0;

    while (i < s.length()) {
        
        switch(s[i]) {
            case 'L': currx--; break;
            case 'R': currx++; break;
            case 'U': curry--; break;
            case 'D': curry++; break;
        }
        i++;
        if (abs(min(ml, currx)) + abs(max(mr, currx)) >= m || abs(min(mt, curry)) + abs(max(mb, curry)) >= n) {
            cout<<min(abs(mt) + 1, n)<<" "<<min(abs(ml) + 1, m)<<endl;
            i = 0;
            break;
        }
        ml = min(ml, currx);
        mr = max(mr, currx);
        mt = min(mt, curry);
        mb = max(mb, curry);
    }
    if (i == s.length()) {
        cout<<min(abs(mt) + 1, n)<<" "<<min(abs(ml) + 1, m)<<endl;
    }
}
int32_t main() {
    int t;
    cin>>t;
    FOR(i, t) {
        solve();
    }
}
