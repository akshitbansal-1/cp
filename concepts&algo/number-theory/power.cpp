#include<bits/stdc++.h>
using namespace std;


//logn

//number, power
int pow(int n, int p) {
    if (p == 1) return n;
    int val = pow(n, p / 2); 
    if (p % 2 == 0) {
        return val * val;
    } else {
        return n * val * val;
    }
}

//number, power, mod
int pow(int n, int p, int m) {
    if (p == 1) return n;
    int val = pow(n, p / 2); 
    if (p % 2 == 0) {
        return ((val % m) * (val % m)) % m;
    } else {
        return ((n * val) % m) * (val % m)) % m;
    }
}
