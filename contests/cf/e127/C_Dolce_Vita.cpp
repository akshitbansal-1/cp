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


int check(int sum, int d, int t, int sz) {
    sum = sum + sz * d;
    if (sum > t) return 0;
    int l = 0, r = 1e9, ans = 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (sum + sz * mid > t) {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }
    return (ans + 1);
}

void run_case() {
    int n, t;
    cin>>n>>t;
    int ans = 0;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
        sum += v[i];
    }
    sort(all(v));
    int res = 0;
    while (v.size()) {
        int temp = check(sum, ans, t, v.size());
        res += temp * v.size();
        ans += temp;
        sum -= v[v.size() - 1];
        v.pop_back();
    }
    cout<<res<<endl;
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