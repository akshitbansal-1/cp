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

vector<int> doIt(int n, vector<int> &arr) {
    stack<pair<int, int> > s;
    vector<int> ans(n);
 
    // iterate for rest of the elements
    for (int i = 0; i < n; i++) {
        int next = i;
 
        // if stack is empty then this element can't be NSE
        // for any other element, so just push it to stack
        // so that we can find NSE for it, and continue
        if (s.empty()) {
            s.push({ next, i });
            continue;
        }
 
        // while stack is not empty and the top element is
        // greater than next
        //  a) NSE for top is next, use top's index to
        //    maintain original order
        //  b) pop the top element from stack
 
        while (!s.empty() && arr[s.top().first] > arr[i]) {
            ans[s.top().second] = next;
            s.pop();
        }
 
        // push next to stack so that we can find NSE for it
 
        s.push({ next, i });
    }
 
    // After iterating over the loop, the remaining elements
    // in stack do not have any NSE, so set -1 for them
 
    while (!s.empty()) {
        ans[s.top().second] = -1;
        s.pop();
    }
 
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ---> " << ans[i] << endl;
    // }
    // cout<<endl;
    return ans;
}

void run_case() {
    int n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = s[i];
    if (s < t) {
        cout<<0<<endl;
        return;
    }

    vector<int> ans = doIt(n, v);
    dbg(ans);
    int res = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int next = ans[i-c];
            dbg(i, next);
            if (next == -1) {
                cout<<-1<<endl;
                return;
            }
            c++;
            res += next - i;
        }
    }
    cout<<res<<endl;
    // int ans = INT_MAX;
    // vector<int> right(n);
    // stack<int> st;
    // st.push(n);
    // for (int i = n - 1; i >= 0; i--) {
    //     while (st.top() != n && s[st.top()] < s[i]) {
    //         st.pop();
    //     }
    //     right[i] = st.top();
    //     st.push(i);
    // }
    // dbg(right);
    // for (int i = 0; i < n; i++) {
    //     if (s[i] > s[i]) {

    //     }
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