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
        int n, s;
        cin>>n>>s;
        int c = 0;
        int sub = 3;
        while (n > 0) {
            n -= sub;
            c++;
            sub += 2;
        }
        cout<<(c * s)<<endl;
    }
}
