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

vector<pair<int, int>> vp;
bool possible = false;
void check(vector<bool> &v, int sum, int c, int &k) {
    if (possible) return;
    if (sum == k && c == v.size() && !possible) {
        possible = true;
        for (auto x: vp) {
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]) continue;
        v[i] = true;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j]) continue;
            v[j] = true;
            vp.push_back(make_pair(i, j));
            check(v, sum + (i & j), c + 2, k);
            vp.pop_back();
            v[j] = false;
        }
        v[i] = false;
    }
}

void run_case() {
    int n, k;
    cin>>n>>k;
    vector<bool> vis(n, 0);
    if (k == n - 1) {
        if (n == 4) {
            cout<<-1<<endl;
            return;
        }
        vis[n - 1] = vis[n - 2] = 1;
        vis[1] = vis[5] = 1;
        vis[0] = vis[n - 6] = 1;
        cout<<0<<" "<<n-6<<endl;
        cout<<n-1<<" "<<n-2<<endl;
        cout<<1<<" "<<5<<endl;
    } else if (k) {
        vis[k] = vis[n - 1] = 1;
        vis[0] = vis[n - k - 1] = 1;
        cout<<k<<" "<<n - 1<<endl;
        cout<<0<<" "<<n - k - 1<<endl;
    }
    for (int i = 0; i < n / 2; i++) {
        if (!vis[i]) {
            cout<<i<<" "<<n - 1 - i<<endl;
        }
    }
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