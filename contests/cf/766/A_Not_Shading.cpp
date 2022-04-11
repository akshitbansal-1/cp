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


void run_case() {
    int m,n,r,c;
    cin>>m>>n>>r>>c;
    vector<string> st(m);
    bool can = false;
    for (int i = 0; i < m; i++) {
        cin>>st[i];
        for (int j = 0; j < n; j++) {
            if (st[i][j] == 'B') can = true;
        }
    }
    if (st[r-1][c-1] == 'B') {
        cout<<0<<endl;
        return;
    }
    if (!can) {
        cout<<-1<<endl;
        return;
    }
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (st[r-1][i] == 'B') ans = 1;
    }
    for (int i = 0; i < m; i++) {
        if (st[i][c-1] == 'B') ans = 1;
    }

    if (ans == INT_MAX) {
        cout<<2<<endl;
    } else {
        cout<<1<<endl;
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