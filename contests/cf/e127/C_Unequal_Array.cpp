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


void run_case() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    int c = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            c++;
        }
    }
    if (c <= 1) {
        cout<<"0\n";
        return;
    }
    c = 1;
    vector<int> temp;
    map<int, int> mp;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            c++;
        } else {
            temp.push_back(c);
            c = 1;
        }
    }
    // if (c > 1) {
        temp.push_back(c);
        mp[c]++;
    // }
    dbg(temp);
    if (temp.size() == 1) {
        if (temp[0] < 3) cout<<0<<endl;
        else if (temp[0] == 3) cout<<1<<endl;
        else cout<<temp[0]-3<<endl;
        return;
    }
    n = temp.size();
    int op = 0, same = 0;
    if (temp[n - 1] > 1) {
        op = temp[n - 1] - 2;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] > 1) {
                dbg('k');
                cout<<op+(n-temp[n - 1]);
                return;
            }
        }
    }
    for (int i = 0; i < temp.size(); i++) {
        
        if (temp[i] > 1) {
            op+=max(0ll, temp[i]-1);
            if (i + 1 < temp.size()) temp[i+1]--;
            same++;
        }
        // else if (temp[i] > 1 && temp[i+1] > 1) {
        //     int l = temp[i] - 1;
        //     int r = temp[i+1]-1;
        //     dbg(l, r);
        //     int j = temp[i] + temp[i + 1];
        //     op += j - 3;
        // } else if (temp[i] > 1) {
        //     op += temp[i] / 2;
        // }
        // same++;
    }
    cout<<op - (same<=1)<<endl;
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