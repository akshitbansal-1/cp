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
#include<cmath>
using namespace std;
#define int long long int

int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int sq = sqrt(n);
        if (sq * sq == n) {
            cout<<sq<<" "<<1<<endl;
            continue;
        }
        int squ = sq * sq;
        int x = 1, y = sq + 1;
        for (int i = 1; i <= 2 * sq + 1; i++) {
            if (squ + i == n) {
                break;
            } else if (x <= sq) {
                x++;
            } else {
                y--;
            }
        }
        cout<<x<<" "<<y<<endl;
    }
}
