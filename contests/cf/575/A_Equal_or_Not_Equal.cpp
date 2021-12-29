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
    cin >> t;

    while(t--){
        string str;
        cin >> str;
        int i;
        int c = 0;
        for (i = 0; i < str.size(); i++) {
            if (str[i] == 'N') c++;
        }
        if (c == 1) cout<<"NO\n";
        // else if (c == 1) cout<<"NO\n"; 
        else cout<<"YES\n";
    }
}