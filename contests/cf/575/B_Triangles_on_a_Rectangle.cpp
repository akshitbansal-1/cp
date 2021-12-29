/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int


int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int w, h;
        cin>>w>>h;
        int k1;
        cin>>k1;
        vector<int> v1(k1);
        for (int i = 0; i < k1; i++) {
            cin>>v1[i];
        }
        int k2;
        cin>>k2;
        vector<int> v2(k2);
        for (int i = 0; i < k2; i++) {
            cin>>v2[i];
        }
        int k3;
        cin>>k3;
        vector<int> v3(k3);
        for (int i = 0; i < k3; i++) {
            cin>>v3[i];
        }
        int k4;
        cin>>k4;
        vector<int> v4(k4);
        for (int i = 0; i < k4; i++) {
            cin>>v4[i];
        }
        int ans = 0;
        ans = max((v1[k1 - 1] - v1[0]) * h, ans);
        // cout<<ans<<endl;
        ans = max((v2[k2 - 1] - v2[0]) * h, ans);
        // cout<<ans<<endl;
        ans = max((v3[k3 - 1] - v3[0]) * w, ans);
        // cout<<ans<<endl;
        ans = max((v4[k4 - 1] - v4[0]) * w, ans);
        cout<<ans<<endl;
    }
}