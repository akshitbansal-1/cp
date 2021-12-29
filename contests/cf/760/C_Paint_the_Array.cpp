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
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin>>v[i];

        int a = 0, b = 0;
        for (int i = 0; i < n; i += 2) {
            a = __gcd(a, v[i]);
        }
        for (int i = 1; i < n; i += 2) {
            b = __gcd(b, v[i]);
        }
        // cout<<a<<" "<<b<<endl;
        bool b1 = false, b2 = false;
        if (a == 1 && b == 1) {
            cout<<0<<endl;
            continue;
        }
        else if (a == 1) {
            for (int i = 0; i < n; i += 2) {
                if (v[i] % b == 0) {
                    b2 = true;
                    break;
                }
            }
            if (b2) {
                cout<<0<<endl;
                continue;
            }
        } else if (b == 1) {
            for (int i = 1; i < n; i += 2) {
                if (v[i] % a == 0) {
                    b1 = true;
                    break;
                }
            }
            if (b1) {
                cout<<0<<endl;
                continue;
            }
        }
        for (int i = 0; i < n; i += 2) {
            if (v[i] % b == 0) {
                b2 = true;
                break;
            }
        }
        for (int i = 1; i < n; i += 2) {
            if (v[i] % a == 0) {
                b1 = true;
                break;
            }
        }
        if (b1 && b2) {
            cout<<0<<endl;
            continue;
        } else if (b1) {
            cout<<b<<endl;
            continue;
        } else {
            cout<<a<<endl;
            continue;
        }
        
    }
}