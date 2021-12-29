/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        int c = 0;
        for (int i = 0; i < n; i++) {
            cin>>v[i];
            // if (v[i] < 2) c++;
        }
        vector<int> dp(n, 0);
        vector<bool> visited(5e5+1, false);
        int x = 0;
        for (int i = 0; i < n; i++) {
            visited[v[i]] = true;
            if (v[i] != x) {
                dp[i] = x;
                continue;
            }
            while (visited[x]) x++;
            dp[i] = x;
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            visited[v[i]] = true;
            if (abs(v[i] - dp[i]) <= 1) k++;
            if (i > 0) {
                visited[v[i]] = false;
            }
        }
        // ans += pow(2, k);
        cout<<k<<endl;
        for (int i = 0; i < n; i++)cout<<v[i]<<" ";
        cout<<endl;
        for (int i = 0; i < n; i++)cout<<dp[i]<<" ";
        cout<<endl;
        // cout<<c<<endl;
    }
}