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
        // for (int i = 10; i < 1e7; i++) {
            int a, b, c;
            // n = i;
            if (n % 2 == 0) {
                a = n / 2;
                b = a - 1;
                c = 1;
            } else {
                if ((n / 2) % 2) {
                    a = n / 2 - 2;
                    b = a + 4;
                    c = 1;
                } else {
                    a = n / 2 - 1;
                    b = a + 2;
                    c = 1;
                }
            }
            cout<<a<<" "<<b<< " "<<c<<endl;
        
    }
}