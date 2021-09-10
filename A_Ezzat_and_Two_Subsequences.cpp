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
#include <iomanip> 
using namespace std;
#define int long long int

int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        double n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        int s = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            s += v[i];
        }
        double res = (s / (n - 1)) + v[n - 1];
        cout<<fixed<<setprecision(9)<<res<<endl;
    }
}
