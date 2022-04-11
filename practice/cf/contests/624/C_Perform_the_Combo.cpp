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
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> p(n, 0);
    for (int i = 0; i < m; i++) {int a; cin>> a; p[a]++;}
    vector<int> ans(26, 0), temp(26, 0);
    int prev = -1;
    // for (int i = 0; i < n; i++) cout<<p[i]<<" ";
    // cout<<endl;
    for (int i = 0; i < n; i++) {
        if (p[i]) {
            for (int j = 0; j < 26; j++) {
                if (ans[j]) ans[j] += temp[j] * p[i];
            }
        }
        ans[s[i] - 'a']++;
        temp[s[i] - 'a']++;
    }
    for (int x: ans) cout<<x<<" ";
    cout<<endl;
    // cout<<endl;
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