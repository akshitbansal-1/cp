/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define int long long int
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        unordered_map<char, char> mp;
        mp['R'] = 'G';
        mp['G'] = 'B';
        mp['B'] = 'R';
        int ans = k;
        for (int i = 0; i < n - k + 1; i++) {
            char prev = 'R';
            int t = 0;
            for (int j = 0; j < k; j++) {
                if (s[i + j] != prev) {
                    t++;
                }
                prev = mp[prev];
            }
            ans = min(ans, t);
            prev = 'G';
            t = 0;
            for (int j = 0; j < k; j++) {
                if (s[i + j] != prev) {
                    t++;
                }
                prev = mp[prev];
            }
            ans = min(ans, t);
            prev = 'B';
            t = 0;
            for (int j = 0; j < k; j++) {
                if (s[i + j] != prev) {
                    t++;
                }
                prev = mp[prev];
            }
            ans = min(ans, t);
        }
        cout<<ans<<endl;
    }
}