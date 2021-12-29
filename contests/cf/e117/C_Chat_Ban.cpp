/*
    Written by: akshitforever
*/

#include<iostream>
using namespace std;
#define lli  long long int

lli sum (lli x) {
    if (x < 0) return 0;
    return (x * (x + 1)) / 2;
}

lli calc(lli k, lli m) {
    if (m <= k) {
        return sum(m);
    } 
    int more = k - 1 - (m - k);
    return sum(k) + sum(k - 1) - sum(more);
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        lli k, x;
        cin>>k>>x;
        lli kt = 2 * k - 1;
        lli l = 1, h = 2 * k - 1;
        lli ans = 0;
        while (l <= h) {
            lli mid = (l + h) / 2;
            lli c = calc(k, mid);
            // cout<<c<<" ";
            int diff = mid <= k ? mid : k - (mid - k);
            if (c - diff < x) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        // cout<<endl;
        cout<<ans<<endl;
    }
}