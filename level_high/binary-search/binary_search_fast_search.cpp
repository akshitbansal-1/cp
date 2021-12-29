#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main() {


    int n, q;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    cin>>q;
    while (q--) {
        int l = -1, r = n;
        int x;
        cin>>x;
        while (r > l + 1) {
            int m  = (l + r) / 2;
            if (v[m] < x) l = m;
            else r = m;
        }
        cin>>x;
        int l2 = r;
        l = -1, r = n;
        while (r > l + 1) {
            int m  = (l + r) / 2;
            if (v[m] <= x) l = m;
            else r = m;
        }
        cout<<(l - l2 + 1)<<"\n";
    }

    return 0;
}