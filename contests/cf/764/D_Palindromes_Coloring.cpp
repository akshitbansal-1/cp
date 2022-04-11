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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int ans = INT_MAX;
    vector<int> hash(26, 0);
    for (int i = 0; i < n; i++) {
        hash[s[i]-'a']++;
    }
    vector<int> odd, even;
    // for (int i = 0; i < k; i++) {
    for (int j = 0; j < 26; j++) {
        if (hash[j] > 0 && hash[j] % 2 == 0) even.push_back(hash[j]/2);
        else if (hash[j] > 0) {
            even.push_back(hash[j]/2);
            odd.push_back(1);
        }
    }
    int s1 = accumulate(even.begin(), even.end(), 0ll);
    int s2 = accumulate(odd.begin(), odd.end(), 0ll);
    int can = s1 / k, other = s1 % k;
    if (s2 + other * 2 >= k) {
        cout<<can*2+1<<endl;
    } else {
        cout<<can*2<<endl;
    }
    // sort(odd.begin(), odd.end());
    // sort(even.begin(), even.end());
    // if (k == 1) {
    //     cout<<(c+ma)<<endl;
    //     return;
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