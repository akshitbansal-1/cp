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

vector<int> fib(51);
void run_case() {
    int n;
    cin>>n;
    vector<int> v(n);
    int z = 0;
    for (int i = 0; i < n; i++) {
        z++;
        if (i == 2) z--;
        v[i] = z;
    }
    v[2] = n;
    dbg(v);
    int k = n, t = 0;
    while (k--) {
        // dbg(v);
        t++;
        next_permutation(v.begin(), v.end());
        bool b = false;
        for (int i = 2; i < n; i++) {
            if (v[i] == v[i - 1] + v[i - 2]) {
                b = true;
                break;
            }
        }
        if (b) {
            k++;
        } else {
            for (int x: v) cout<<x<<" ";
            cout<<endl;
        }
    }
    dbg(t);
}
int32_t main() {
    ios::sync_with_stdio(false);
#ifndef AKSHIT_DEBUG
    cin.tie(nullptr);
#endif
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 51; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int tests = 1;
    cin >> tests;
 
    while (tests--)
        run_case();

}