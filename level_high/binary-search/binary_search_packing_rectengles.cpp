#include<vector>
#include<iostream>
using namespace std;

long long n, w, h;
bool f(long long x) {
    return (x/w) * (x/h) >= n;
}
int main() {

    cin>>w>>h>>n;
    long long l = 0, r = 1;
    while (!f(r)) r *= 2;
    // cout<<r;
    while (l + 1 < r) {
        long long m = (l + r) / 2;
        if (!f(m)) l = m;
        else r = m;
        // cout<<l<<" "<<r<<endl;
    }
    cout<<r<<endl;
    return 0;
}