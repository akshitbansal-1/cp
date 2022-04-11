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

int calc(vector<int> &a, vector<int> &b) {
    int n = a.size();
    
    int ans = min(abs(a[0] - b[0]) + abs(a[n-1] - b[n-1]),
        abs(a[0] - b[n-1]) + abs(a[n-1] - b[0]));
    int d1 = LLONG_MAX, d2 = LLONG_MAX, d3 = LLONG_MAX, d4 = LLONG_MAX;
    
    for (int i = 0; i < n; i++) {
        d1 = min(d1, abs(a[0] - b[i]));
    }
    for (int i = 0; i < n; i++) {
        d2 = min(d2, abs(a[n-1] - b[i]));
    }
    for (int i = 0; i < n; i++) {
        d3 = min(d3, abs(b[0] - a[i]));
    }
    for (int i = 0; i < n; i++) {
        d4 = min(d4, abs(b[n-1] - a[i]));
    }
    
    int a0 = d1, a1 = d2, b0 = d3, b1 = d4;

    ans = min({1LL * ans, 1LL * std::abs(a[0] - b[0]) + a1 + b1,
        1LL * std::abs(a[0] - b[n - 1]) + a1 + b0,
        1LL * std::abs(a[n - 1] - b[0]) + a0 + b1,
        1LL * std::abs(a[n - 1] - b[n - 1]) + a0 + b0});
    
    ans = std::min(1LL * ans, 1LL * a0 + a1 + b0 + b1);
    return ans;
}
void run_case() {
    int n;
    cin>>n;
    
    vector<int> r1(n), r2(n);
    for (int i = 0; i < n; i++) {
        cin>>r1[i];
    }
    for (int i = 0; i < n; i++) {
        cin>>r2[i];
    }

    int ans = calc(r1, r2);
    
    // int ans = 0;
    // int ans = abs(r1[0] - r2[0]) + abs(r1[n-1] - r2[n-1]); 
    cout<<ans<<endl;
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