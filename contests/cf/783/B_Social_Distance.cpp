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
 
 
// void run_case() {
//     int n, m;
//     cin>>n>>m;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++) cin>>v[i];
//     sort(v.begin(), v.end());
//     int sum = 1+v[0]*2, a;
//     for (int i  = 1; i < n; i++) {
//         // int a;
//         // cin>>a;
//         if (sum >= m) {
//             cout<<"NO\n";
//             return;
//         }
//         if (v[i] > v[i-1]) {
//             sum += v[i]*2-(v[i]-v[i-1]);
//         } else {
//             sum += v[i]+1;
//         }
//     }
//     if (sum <= m + v[0]) cout<<"YES\n";
//     else cout<<"NO\n";
// }
void run_case() {
    int n, m;
    cin>>n>>m;
    
    int sum = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    if (n >= m) {
        cout<<"NO\n";
        return;
    }
    sort(v.begin(), v.end());
    dbg(v);
    int start = v[0] + 1, astart = start, next = start*2;
    dbg(start);
    for (int i  = 1; i < n; i++) {
        int ndiff = max(next, start + v[i]+1);
        start = ndiff;
        dbg(start);
        next = start + v[i] + 1 - (i == n - 1);
        if (next > m) {
            dbg(next, m+astart);
            if (i == n-1 && next < m + astart) {
                cout<<"YES\n";
                return;
            } else {
                cout<<"NO\n";
                return;
            }
        }
    }
    dbg("");
    if (next < m + astart) {
        cout<<"YES\n";
        return;
    } else {
        cout<<"NO\n";
        return;
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