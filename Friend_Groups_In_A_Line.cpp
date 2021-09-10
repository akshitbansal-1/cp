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
int INT_MINI = -214748364;
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<vector<int> > v;
        int prev = INT_MINI;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                if (i - prev > k) {
                    v.push_back({i, i, 0});
                } else {
                    int temp = min(i - prev, v[v.size() - 1][2]);
                    v[v.size() - 1][2] = temp;
                    v[v.size() - 1][1] = i;
                }
                prev = i;
            }
        }
        int c = 1;
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1][0] - v[i][1] > k + 2) {
                if (v[i][2] + 1 > k);
                if (v[i + 1])
                c++;
            }
        }
        cout<<c<<endl;
    }
}
