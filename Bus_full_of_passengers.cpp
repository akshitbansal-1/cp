#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define int long long int
void solve() {
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int, int> > v(n + 1, make_pair(0,0));
    string ans = "";
    while (q--) {
        char ch; 
        int i;
        cin>>ch;
        cin>>i;
        if (ch == '+') {
            if (v[i].first == 1 || v[i].second > 0) {
                ans = "Inconsistent";
            }
            v[i].first = 1;
            m--;
        } else {
            if (v[i].first == 0) {
                ans = "Inconsistent";
            }
            v[i].first = 0;
            v[i].second++;
            m++;
        }
        if (m < 0) {
            ans = "Inconsistent";
        }
    }
    if (ans == "") {
        cout<<"Consistent";
    } else {
        cout<<ans;
    }
}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
        cout<<endl;
    }
}
