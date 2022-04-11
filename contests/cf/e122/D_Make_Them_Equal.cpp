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
 
vector<int> com(1001, 1e9);
 
int getOps(int start, int end) {
    int m = INT_MAX;
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    vector<bool> vis(1e3 + 1, false);
    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();
        if (top.first == end) {
            m = min(m, top.second);
            break;
        } else if (top.first > end) {
            continue;
        }
        if (top.first + 1 < 1001 && !vis[top.first + 1]) {
            q.push(make_pair(top.first + 1, top.second + 1));
            vis[top.first + 1] = true;
        }
        for (int i = 1; i <= sqrt(top.first); i++) {
            int sum = top.first + top.first/i;
            if ((sum < 1001 && vis[sum]) or sum >= 1001) continue;
            q.push(make_pair(sum, top.second + 1));
            vis[sum] = true;
        }
    }
    return m;
}
int knapSack(int W, vector<int> &wt, vector<int> & val, int n)
{
    int i, w;
    int K[2][W + 1];
    // We know we are always using the the current row or
    // the previous row of the array/vector . Thereby we can
    // improve it further by using a 2D array but with only
    // 2 rows i%2 will be giving the index inside the bounds
    // of 2d array K
 
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i % 2][w] = 0;
            else if (wt[i - 1] <= w)
                K[i % 2][w] = max(
                    val[i - 1]
                        + K[(i - 1) % 2][w - wt[i - 1]],
                    K[(i - 1) % 2][w]);
            else
                K[i % 2][w] = K[(i - 1) % 2][w];
        }
    }
    return K[n % 2][W];
}
void run_case() {
    int n, k;
    cin>>n>>k;
    vector<int> b(n), c(n);
    k = min(k, 12 * n);
    for (int i = 0; i < n; i++) cin>>b[i];
    for (int i = 0; i < n; i++) cin>>c[i];
    vector<int> operations(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] == 1) {
            ans += c[i];
            operations[i] = INT_MAX;
            continue;
        }
        int ops = com[b[i]];
        dbg(ops);
        operations[i] = (ops);
    }
    cout<<ans + knapSack(k, operations, c, n)<<endl;
}
int32_t main() {
    ios::sync_with_stdio(false);
#ifndef AKSHIT_DEBUG
    cin.tie(nullptr);
#endif
    com[1] = 0;
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= i; j++) {
            if (i + i / j <= 1000) {
                com[i + i / j] = std::min(com[i + i / j], com[i] + 1);
            }
        }
    }
    // dbg(com);
    int tests = 1;
    cin >> tests;
 
    while (tests--)
        run_case();
 
}