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

bool check(int a, int b, int c) {
    if (abs(a-b) % min(a,b) == 0 && abs(b-c) % min(b,c) == 0 && abs(a-c) % min(a, c) == 0) {
    // if (a - b == b - c) {
        // cout<<"YES\n";
        return true;
    } else {
        // cout<<"NO\n";
    }
    return false;
}

void run_case() {
    int a, b, c;
    cin>>a>>b>>c;
    // cout<<a<<" "<<b<<" "<<c<<endl;
    if (a == b && b == c) {
        cout<<"YES\n";
        return;
    }
    // if (check(a,b,c)) {
    //     // cout<<"YES\n";
    //     return;
    // }
    bool found = false;
    int temp = c - b;
    int ans = (b - temp) % a;
    if (!ans and (b-temp) > 0){
        found = true;
    } 
    temp = (a + c) / 2;
     ans = (temp) % b;
    if (!ans and (temp*2) == (a+c)){
        found = true;
    }
     temp = b - a;
     ans = (temp + b) % c;
    if (!ans and (temp+b) > 0){
        found = true;
    }

    if (found) cout<<"YES\n";
    else cout<<"NO\n";
    // if ((a-c) % b == 0 && check(a, abs(a-c), c)) {
    //     cout<<"YES\n";
    // } else if (abs(a-b) % c == 0 && check(a, b, abs(a-b))) {
    //     cout<<"YES\n";
    // } else if (abs(b-c) % a == 0 && check(abs(b - c), b, c)) {
    //     cout<<"YES\n";
    // } else {
    //     cout<<"NO\n";
    // }


    
    // if (c > a) {
    //     if (a > b) {
    //         if ((c - a) % b == 0) {
    //             cout<<"YES\n";
    //             return;
    //         } else {
    //             cout<<"NO\n";
    //             return;
    //         }
    //     } else {
    //         if ((c - b) % a == 0 && check((c - b) / a, b, c)) {
    //             cout<<"YES\n";
    //             return;
    //         } else {
    //             cout<<"NO\n";
    //             return;
    //         }
    //     } 
    // } else if (c < a) {
    //     if (a > b) {
    //         if ((c - a) % b == 0 && check(a, (c - a) / b, c)) {
    //             cout<<"YES\n";
    //             return;
    //         } else {
    //             cout<<"NO\n";
    //             return;
    //         }
    //     } else {
    //         if ((b - a) % c == 0 && check(a, b, (b - a) % c)) {
    //             cout<<"YES\n";
    //             return;
    //         } else {
    //             cout<<"NO\n";
    //             return;
    //         }
    //     }
    // } else {
    //     if (b < a && (c - a) % b == 0) cout<<"NO\n";
    //     else cout<<"NO\n";
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