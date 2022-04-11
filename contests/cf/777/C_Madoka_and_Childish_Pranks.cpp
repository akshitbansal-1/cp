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
 
void change(vector<string>& plain, int i, int j, int k, int l) {
    dbg(k, l, i, j);
    int row = 0;
    for (int x = k; x <= i; x++) {
        int col = row;
        for (int y = l; y <= j; y++) {
            plain[x][y] = col + '0';
            col = !col;
        }
        row = !row;
    }
}
void dfs(vector<string>&plain, vector<string> &v, int i, int j) {
    dbg(i,j);
    int trr = i, trc = j, brr = i, brc = j, k, l;
    int row = 1;
    for (int k = i; k >= 0; k--) {
        int col = row;
        for (int l = j; l >= 0; l--) {
            if (v[k][l] - '0' - col != 0) {
                change(plain, i, j, k, min(l + 1, j - 1));
                return;
            }
            col = !col;
        }
        row = !row;
    }
}
 
 
void run_case() {
    int m, n;
    cin>>n>>m;
    vector<string> v(n);
    vector<string> plain(n, string(m, '0'));
    change(plain, n - 1, m - 1, 0, 0);
    for (int i = 0; i < n; i++) cin>>v[i];
    if (v[0][0] == '1') {
        cout<<"-1\n";
        return;
    }
    vector<vector<int>> ops;
    ops.push_back({0,0,n-1,m-1});
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (v[i][j] != plain[i][j]) {
                if (i == '0') {
                    ops.push_back({i, j, i, j});
                    plain[i][j] = '0';
                } else {
                    if ((j > 0 && v[i][j - 1] == '0')) {
                        ops.push_back({i, j, i, j});
                        plain[i][j - 1] = '0';
                        plain[i][j] = '1';
                    }
                }
            }
        }
    }
    
    vector<string> test(n, string(m, '0'));
    for (auto &x: ops) {
        change(test, x[2], x[3], x[0], x[1]);
        for (int y: x) {
            // cout<<y + 1<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < n; i++) {
        cout<<test[i]<<endl;
        if (test[i] != v[i]) {
            cout<<"NO\n"<<endl;;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        // cout<<plain[i]<<endl;;
        if (plain[i] != v[i]) {
            cout<<-1<<endl;;
            return;
        }
    }
    cout<<ops.size()<<endl;
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