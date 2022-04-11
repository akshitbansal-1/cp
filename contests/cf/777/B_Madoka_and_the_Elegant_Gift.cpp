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


int trr, trc, brr, brc, tlr, tlc, blr, blc;
void dfs(vector<string> &v, vector<vector<bool>> &vis, int i, int j) {
    if (i < 0 || i >= v.size() || j < 0 || j >= v[0].length() || vis[i][j] || v[i][j] == '0') return;
    trr = min(trr, i);
    trc = max(trc, j);
    brr = max(brr, i);
    brc = max(brc, j);
    tlr = min(tlr, i);
    tlc = min(tlc, j);
    blr = max(blr, i);
    blc = min(blc, j);
    vis[i][j] = true;
    dfs(v, vis, i + 1, j);
    dfs(v, vis, i, j + 1);
    dfs(v, vis, i - 1, j);
    dfs(v, vis, i, j - 1);
}
int getMaxArea(vector<int> hist, int n)
{
    // Create an empty stack. The stack holds indexes
    // of hist[] array. The bars stored in stack are
    // always in increasing order of their heights.
    stack<int> s;
 
    int max_area = 0; // Initialize max area
    int tp;  // To store top of stack
    int area_with_top; // To store area with top bar
                       // as the smallest bar
 
    // Run through all bars of given histogram
    int i = 0;
    while (i < n)
    {
        // If this bar is higher than the bar on top
        // stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
 
        // If this bar is lower than top of stack,
        // then calculate area of rectangle with stack
        // top as the smallest (or minimum height) bar.
        // 'i' is 'right index' for the top and element
        // before top in stack is 'left index'
        else
        {
            tp = s.top();  // store the top index
            s.pop();  // pop the top
 
            // Calculate the area with hist[tp] stack
            // as smallest bar
            area_with_top = hist[tp] * (s.empty() ? i :
                                   i - s.top() - 1);
 
            // update max area, if needed
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
 
    // Now pop the remaining bars from stack and calculate
    // area with every popped bar as the smallest bar
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i :
                                i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
 
    return max_area;
}
int getRecArea() {
    if (!brr) brr++, trr++;
    else if (!trr) trr++, brr++;
    if (!brc) brc++, trc++;
    if (!trc) trc++, brc++;
    return (brr - trr + 1) * (brc - trc + 1);
}
void run_case() {
    int m, n;
    cin>>n>>m;
    vector<string> v(n);
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) cin>>v[i];
    vector<int> dp(m, 0);
    for (int i = 0; i < n; i++) {
        bool trig = false;
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '1') dp[j]++;
            else dp[j] = 0;
            if (v[i][j] == '1' && !vis[i][j]) {
                trig = true;
                trr = brr = tlr = blr = i;
                trc = brc = tlc = blc = j;
                dfs(v, vis, i, j);
                for (int k = min({tlr, trr, blr, brr}); k <= max({blr, brr, tlr, trr}); k++) {
                    for (int l = min({tlc, trc, brc, blc}); l <= max({brc, blc, tlc, trc}); l++) {
                        if (v[k][l] == '0') {
                            cout<<"NO\n";
                            return;
                        }
                    }
                }
            }
        }
        // if (trig) {
        //     // dbg(dp);
        //     int area = getMaxArea(dp, m);
        //     int recarea = getRecArea();
        //     dbg(area, recarea);
        //     if (area != recarea) {
        //         cout<<"NO"<<endl;
        //         return;
        //     }
        // }
    }
    cout<<"YES\n";
    dbg();

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