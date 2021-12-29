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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    int curr = 0;
    string ans = "";
    for (int i = 0, j = n - 1; i <= j;) {
        if (v[i] < curr && v[j] < curr) break;
        if (v[i] < curr) {
            ans += 'R';
            curr = v[j--];
        } else if (v[j] < curr) {
            ans += 'L';
            curr = v[i++];
        } else if (v[i] < v[j]) {
            ans += 'L';
            curr = v[i++];
        } else {
            ans += 'R';
            curr = v[j--];
        }
    }
    cout<<ans.length()<<"\n"<<ans;

}