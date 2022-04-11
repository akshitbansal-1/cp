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

int get(vector<int> &v, int ma, int n) {
    dbg(v);
    multiset<int> odd, even;
    for (int i = 0; i < n; i++) {
        if (v[i] == ma) continue;
        if (v[i] % 2) odd.insert(v[i]);
        else even.insert(v[i]);
    }
    // dbg(odd, even);
    int toBe = ma % 2;
    int day = 1;
    while(odd.size() || even.size()) {
        bool used = false;
        if (toBe) {
            // dbg('o');
            if (even.size() && ((day % 2) == 1)) {
                int x = *even.begin();
                even.erase(even.begin());
                if ((x + 1) < ma)odd.insert(x+1);
                used = true; 
            } else if (odd.size() && ((day % 2) == 0)) {
                int x = *odd.begin();
                odd.erase(odd.begin());
                if ((x + 2) < ma) odd.insert(x+2);
                used = true; 
            }

            // if (even.size() == 0) {
            //     int x = *odd.begin();
            //     odd.erase(odd.begin());
            //     if (day % 2) {

            //     }
            //     if (x + 2 < ma) odd.insert(x+2);
            // }
            if (odd.size() && !used) {
                // dbg("here");
                int x = *odd.begin();
                if ((odd.size() >= 2) || (x + 3 < ma)) {
                    odd.erase(odd.begin());
                    if ((x + 1) < ma) even.insert(x+1);
                }
            }
        } else {
            // dbg('e');
            if (even.size() && ((day % 2) == 0)) {
                int x = *even.begin();
                even.erase(even.begin());
                if ((x + 2) < ma)even.insert(x+2);
                used = true;
            } else if (odd.size() && ((day % 2) == 1)) {
                int x = *odd.begin();
                odd.erase(odd.begin());
                if ((x + 1) < ma) even.insert(x+1);
                used = true; 
            }

            if (even.size() && !used) {
                // dbg("here");
                int x = *even.begin();
                if ((even.size() >= 2) || ((x + 3) < ma)) {
                    even.erase(even.begin());
                    if ((x + 1) < ma) odd.insert(x+1);
                }
            }
            
        }
        dbg(day, odd, even);
        day++;
    }
    return day - 1;
}
void run_case() {
    int n;
    cin>>n;
    vector<int> v(n);
    int ma = 0;
    
    for (int i = 0; i < n; i++) {
        cin>>v[i];
        ma = max(ma, v[i]);
    }
    sort(all(v));
    int ans = get(v, ma, n);
    dbg(ans);
    v[n - 1]++;
    ans = min(ans, 1+get(v, ma+1, n));
    cout<<ans<<endl;
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