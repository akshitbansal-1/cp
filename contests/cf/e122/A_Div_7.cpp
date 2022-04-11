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

int fd(string &d, string &c) {
    int diff = max(c.length(), d.length()) - min(c.length(), d.length());
    for (int i = 0; i < min(c.length(), d.length()); i++) {
        if (d[i] != c[i]) diff++;
    }
    return diff;
}
void run_case() {
    int n;
    cin>>n;
    if (n % 7 == 0) {
        cout<<n<<endl;
        return;
    }
    int prev = n / 7 * 7, next = prev + 7;
    string s1 = to_string(prev), s2 = to_string(next), s3 = to_string(n);
    int diff1 = fd(s1, s3), diff2 = fd(s2, s3);
    if (diff1 < diff2 && prev % 10 != 0) {
        cout<<prev<<endl;
    } else if (diff2 < diff1 && next % 10 != 0) {
        cout<<next<<endl;
    } else if (prev % 10 == 0){
        cout<<next<<endl;
    } else {
        cout<<prev<<endl;
    }
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