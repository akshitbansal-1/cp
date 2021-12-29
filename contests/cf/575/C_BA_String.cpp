/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int
int sum(int x) {
    return x * (x + 2) / 2;
}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        // cout<<"here\n";
        int n, k, x;
        cin>>n>>k>>x;
        string s;
        cin>>s;
        int a = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a++;
        }
        int st = 1;
        bool enc = false;
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            cout<<st<<endl;
            if (s[i] == '*') {
                int prev = st;
                if (enc) st += sum(st + k) - sum(st);
                else st += k;
                int diff = min(x-prev, st - prev);
                if (st >= x) {
                    ans += string(diff, 'b');
                    break;
                } else {
                    ans += string(diff, 'b');
                }
            } else {
                ans += 'a';
                // st += 1;
                a--;
                enc = true;
                if (ans.size() == x) break;
            }
        }
            cout<<st<<endl;

        for (int i = 0; i < a; i++) cout<<'a';
        cout<<ans<<endl;
    }
}