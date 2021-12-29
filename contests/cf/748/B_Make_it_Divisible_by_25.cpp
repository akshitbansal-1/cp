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
    string s;
    cin>>s;
    int i, c = 0;
    for (i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '0') break;
        c++;
    }
    for (int j = i - 1; j >= 0; j--) {
        if (s[i] == '0'){
            if (s[j] == '5') break;
            if (s[j] == '0' && j >= 1) break;
        }
        c++;
    }
    int c1 = c;
    c = 0;
    for (i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '5') break;
        c++;
    }
    for (int j = i - 1; j >= 0; j--) {
        if (s[i] == '5' && (s[j] == '2' || s[j] == '7')) break;
        c++;
    }
    cout<<min(c, c1)<<endl;
    

}
int32_t main() {
    int t;
    cin>>t;
    FOR(i, t) {
        solve();
    }
}
