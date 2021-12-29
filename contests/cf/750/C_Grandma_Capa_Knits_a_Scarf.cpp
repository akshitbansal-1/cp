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


int solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vb b(26, false);
    for (int i = 0; i < n; i++) {
        b[s[i] - 'a'] = true;
    }
    int st = 0, e = n - 1;
    bool k = true;
    while (st < e) {
        if (s[st] != s[e]) {k = false; break;}
        st++; e--;
    }
    if (k) return 0;
    int ans = INT_MAX;
    for (int i = 0; i < 26; i++) {
        if (b[i]) {
            int st = 0, e = n - 1;
            int c = 0;
            while (st < e) {
                if (s[st] == s[e]) {st++; e--; continue;}
                int stt = st, et = e;
                bool m1 = false, m2 = false;
                int rm1 = INT_MAX, rm2 = INT_MAX;
                while (stt <= et) {
                    if (s[stt]==s[et]) {
                        rm1 = stt - st;
                        m1 = true;
                        break;
                    }
                    if (s[stt] != i + 'a') break;
                    stt++;
                }
                
                int st2 = st, e2 = e;
                while (st2 <= e2) {
                    if (s[st2]==s[e2]) {
                        rm2 = e - e2;
                        m2 = true;
                        break;
                    }
                    if (s[e2] != i + 'a') break;
                    e2--;
                }
                if (!m1 && !m2) {
                    c = -1;
                    break;
                }
                if (rm1 <= rm2) {
                    c += stt - st;
                    st = stt;
                } else {
                    c += e - e2;
                    e = e2;
                }
            }
            if (c > 0) ans = min(c, ans);
        }
    }
    return ans == INT_MAX ? -1 : ans;
}
int32_t main() {
    int t;
    cin>>t;
    FOR(i, t) {
        cout<<solve()<<endl;
    }
}
