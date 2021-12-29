/*
    Written by: akshitforever
*/

#include<iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        int n = s.length();
        if ((s[n - 1] - '0') % 2 == 0) {
            cout<<0<<endl;
            continue;
        }
        int i;
        for (i = 0; i < n; i++) {
            if ((s[i] - '0') % 2 == 0) {
                break;
            }
        }
        if (i == n) {
            cout<<-1<<endl;
        } else {
            if ((s[0] - '0') % 2 == 0) cout<<1<<endl;
            else cout<<2<<endl;
        }
    }
}