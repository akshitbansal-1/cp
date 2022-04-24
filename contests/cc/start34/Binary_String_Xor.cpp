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

bool check(int target, int n, int k, string &s) {
    int x = 0, c = 0, i;
    for (i = 0; i < n; i++) {
        x ^= (s[i] - '0');
        if (k == 1) {
            break;
        } else {
            if (x == target) {
                k--;
                x = 0;
            }
        }
    }
    if (i == n) {
        return false;
    }
    // dbg(i);
    x = 0;
    for (; i < n; i++) {
        x ^= (s[i] - '0');
    }
    return x == target;
}

void run_case() {
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    cout<<(check(0, n, k, s) || check(1, n, k, s) ? "YES" : "NO")<<endl;
    dbg();
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