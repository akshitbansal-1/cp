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
        int n, k, k1, c = 0;
        cin>>n>>k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
            if (v[i] % 2 == 1) c++;
        }
        if (c < k) {
            cout<<"NO\n";
            continue;
        } else if ((c - k + 1) % 2 == 0) {
            cout<<"NO\n";
            continue;
        } else {
            int i = 0, sum = 0;
            vector<int> ans;
            k--;
            while (i < n && k) {
                sum += v[i];
                if (sum % 2 == 1) {
                    ans.push_back(i + 1);
                    k--;
                    sum = 0;
                }
                i++;
            }
            ans.push_back(n);
            cout<<"YES\n";
            for (int i = 0; i < k1; i++) cout<<ans[i]<<" ";
            cout<<endl;
        }








        
        // cout<<k<<" "<<sum<<endl;
        // if (k < 0 && sum % 2 == 1) {
        //     cout<<"NO\n";
        //     continue;
        // }
        // if (k <= 0) {
            
        // } else {
        //     cout<<"NO\n";
        // }
    }
}