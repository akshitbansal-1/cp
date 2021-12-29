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

// bool cmp1 (int a, int b) {
//     dbg(z[a], z[b]);
//     return z[a] < z[b];
// }
// bool cmp2 (int a, int b) {
//     return o[a] < o[b];
// }

void run_case() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    string s;
    cin>>s;
    
    vector<int> z, o;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') z.push_back(i);
        else o.push_back(i);
    }
    auto x1 = [&](int a, int b) {
        return v[a] < v[b];
    };
    auto x2 = [&](int k, int l) {
        return v[k] < v[l];
    };
    sort(z.begin(), z.end(), x1);
    sort(o.begin(), o.end(), x2);
    vector<int> ans(n);
    dbg(z);
    dbg(o);
    int c = 1, idx = 0;
    for (int i = 0; i < z.size(); i++) {
        ans[z[i]] = c++;
    }
    for (int i = 0; i < o.size(); i++) {
        ans[o[i]] = c++;
    }
    for (int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;

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