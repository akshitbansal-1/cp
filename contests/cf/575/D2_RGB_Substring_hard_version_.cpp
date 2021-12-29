/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<deque>
using namespace std;
#define int long long int
unordered_map<char, char> mp;
void fv1(vector<int> &v, int j, string &s) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = (i + j) % 3;
        // cout<<v[i]<<" ";
    }
    // cout<<endl;
}
void fv2(vector<int> &v, vector<int> &x, string &s) {
    for (int i = 0; i < v.size(); i++) {
        if (s[i] != v[i]) {
            x[i] = 1;
        } else x[i] = 0;
        // cout<<x[i]<<" ";
    }
    // cout<<endl;
}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') s[i] = 0;
            else if (s[i] == 'G') s[i] = 1;
            else s[i] = 2;
        }
        int ans = k;
        for (int i = 0; i < 3; i++) {
            vector<int> v1(n), v2(n);
            fv1(v1, i, s);
            fv2(v1,v2, s);
            int s = 0;
            for (int j = 0; j < k; j++) {
                s += v2[j];
            }
            ans = min(ans, s);
            for (int j = k; j < n; j++) {
                s += v2[j];
                s -= v2[j - k];
                ans = min(ans, s);
                // cout<<s<<" ";
            }
        }
        cout<<ans<<endl;
    }
}