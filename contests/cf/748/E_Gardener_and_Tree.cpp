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
    vector<bool> visited;
    Graph(int n){adj.assign(n,vector<T>());visited.assign(n, false);}
    void add(T a, T b){adj[a].pb(b),adj[b].pb(a);}
    void dfs(T src);
};
template <class T>
void Graph<T>::dfs(T src){
    Graph::visited[src] = true;
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

void bfs(queue<int> &q, vi &visited, vi &a) {
    for(int i = 0; i < visited.size(); i++){
        visited[i] = 0;
        if(a[i] == 1 || a[i] == 0){
            visited[i]=1;
            q.push(i);
        }
    }
}

void solve() {
    int n, k;
    cin>>n>>k;
    vi arr[n];
    vi a(n, 0);
    FOR(i, n -1){
        int u,v;
        cin>>u>>v;
        arr[u-1].push_back(v-1);
        arr[v-1].push_back(u-1);
        a[u-1]++;
        a[v-1]++;
    }
    queue<int> q;
    vi visited(n);
    bfs(q, visited, a);
    int ans = n;
    while (ans > 0 && k > 0) {
        queue<int> q1;
        while(!q.empty()){
            ans--;
            int x = q.front();
            q.pop();
            for(int i : arr[x]){
                a[i]--;
                if(a[i] == 1 || a[i] == 0 && visited[i] == 0){
                    visited[i] = 1;
                    q1.push(i);
                }
            }
        }
        q = q1;
        k--;
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
