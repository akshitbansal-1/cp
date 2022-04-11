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
    int n, x, y;
    cin>>n>>x>>y;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    vector<int> suff(n), add(n, 0);
    add[0] = v[0];
    for (int i = 1; i < n; i++) add[i] = add[i - 1] + v[i];
    suff[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--) suff[i] = suff[i + 1] ^ v[i];
    dbg(add, suff);
    for (int i = 0; i < n - 1; i++) {
        if (((x + add[i]) ^ (suff[i + 1])) == y) {
            cout<<"Alice"<<endl;
            return;
        }
    }
    if ((x + add[n - 1]) == y || ((suff[0] ^ x) == y)) {
        cout<<"Alice\n";
        return;
    }
    cout<<"Bob\n";
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