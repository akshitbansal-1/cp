/*
    Written by: akshitforever
*/

#include<iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        long long int a, b, x;
        cin>>a>>b>>x;
        if (a == x || b == x) {
            cout<<"YES\n";
            continue;
        }
        // cout<<a<<" "<<b<<" "<<x<<endl;
        if (x > a && x > b) {
            cout<<"NO\n";
            continue;
        }
        int i = 1;
        bool bo = true;
        while (i++ <= 100000) {
            if (a == x || b == x) {
                cout<<"YES\n";
                bo = false;
                break;
            }
            if (a == 0 || b == 0) break;
            if ((max(a, b) - x) % min(a, b) == 0) {
                cout<<"YES\n";
                bo = false;
                break;
            }
            long long int a1 = abs(max(a,b) % min(a,b));
            if (a > b) a = a1;
            else b = a1;
        }
        if (bo)
        cout<<"NO\n";
    }
}