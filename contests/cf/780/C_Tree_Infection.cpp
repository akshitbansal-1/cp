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

struct Node {
    int index;
    int val;
    bool vis;

    Node(int index, int val): index(index), val(val)  {
        vis = false;
    }
        
};
struct CompareHeight {
    bool operator()(Node const& p1, Node const& p2)
    {
        if (p1.val != p2.val) return p1.val < p2.val;
        else return p1.vis == true;
    }
};
void run_case() {
    int n;
    cin>>n;
    map<int, int> mp;
    for (int i = 2; i <= n; i++) {
        int a;
        cin>>a;
        mp[a]++;
    }
    multiset<int, greater<int>> st; 
    st.insert(1);
    for (auto x: mp) {
        st.insert(x.second);
    }
    int s = 0, rem = n;
    multiset<int> vis;
    set<int> visited;
    while (rem > 0) {
        if (st.empty()) break;
        int v = *st.begin();
        s++;
        st.erase(st.begin());
        rem--;
        multiset<int> copy = vis;
        for (auto x: copy) {
            rem--;
            vis.erase(vis.find(x));
            if (x - 1 > 0) {
                vis.insert(x - 1);
            }
        }
        if (v - 1 > 0) vis.insert(v-1);
        dbg(vis, v, rem);
    }
    while (rem > 0) {
        // if (vis.size() == 0) break;
        s++;
        multiset<int> copy = vis;
        bool used = false;
        for (auto x: copy) {
            rem--;
            vis.erase(vis.find(x));
            if (used) {
                if (x - 1 > 0) {
                    vis.insert(x - 1);
                }
            }
            else if (x - 2 >= 0) {
                rem--;
                used = true;
                if (x - 2) vis.insert(x - 2);
            }
        }
        dbg(vis, rem);
    }
    // if (rem) s++;
    dbg("\n");
    
    cout<<s<<endl;
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