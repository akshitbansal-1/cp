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
        int c = 0;
        vector<int> v(4), vis(4, 0);
        for (int i = 0; i < 4; i++) {
            cin>>v[i];
        }
        // for (int i = 0; i < 4; i++) {
        //     for (int j = 0; j < 4; j++) {
        //         if (i != j && v[i] != v[j] && !vis[j] && !vis[i]) {
        //             vis[i] = 1;
        //             vis[j] = 1;
        //             c++;
        //         }
        //     }
        // }
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            for(int j = 0;j < 4; j++) {
                if (v[i] == v[j] and i != j){
                    ans += 1;
                } 
            }
        }
        cout << ans << "\n";
        if (ans == 0 or ans == 2){
            cout << 2 << "\n";
        }
        else if (ans == 6){
            cout << 1 << "\n";
        }
        else cout << 0 << "\n";
    }
}
