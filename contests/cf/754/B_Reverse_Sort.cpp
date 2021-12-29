/*
    Written by: akshitforever
*/

#include<bits/stdc++.h>
using namespace std;
bool sorted(string &s) {
    for (int k = 0; k < s.size() - 1; k++) {
        if (s[k] > s[k + 1]) return false;
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> v;
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (sorted(s)) {
                break;
            }
            vector<int> os, zs;
            int j = 0;
            while (j < n) {
                if (s[j] == '1') os.push_back(j);
                j++;
            }
            j = n - 1;
            while (j >= 0) {
                if (s[j] == '0') zs.push_back(j);
                j--;
            }
            // for (int x: os) cout<<x<<" ";
            // cout<<endl;
            // for (int x: zs) cout<<x<<" ";
            // cout<<endl;
            j = 0;
            int k = 0;
            vector<int> t1, t2;
            while (j < os.size() && k < zs.size() && os[j] < zs[k]) {
                t1.push_back(os[j++]);
                t2.push_back(zs[k++]);
            }

            for (j = t2.size() - 1; j >= 0; j--) t1.push_back(t2[j]);
            j = 0, k = t1.size() - 1;
            // for (int x: t1) cout<<x<<" ";
            // cout<<endl;
            while (j < k) {
                swap(s[t1[j++]], s[t1[k--]]);
            }
            ans.push_back(t1);
            // cout<<s<<endl;
        }
        cout<<ans.size()<<endl;
        for (vector<int> &x: ans) {
            cout<<x.size()<<" ";
            for (int y : x) cout<<y + 1<<" ";
            cout<<endl;
        }
    }
}