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
        int n, k, l;
        cin>>n>>k>>l;
        vector<int> v(n);
        int m = 0, idx = -1;
        for (int i = 0; i < n; i++) {
            cin>>v[i];
            if (m < v[i]) {
                idx = i;
                m = v[i];
            }
        }
        if (idx == n - 1) {
            cout<<"Yes\n";
            continue;
        }
        if (k <= 0) {
            cout<<"No\n";
            continue;
        }
        int curr = v[n - 1];
        int injected = 0;
        double rem = m - curr + 1;
        int req = ceil((double)(rem) / (double)(k));
        if (req < l) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
