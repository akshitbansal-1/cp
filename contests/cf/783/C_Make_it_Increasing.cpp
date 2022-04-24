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
    cin>>n;
    vector<int> v(n);
    for (int i = 0 ; i < n; i++) {
        cin>>v[i];
    }
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
        int op = 0, prev = 0;
        vector<int> t(n, 0);
        // v
        for (int j = i-1; j >= 0; j--) {
            // if (v[j] <= prev) {
                op += abs(prev / v[j]) + 1;
                prev = v[j] * (prev / v[j])-v[j];
            // }
            t[j] = prev;
        }
        prev = 0;
        for (int j = i+1; j < n; j++) {
            // if (v[j] >= prev) {
                op += abs(prev / v[j]) + 1;
                prev = v[j] * (prev / v[j])+v[j];
            // }
            t[j] = prev;
        }
        dbg(t, op);
        res = min(op, res);



        // if (i < n - 1) {
        //     op = 0, prev = 0;
        //     vector<int> t(n, 0);
        //     // v
        //     for (int j = i-1; j >= 0; j--) {
        //         // if (v[j] <= prev) {
        //             op += abs(prev / v[j]) + 1;
        //             prev = v[j] * (prev / v[j])-v[j];
        //         // }
        //         t[j] = prev;
        //     }
        //     prev = 0;
        //     for (int j = i+1; j < n; j++) {
        //         // if (v[j] >= prev) {
        //             op += abs(prev / v[j]) + 1;
        //             prev = v[j] * (prev / v[j])+v[j];
        //         // }
        //         t[j] = prev;
        //     }
        //     dbg(t, op);
        //     res = min(op, res);
        //     dbg(" ");
        // }
        if (i > 0) {
            int t;
            if (v[i - 1] >   v[i]) {
                op = v[i-1] / v[i]+1, t = v[i-1] / v[i] * v[i] + v[i];
            } else{
                op = 0, t = 0;
            }
            prev = t;
            // op = v[i]/v[i-1]+1, prev = 0;
            // vector<int> t(n, 0);
            // v
            for (int j = i-1; j >= 0; j--) {
                // if (v[j] <= prev) {
                    op += abs(prev / v[j]) + 1;
                    prev = v[j] * (prev / v[j])-v[j];
                // }
                // t[j] = prev;
            }
            prev = t;
            for (int j = i+1; j < n; j++) {
                // if (v[j] >= prev) {
                    op += abs(prev / v[j]) + 1;
                    prev = v[j] * (prev / v[j])+v[j];
                // }
                // t[j] = prev;
            }
            dbg(t, op);
            res = min(op, res);
            dbg(" ");
        }
    }
    cout<<res<<endl;
}
int32_t main() {
    ios::sync_with_stdio(false);
#ifndef AKSHIT_DEBUG
    cin.tie(nullptr);
#endif
 
    int tests = 1;
    // cin >> tests;
 
    while (tests--)
        run_case();
 
}