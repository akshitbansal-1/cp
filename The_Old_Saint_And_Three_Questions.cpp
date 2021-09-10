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
        vector<int> v(2);
        for (int i = 0; i < 3; i++) {
            int a;
            cin>>a;
            v[a]++;
        }
        for (int i = 0; i < 3; i++) {
            int a;
            cin>>a;
            v[a]--;
        }
        if (v[0] != 0 || v[1] != 0) cout<<"Fail";
        else cout<<"Pass";
        cout<<endl;
    }
}
