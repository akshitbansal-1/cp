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

int c, ac;
char findMin(char s, char d) {
    if (d == 'W') {
        switch(s) {
            case 'N': return min(1 * ac, 3 * c);
            case 'E': return min(2 * ac, 2 * c);
            case 'S': return min(3 * ac, 1 * c);
        }
    } else {
        switch(s) {
            case 'N': return min(1 * c, 3 * ac);
            case 'W': return min(2 * ac, 2 * c);
            case 'S': return min(3 * c, 1 * ac);
        }
    }
    return 0;
}

int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        string v;;
        cin>>v;

        cin>>c>>ac;
        vector<int> l(n), r(n);
        if (v[0] != 'W') l[0] = findMin(v[0], 'E');
        if (v[n - 1] != 'E') r[n - 1] = findMin(v[n - 1], 'W');
        for (int i = n - 2; i >= 0; i--) {
            if (v[i] != 'W') r[i] = findMin(v[i], 'W');
            r[i] += r[i + 1];
        }
        for (int i = 1; i < n; i++) {
            if (v[i] != 'E') l[i] = findMin(v[i], 'E');
            l[i] += l[i - 1];
        }
        int ans = min(l[n - 1], r[0]);
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, l[i] + r[i + 1]);
        }
        cout<<ans;
    }
}
