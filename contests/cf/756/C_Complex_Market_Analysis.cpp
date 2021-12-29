/*
    Written by: akshitforever
*/

#include<iostream>
using namespace std;
#define int long long int
bool isPrime(int a) {
    if (a < 2) return false;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    } return true;
}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        int n, e;
        cin>>n>>e;
        int ar[n], dp[n];
        for (int i = 0; i < n; i++) {
            cin>>ar[i];
        }
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(ar[i])) {
                int j = i + e, r1 = 0, r2 = 0;
                while (j < n && ar[j] == 1) {
                    r2++;
                    j+=e;
                }
                j = i - e;
                while (j >= 0 && ar[j] == 1) {
                    r1++;
                    j-=e;
                }
                int res1 = r1 + r2 + r1 * r2;

                c += res1;
            }
        }
        cout<<c<<endl;

    }
}