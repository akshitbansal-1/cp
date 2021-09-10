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

bool cmp(vector<int>& i1, vector<int>& i2)
{
    return (i1[0] < i2[0]);
}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n, m, c = 0;
        cin>>n>>m;
        vector<int> v(n);
        map<int, int> ma;
        for (int i = 0; i < n; i++) {
            cin>>v[i];
            ma[v[i]] = i;
        }
        if (n == m) {
            cout<<"Yes\n";
            continue;
        }
        vector<int> v1 = v;
        
        sort(v1.begin(), v1.end());
        
        int idx = ma[v1[0]];
        for (int i = 1; i < n; i++) {
            if (ma[v1[i]] != idx + 1) c++;
            idx = ma[v1[i]];
        }
        cout<<(m >= c ? "Yes\n" : "No\n");
    }
}
