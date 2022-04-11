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

// int check(int n) {
//     queue<int> q;
//     q.push(n);
//     int c = 0;
//     set<int> vis;
//     while (true) {
//         int x = q.front();
//         q.pop();
//         vis.insert(x);
//         dbg(x);
//         if (x % 32768 == 0) return c;
//         if (vis.find((x + 1) % (32768)) == vis.end()) {
//             q.push((x + 1) % (32768));
//             vis.insert((x + 1) % (32768));
//         }
//         if (vis.find((x * 2) % (32768)) == vis.end()) {
//             q.push((x * 2) % (32768));
//             vis.insert((x * 2) % (32768));
//         }
//     }
//     return 0;
// }
// int MAX = 2*32679;
// vector<int> ans(MAX, 0);
void run_case() {
    int n;
    cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) cin>>v[i];
    for (int i = 0; i < n; i++) {
        int ans = INT_MAX, x = v[i];
        if (x % 32768 == 0) {
            cout<<"0 ";
            continue;
        }
        for (int c = 1; c <= 15; c++) {
            bool found = false;
            for (int j = c, k = 0; j>=0; j--,k++) {
                int t = ((x+j)<<k)%32768;
                if (t == 0) {
                    found = true;
                    cout<<c<<" ";
                    break;
                }
            }
            if (found) break;
        }
        
    }
    cout<<endl;
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