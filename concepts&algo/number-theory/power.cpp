#include<bits/stdc++.h>
using namespace std;


//logn

//number, power
int pow(int n, int p) {
    if (p == 1) return n;
    if (p % 2 == 0) {
        return pow(n, p / 2) * pow(n, p / 2);
    } else {
        return n * pow(n, p / 2) * pow(n, p / 2);
    }
}

//number, power, mod
int pow(int n, int p, int m) {
    if (p == 1) return n;
    if (p % 2 == 0) {
        return ((pow(n, p / 2) % m) * (pow(n, p / 2) % m)) % m;
    } else {
        return ((n * pow(n, p / 2)) % m * (pow(n, p / 2) % m)) % m;
    }
}