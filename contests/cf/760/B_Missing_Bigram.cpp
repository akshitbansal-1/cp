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
        int n;
        cin>>n;
        string ans = "";
        string prev = "cc";
        for (int i = 0; i < n - 2; i++) {
            string s;
            cin>>s;
            if (prev[1] != s[0]) {
                ans += prev[1];
            }
            if (i < n - 3) ans += s[0];
            if (i == n - 3) ans += s;
            prev = s;
        }
        ans = ans.substr(1, ans.length() - 1);
        cout<<ans;
        for (int i = ans.length(); i < n; i++) {
            cout<<"a";
        }
        cout<<endl;
    }
}
