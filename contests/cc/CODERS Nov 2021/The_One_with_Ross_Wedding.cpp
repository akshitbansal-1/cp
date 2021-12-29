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
        string s;
        cin>>n>>a>>b;
        a = abs(a), b = abs(b);
        cin>>s;
        vector<int> ar(2, 0);
        int idx = 1, c = 0, c1 = 0, c2 = 0;
        int i = 0;
        for (; i < n; i++) {
            if (s[i] == '0') {
                idx ^= 1;
            } 
            ar[idx]++;
        }
        c1 = ar[0], c2 = ar[1];
        if (c1 >= abs(a) && c2 >= abs(b)) {
            if ((c1 - a) % 2 == 0 && (c2 - b) % 2 == 0) {
                cout<<"YES\n";
                continue;
            }
        } 
        if (c1 >= abs(b) && c2 >= abs(a)) {
            if ((c1 - b) % 2 == 0 % 2 && (c2 - a) % 2 == 0) {
                cout<<"YES\n";
                continue;
            }
        } 
        cout<<"NO\n";
    }
}