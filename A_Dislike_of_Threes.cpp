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
        int n;
        cin>>n;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            ans++;
            string anss = to_string(ans);
            if (ans % 3 == 0 || anss[anss.size() - 1] == '3')i--;
        }
        cout<<ans<<endl;
    }
}
