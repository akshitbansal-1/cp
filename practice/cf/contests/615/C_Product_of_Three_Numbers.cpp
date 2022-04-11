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


void run_case() {
    int n;
    cin>>n;
    set<int> ste;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ste.insert(i);
            ste.insert(n/i);
        }
    }
    vector<int> st(ste.begin(), ste.end());
    // cout<<st.size()<<endl;
    bool b = true;
    for (int i = 0; i < st.size(); i++) {
        // cout<<st[i]<<" ";
        for (int j = i + 1; j < st.size(); j++) {
            for (int k = j + 1; k < st.size(); k++) {
                if (st[i] * st[j] * st[k] == n) {
                    b = false;
                    cout<<"YES\n";
                    cout<<st[i]<<" "<<st[j]<<" "<<st[k]<<endl;
                    break;
                }
            }
            if (!b) break;
        }
        if (!b) break;
    }
    if (b) cout<<"NO\n";
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