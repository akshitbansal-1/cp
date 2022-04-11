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


struct midE {
    int len;
    int pos;
    int step;
};

midE f(vector<int> & v) {
    midE best = { -1, 0, 0 };
    if(v.size() < 3) { best.len = v.size(); return best; }
    for (double i = 1; i < v.size(); ++i) {
        unordered_map<double, double> bestForStep;
        for (double j = 0; j < i; ++j) {
            double step = (v[i] - v[j]) / (i - j);
            if (step * (i - j) == v[i] - v[j]) {
                // This j gives an integer step size: record that j lies on this AP
                int len = ++bestForStep[step];
                if (len > best.len) {
                    best.len = len;
                    best.pos = i;
                    best.step = step;
                }
            }
        }
        dbg(bestForStep);
    }

    ++best.len;     // We never counted the final element in the AP
    return best;
}
int costAP(vector<int> arr) {
    if(arr.size() < 3) { return 0; }
    int minCost = arr.size();
    for(double i = 0; i < arr.size() - 1; i++) {
        for(double j = i + 1; j < arr.size(); j++) {
            double delta = (arr[j] - arr[i]) / (j - i);
            int cost = 0;
            for(int k = 0; k < arr.size(); k++) {
                if(k == i) { continue; }
                if((arr[k] + delta * (i - k)) != arr[i]) { cost++; }
            }
            if(cost < minCost) { minCost = cost; }
        }
    }
    return minCost;
}
void run_case() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    // cout<<costAP(v)<<endl;
    cout<<n - f(v).len<<endl;
    // if (n < 3) {
    //     cout<<0<<endl;
    //     return;
    // }
    // vector<int> diffs(n - 1);
    // map<int, int> mp;
    // for (int i = 0; i < n - 1; i++) {
    //     mp[v[i] - v[i + 1]]++;
    //     diffs[i] = v[i] - v[i+ 1];
    // }
    // dbg(diffs);
    // // dbg(mp);
    // if (mp.size() == 1) {
    //     cout<<0<<endl;
    //     return;
    // }
    // int mx = 0, mxf = INT_MIN, ans = 0;
    // for (auto x: mp) {
    //     if (x.second > mx) {
    //         mxf = x.first;
    //         mx = x.second;
    //     }
    // }
    // // dbg(mxf);
    // for (int i = 0; i < n - 1; i++) {
    //     if (diffs[i] != mxf) ans++;
    // }
    // cout<<ans<<endl;
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