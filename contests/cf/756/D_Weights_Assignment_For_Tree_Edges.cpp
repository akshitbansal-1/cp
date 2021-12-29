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
        int n;
        cin>>n;
        vector<int> b(n), p(n), s(n, 0), s2(n, 0);
        vector<bool> covered(n, false);
        int r = 0;
        for (int i = 0; i < n; i++) {
            cin>>b[i];
            b[i]--;
            if (b[i] == i) r = i;
        }
        for (int i = 0; i < n; i++) {
            cin>>p[i];
            p[i]--;
            
        }
        
        if (p[0] != r) {
            cout<<-1<<endl;
            continue;
        }
        vector<int> ans(n);

        ans[r] = 0;
        covered[r] = true;
        int c = 1;
        bool can = true;
        for (int i = 0; i < n; i++) {
            if (p[i] == r) continue;
            int par = b[p[i]];
            if (!covered[par]) {
                can = false;
                break;
            }
            int t = c++ - s2[b[p[i]]];
            s[p[i]] = t;
            s2[p[i]] = t + s[b[p[i]]];
            covered[p[i]] = true;
        }
        // cout<<endl;
        if (can) {
            for (int i = 0; i < n; i++) cout<<s[i]<<" "; cout<<endl;
            // for (int i = 0; i < n; i++) cout<<s2[i]<<" "; cout<<endl;
        }
        else cout<<-1<<endl;
    }
}