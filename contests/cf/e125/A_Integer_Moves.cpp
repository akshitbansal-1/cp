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

int getMinSquares(int n)
{
    // We need to check base case
    // for n i.e. 0,1,2
    // the below array creation
    // will go OutOfBounds.
    if(n<=3)
      return n;
     
    // Create a dynamic
    // programming table
    // to store sq
    int* dp = new int[n + 1];
 
    // getMinSquares table
    // for base case entries
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
 
    // getMinSquares rest of the
    // table using recursive
    // formula
    for (int i = 4; i <= n; i++)
    {
         
        // max value is i as i can
        // always be represented
        // as 1*1 + 1*1 + ...
        dp[i] = i;
 
        // Go through all smaller numbers to
        // to recursively find minimum
        for (int x = 1; x <= ceil(sqrt(i)); x++)
        {
            int temp = x * x;
            if (temp > i)
                break;
            else
                dp[i] = min(dp[i], 1 +
                                  dp[i - temp]);
        }
    }
 
    // Store result and free dp[]
    int res = dp[n];
    delete[] dp;
 
    return res;
}

void run_case() {
    int x, y;
    cin>>x>>y;
    if (x == 0 && y == 0) {
        cout<<0<<endl;;
        return;
    }
    cout<<getMinSquares(x*x + y * y)<<endl;
    return;
    // int op = 0;
    // vector<vector<int>> dp(x + 1, vector<int> (y + 1, INT_MAX));
    // dp[0][0] = 0;
    // for (int i = 0; i < x + 1; i++) {
    //     double d = sqrt(i*i);
    //     if (d == int32_t(d)) {
    //         dp[i][0] = 1;
    //     } else {
    //         dp[i][0] = i;
    //     }
    // }
    // for (int i = 0; i < y + 1; i++) {
    //     double d = sqrt(i*i);
    //     if (d == int32_t(d)) {
    //         dp[0][i] = 1;
    //     } else {
    //         dp[0][i] = i;
    //     }
    // }
    
    // for (int i = 1; i <= x; i++) {
    //     for (int j = 1; j <= y; j++) {
    //         double d = sqrt(i*i + j*j);
    //         // cout<<d<<" " << int32_t(d)<<endl;
    //         if (d == int32_t(d)) {
    //             dp[i][j] = 1;
    //         } else {
    //             dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
    //         }
    //     }
    // }
    // cout<<dp[x][y]<<endl;
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