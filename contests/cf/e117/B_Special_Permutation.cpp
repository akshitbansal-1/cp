/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, a, b;
        cin>>n>>a>>b;
        vector<bool> v(n, false);
        vector<int> ans;
            // cout<<a<<" ";
            ans.push_back(a);
            v[a] = true;
            int j = 0;
            for (int i = 0; i < n / 2 - 1 && j < n;) {
                if (n - j != b && n - j != a && n - j > a) {
                    ans.push_back(n - j);
                    v[n - j] = true;
                    i++;
                }
                j++;
            }
            j = 0;
            ans.push_back(b);
            v[b] = true;
            // cout<<b<<" ";
            bool bo = false;
            for (int i = 0; i < n / 2 - 1 && j < n;) {
                if (j + 1 != a && j + 1 != b && j + 1 < b) {
                    ans.push_back(j + 1);
                    i++;
                }
                j++;
            }
            if (bo || ans.size() != n) {
                cout<<-1<<endl;
                continue;
            }
            for (int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
        // }
        cout<<endl;
    }
}