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

int check(vector<int> &v) {
    int op = 0, n = v.size();
    for (int i = 1; i < n - 1; i++) {
        if (v[i] > v[i + 1] && v[i] > v[i - 1]) {
            if (i + 2 < n) {
                v[i + 1] = max(v[i + 1], v[i + 2]);
                op++;
            } else {
                v[i] = max(v[i + 1], v[i - 1]);
                op++;
            }
        }
    }
    return op;
}
void run_case() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }

    bool isPeak = false;
    int op = 0;//, n = v.size();
    for (int i = 1; i < n; i++) {
        if (i < n - 1 && v[i] > v[i + 1] && v[i] > v[i - 1]) {
            isPeak = true;
        }
        else if (isPeak) {
            isPeak = false;
            op++;
            v[i] = max(v[i < n - 1 ? i + 1 : i], v[i - 1]);
        }
    }
    cout<<op<<endl;
    // return op;
    for (int i = 1; i < n - 1; i++) {
        if (v[i] > v[i + 1] && v[i] > v[i - 1]) {
            dbg(v, i);
        }
    }
    for (int x: v) cout<<x<<" ";
    cout<<endl;
    
    // vector<int> v1 = v, v2 = v;
    // reverse(v2.begin(), v2.end());
    // int x1 = check(v1);
    // int x2 = check(v2);
    // dbg(x1, x2);
    // if (x1 >= x2) {
    //     cout<<x2<<endl;
    //     for (int x: v2) cout<<x<<" ";
    //     cout<<endl;
    // } else {
    //     cout<<x1<<endl;
    // }
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