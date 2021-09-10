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
        int g1, s1, b1, g2, b2, s2;
        cin>>g1>>s1>>b1>>g2>>s2>>b2;
        int sum1 = g1+s1+b1;
        int sum2 = g2+s2+b2;
        if (sum1 > sum2) cout<<1;
        else cout<<2;
        cout<<endl;
    }
}
