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
    // string s;
    // cin>>s;
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> v(m);
    map<int, int> mp;
    for (int i = 0 ;i < m ;i++) {
        cin>>v[i].second>>v[i].first;
        mp[v[i].second] = i;
    }
    dbg(v);
    sort(v.begin(), v.end());
    dbg(v);
    int sum = 0;
    dbg(v.size());
    for (int i = 0; i < 2 * n; i++) {
        sum += v[i].first;
    }
    cout<<sum<<endl;
    vector<int> pts;
    for (int i = 0; i < 2 * n; i++) {
        pts.push_back(v[i].second);
    }
    sort(pts.begin(), pts.end());
    dbg(pts);
    for (int i = 0, j = 2 * n - 1; i < j; i++, j--) {
        cout<<mp[pts[i]] + 1<<" "<<mp[pts[j]] + 1<<endl;
    }
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