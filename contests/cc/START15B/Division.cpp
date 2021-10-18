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
    int n, a, b, n1;
    cin>>n>>a>>b;
    int oddc = 0, evenc = 0; 
    int ans = 0, l = sqrt(n); 
    for (int i = 2; i <= l; i++){  
        while(n % i == 0){ 
            n /= i; 
            i % 2 ? oddc++ : evenc++;
        } 
    } 
    if(n > 1){ 
        n % 2 ? oddc++ : evenc++; 
    } 

    if(a >= 0 && b >= 0) { 
        ans = a * evenc + b * oddc;
    } else if (a >= 0 && b < 0) { 
        if (evenc) ans = a * evenc; 
        else if (oddc) ans = b; 
    } else if (a < 0 && b >= 0) { 
        ans = b * oddc; 
        if (evenc) ans += a;
    } else if (a < 0 && b < 0) { 
        if (evenc) ans += a; 
        else if( oddc) ans += b; 
    } 
    cout<<ans<<endl; 
}
int32_t main() {
    int t;
    cin>>t;
    FOR(i, t) {
        solve();
    }
}
