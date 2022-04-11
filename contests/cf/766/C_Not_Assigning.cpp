#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<class Fun> class y_combinator_result {Fun fun_;public:template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }};template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef AKSHIT_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define int long long int

unordered_map<int, int> mp;
int curr = 2;
map<pair<int, int>, int> ans;
void dfs(vector<vector<int>> &v, vector<bool> &vis, int src) {
    if (vis[src]) return;

    vis[src] = true;
    // curr = mp[curr];
    for (int x: v[src]) {
        if (!vis[x]) {
            ans[make_pair(src, x)] = curr;
            ans[make_pair(x, src)] = curr;
            int t = curr;
            curr = mp[curr];
            dfs(v, vis, x);
            curr = mp[t];
        }
    }
}
void run_case() {
    int n;
    cin >> n;
    ans.clear();
    mp.clear();
    curr = 2;
    mp[2] = 3;
    mp[3] = 2;
    vector<vector<int>> v(n);
    vector<pair<int, int>> in;
    vector<int> idg(n, 0);
    vector<bool> vis(n, false);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin>>a>>b;
        in.push_back(make_pair(a-1, b-1));
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
        idg[a-1]++;
        idg[b-1]++;
    }
    for (int i = 0; i < n; i++) {
        if (idg[i] > 2) {
            cout<<-1<<endl;
            return;
        }
    }
    for (int i = 0; i < n; i++)
        dfs(v, vis, i);
    for (int i = 0; i < n - 1; i++) {
        cout<<ans[in[i]]<<" ";
    }
    cout<<endl;

}
int32_t main() {
    ios::sync_with_stdio(false);
#ifndef AKSHIT_DEBUG
    cin.tie(nullptr);
#endif
 
    int tests = 1;
    cin >> tests;
 
    while (tests--)
        run_case();

}