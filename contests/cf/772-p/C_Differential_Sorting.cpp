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
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    if (is_sorted(v.begin(), v.end())) {
        cout<<0<<endl;
        return;
    }
    if (n > 1 && v[n - 2] > v[n - 1]) {
        cout<<-1<<endl;
        return;
    }
    int mty = -1;
    vector<vector<int>> ans;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i] > v[i + 1]) {
            mty = i;
            break;
        }
    }
    dbg(mty);
    if (mty == -1) {
        cout<<0<<endl;
        return;
    }
    if (mty >= n - 2 || v[mty + 1] - v[n - 1] > v[mty + 1]) {
        cout<<-1<<endl;
        return;
    }
    cout<<mty + 1<<endl;
    for (int i = mty; i >= 0; i--) {
        cout<<i + 1<<" "<<i+2<<" "<<n<<endl;
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