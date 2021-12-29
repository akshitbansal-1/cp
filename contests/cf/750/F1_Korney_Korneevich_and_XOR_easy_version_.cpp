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


void countSub(vi &arr, int n)
{
    int count[501] = {0};
    
    set<int> st;
    st.insert(0);
    vector<vector<int>> v(501);
    // scan each digit in arr[]
    for (int i=0; i<n; i++)
    {
        st.insert(arr[i]);
        // count all possible sub-sequences by
        // the digits less than arr[i] digit
        int x = 0;
        for (int j=0; j<arr[i]; j++) {
            if (count[j]) {
                x ^= j;
                st.insert(arr[i]^j);
                cout<<i<<" "<<x<<" "<<(arr[i]^j)<<endl;
                st.insert(x);
            }
        }
        // store sum of all sub-sequences plus
        // 1 in count[] array
        count[arr[i]]++;
    }
    // for (int i = 0; i < 501; i++) cout<<count[i]<<" ";
 
    cout<<st.size()<<endl;
    // now sum up the all sequences possible in
    // count[] array
    int result = 0;
    for (int x : st) cout<<x<<" ";
    cout<<endl;
}

void solve() {
    int n;
    cin>>n;
    vi v(n);
    vin(v, n);
    countSub(v, n);
}
int32_t main() {
    int t = 1;
    
    FOR(i, t) {
        solve();
    }
}
