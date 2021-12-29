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
        int n, a, b;
        cin>>n>>a>>b;
        int a1 = a, b1 = b;
        if (a + b > n - 2) {
            cout<<"-1\n";
            continue;
        }
        
        vector<int> ans(n, 0);
        if (a >= b) {
            int i = n, idx = 1;
            while (idx < n - 1 && a) {
                ans[idx] = i--;
                idx += 2;
                a--;
            }
            idx = 2;
            int j = 1;
            while (idx < n - 1 && b) {
                ans[idx] = j++;
                idx += 2;
                b--;
            }
            int k = 0;
            while (j <= i && k < n) {
                if (ans[k] == 0) ans[k] = (a1 + b1) % 2 == 0 ? j++ : i--;
                k++;
            }
            for (i = 1; i < n - 1; i++) {
                if (ans[i] > ans[i + 1] && ans[i] > ans[i - 1]) a1--;
                else if (ans[i] < ans[i + 1] && ans[i] < ans[i - 1]) b1--;
            }
            // cout<<a1<<" "<<b1<<endl;
            if (a1 == 0 && b1 == 0)
                for (k = 0; k < n; k++) {
                    cout<<ans[k]<<" ";
                }
            else {
                cout<<-1;
            }
        } else {
            int i = 1, idx = 1;
            while (idx < n - 1 && b) {
                ans[idx] = i++;
                idx += 2;
                b--;
            }
            int j = n; idx = 2;
            while (idx < n - 1 && a) {
                ans[idx] = j--;
                idx += 2;
                a--;
            }
            int k = 0;
            while (i <= j && k < n) {
                if (ans[k] == 0) ans[k] = i++;
                k++;
            }
            for (i = 1; i < n - 1; i++) {
                if (ans[i] > ans[i + 1] && ans[i] > ans[i - 1]) a1--;
                else if (ans[i] < ans[i + 1] && ans[i] < ans[i - 1]) b1--;
            }
            if (a1 == 0 && b1 == 0)
                for (k = 0; k < n; k++) {
                    cout<<ans[k]<<" ";
                }
            else {
                cout<<-1;
            }
        }
        cout<<endl;
    }
}