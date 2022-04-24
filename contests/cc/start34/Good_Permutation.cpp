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
    int x = 0, z = 1;
    vector<int> v(n);
    if (n == 1 || n ==3) cout<<-1;
    else if (n%2) {
        vector<int> t;
        for (int i = 0; i < n; i++) {
            if (i == 3 || i == 4 || i == 2);
            else t.push_back(i+1);
        }
        cout<<"4 3 5 ";
        for (int i = 0; i < n - 3; i++) {
            if (i + 3 + 1 == t[i]) {
                reverse(t.begin() + i, t.end());
                break;
            }
        }
        for (int i = 0; i < n-3; i++) {
            cout<<t[i]<<" ";
        }
        v[0] = 4, v[1] = 3, v[2] = 5;
        for (int i = 3; i < n; i++) {
            v[i] = t[i-3];
        }
    }
    else
        for (int i = n; i >= 1; i--) {
            cout<<i<<" ";
            v[n-i] = i;
        }
    z = 1;
    for (int i = 0; i < n; i++) {
        x ^= abs(v[i] - z++);
    }
    dbg(x);
    cout<<endl;
    // cout<<x<<endl;
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