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

int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            cin>>v[i];
            m[v[i]] = i;
        }
        vector<int> v1 = v;
        sort(v1.begin(), v1.end());
        vector<int> ans(k);
        int z = 0;
        for (int i = n - k; i < n; i++) {
            ans[z++] = m[v1[i]];
        }
        cout<<v[ans[k/2]]<<endl;
        sort(ans.begin(), ans.end());
        for (int i = 0; i < k; i++) cout<<v[ans[i]] <<" ";

    }
}
