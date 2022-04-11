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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
 
    else
        return gcd(b, a % b);
}
 
/*Function to left rotate arr[] of siz n by d*/
void leftRotate(vector<int> &arr, int d, int n)
{
    /* To handle if d >= n */
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;
 
        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;
 
            if (k == i)
                break;
 
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
    dbg(arr);
}

void run_case() {
    int n;
    cin>>n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        v[i] = x;
    }
    dbg(v);
    stack<int> st;
    for (int i = n - 1; i > 0; i--) {
        vector<int> temp(i + 1);
        int idx;
        for (int j = 0; j <= i; j++) {
            if (v[j] == i + 1) idx = j + 1;
            temp[j] = v[j];
        }
        if (idx == i + 1) {
            st.push(0);
            continue;
        }
        dbg(idx);
        leftRotate(temp, idx, i + 1);
        for (int j = 0; j < i; j++) {
            v[j] = temp[j];
        }
        // idx = idx % (i + 1);
        st.push(idx);
    }
    cout<<0<<" ";
    while (!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
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