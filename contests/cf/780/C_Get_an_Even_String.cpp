#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<class Fun> class y_combinator_result {Fun fun_;public:template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }};template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef AKSHIT_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define all(x) (x).begin(), (x).end()
#define isEven(x) (x % 2 == 0)
#define int long long int


void run_case() {
    int n;
    string s;
    cin>>s;
    n = s.length();
    vector<vector<int>> v(n, vector<int>(26, INT_MAX));
    for (int i = n - 2; i >= 0; i--){
        for (int j = 0; j < 26; j++) {
            if (s[i] == 'a' + j) {
                v[i][j] = 1;
            } else if (v[i][j] != INT_MAX) {
                v[i][j] = v[i][j] + 1;
            }
        }
    }
    int op = 0;
    for (int i = 0; i < n - 1; i++){
        int d = s[i] - 'a';
        if (v[i][d] == i + 1) {
            i++;
        } else if (v[i][d] != INT_MAX) {
            int j;
            for (j = i + 1; j < min(v[i][d], n))
        } else op++;
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