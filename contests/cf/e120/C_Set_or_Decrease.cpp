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

int d(vector<int> &v, int m, int n, int k, int sum) {
    int i = n - 1;
    while (i >= 1 && sum > k) {
        sum = sum - v[i--] + m;
    }
    dbg(sum);
    if (sum > k) return -2;
    return i;
}
void run_case() {
    int n, k, sum = 0;
    cin>>n>>k;
    vector<int> v(n);
    // map<int, int> um;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
        // um[v[i]]++;
        sum += v[i];
    }
    sort(begin(v), end(v));
    
    dbg(v);
    if (sum <= k) {
        cout<<0<<endl;
        return;
    }
    if (n == 1) {
        cout<<(v[0] - k)<<endl;
        return;
    }
    int l = -1e15, r = v[0], m;
    dbg(l, r);
    int ans = 1e16;
    while (l <= r) {
        m = (l + r) / 2;
        int diff = d(v, m, n, k, sum - v[0] + m);
        if (diff == -2) r = m - 1;
        else {
            diff++;
            dbg(l, r);
            ans = min(ans, v[0] - m + n - diff);
            l = m + 1;
        }
        dbg(diff);
    }
    dbg(ans);
    cout<<ans<<endl;
    // dbg(r);

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