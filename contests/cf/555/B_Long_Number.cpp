/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long int

int32_t main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v(10);
    for (int i = 1; i <= 9; i++) cin>>v[i];
    bool b = false;
    for (int i = 0; i < n; i++) {
        if (s[i] - '0' >= v[s[i] - '0']) continue;
        while (i < n && s[i] - '0' <= v[s[i] - '0']) {
            s[i] = '0' + v[s[i] - '0'];
            i++;
            b = true;
        }
        if (b) break;
    }
    cout<<s;
}