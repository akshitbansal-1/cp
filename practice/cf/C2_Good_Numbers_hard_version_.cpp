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

vector<int> v1(41), v2(41);
void precom() {
    int i = 1;
    v1[0] = v2[0] = 1, v2[1] = 1;
    v1[0] = 1;
    while (i < 40) {
        v1[i] = v1[i - 1] * 3;
        i++;
    }
    i = 1;
    while (i < 40) {
        v2[i] = v2[i - 1] + v1[i];
        i++;
    }
    // dbg(v1);
    // dbg(v2);
}
int run_case(int n) {
    if (n <= 0) return 0;
    int n1 = n, c = 0, ans = 0, b = 0;
    while (n1) {
        if (n1 % 3 != 0) b = 1;
        n1 /= 3;
        c++;
    }
    if (b == 0) return v1[c - 1];
    // c = max(2ll, c);
    dbg(n, c);
    dbg(v1[c - 1], v2[c - 2]);
    // c--;
    if (v1[c - 1] + v2[c - 2] < n) {
        ans = v1[c];
    } else {

        //try recusrsion here
        ans += run_case(n - v1[c - 1]);
    }
    return ans;
}
int32_t main() {
    precom();
    ios::sync_with_stdio(false);
#ifndef AKSHIT_DEBUG
    cin.tie(nullptr);
#endif
 
    int tests = 1;
    cin >> tests;
 
    while (tests--)
        {
            int n;
            cin>>n;
            cout<<run_case(n)<<endl;;
        }

}