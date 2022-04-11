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

int su(int sum) {
    return (sum * (sum + 1))/2;
}

int getN(int sum) {
    sum *= 2;
    int q = sqrt(sum);
    if (sum % q == 0 && sum / q == q + 1) return q;
    else return q + 1;
}

void run_case() {
    int n;
    cin>>n;
    vector<pair<int, int>> v(n + 1);
    v[0] = make_pair(-1,-1);
    for (int i = 1; i <= n; i++) {
        cin>>v[i].first;
    }
    for (int i = 1; i <= n; i++) {
        cin>>v[i].second;
    }
    int sum = 0, cf = 0;
    // sort(v.begin(), v.end());
    // int prev = 0, health = 0;
    pair<int, int> inter = make_pair(-1, -1);
    for (int i = n; i >= 1; i--) {
        int g = (v[i].second);
        if (v[i].first - g < v[i-1].first) {
            if (inter.first == -1) {
                inter.first = v[i].first - g + 1;
                inter.second = v[i].first;
            } else
                inter.first = min(v[i].first - g + 1, inter.first);
        } else if (inter.first == -1 || inter.first >= v[i].first){
            if (inter.second == -1) {
                inter.second = v[i].first;
                inter.first = v[i].first - g + 1;
            }
            sum += su(inter.second - min(inter.first, v[i].first - g + 1) + 1);
            inter = make_pair(-1, -1);
        }
    }
    // if (inter.first != -1) sum += su(inter.second - inter.first + 1);
    cout<<sum<<endl;
    // cout<<endl;
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