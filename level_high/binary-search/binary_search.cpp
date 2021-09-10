#include<vector>
#include<iostream>
using namespace std;
int main() {


    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];

    while (q--) {
        int l = -1, r = n;
        int f;
        cin>>f;
        while (r > l + 1) {
            int m  = (l + r) / 2;
            if (v[m] < f) l = m;
            else r = m;
        }
        if (r < n && v[r] == f) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }

    return 0;
}