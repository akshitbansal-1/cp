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
        int a, b, c;
        cin>>a>>b>>c;
        if (a > b) swap(a, b);
        int maxEls = 2 * (b - a);


        // cout<<maxEls<<" ";
        if (b > maxEls || a > maxEls || c > maxEls) {
            cout<<-1<<endl;continue;
        }
        if (c <= maxEls / 2) {
            cout<<(maxEls / 2 + c);
        } else {
            cout<<(c - maxEls / 2);
        }
        cout<<endl;
        // if (b - a == 1 && (a != 1 || b != 1)) {
        //     cout<<-1<<endl;continue;
        // }
        // if (b < 2 * a) {
        //     cout<<-1<<endl; continue;
        // } 
        // if (c >= a && c <= b) {
        //     cout<<(c + b - a)<<endl;
        // } else {
        //     cout<<-1<<endl;
        // }
    }
}
