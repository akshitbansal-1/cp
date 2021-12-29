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
        int z = 0, o = 0;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin>>v[i];
        }

        sort(v.begin(), v.end());
        for (int i = 0; i < n / 2; i++) {
            cout<<v[n - i - 1]<<" "<<v[0]<<endl;
        }
    }
}