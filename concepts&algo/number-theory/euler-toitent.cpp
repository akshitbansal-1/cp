#include<bits/stdc++.h>
using namespace std;

// Given n find all 1-n which are coprime with n.
// 1. If n is primn then ans = n - 1
// 2. If n is in form prime^a then ans = prime^a-prime^a/prime
// 3. For d(a*b) = d(a) * d(b)
// so we can get all the prime factors in sqrt(n) for n
// for each we can apply above formulas
// for each prime^a, we can get its coprimes using 2.


int euler_toitent(int n) {
    int c = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            c -= c/i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    if (n > 1) {
        c -= c/n;
    }
    return c;
}
int main() {
    int n;
    cin>>n;
    cout<<euler_toitent(n);
}