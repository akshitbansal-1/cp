/*
    Written by: akshitforever
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        vector<int> v(3);
        for (int i = 0; i < 3; i++) cin>>v[i];
        // sort(v.begin(), v.end());
        int x = (v[0] + v[1] + v[2]) % 3;
        if (x == 0) cout<<0<<endl;
        else cout<<1<<endl;
    }
}