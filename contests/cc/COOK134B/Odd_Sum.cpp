#include <bits/stdc++.h>
using namespace std;
#define int long long int



void solve() {
    
    
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    scanf("%lld", &t);
    while(t--) {
        int n;
        scanf("%lld", &n);
        if (n == 1) {
            cout<<1<<endl;
            continue;;
        }
        if (n == 2) {
            cout<<1<<endl;
            continue;
        }
        n -= 2;
        int ans = n * (4 + (n - 1) * 2) / 2 + 1;
        cout<<ans<<endl;
    }
}
