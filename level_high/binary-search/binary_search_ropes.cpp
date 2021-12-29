#include<vector>
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

long long n, k;
vector<int> v;
bool f(double x) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += floor(v[i] / x);
    }
    return s >= k;
}
int main() {

    cin>>n>>k;
    v.assign(n, 0);
    for (int i = 0; i < n; i++) cin>>v[i];
    double l = 0, r = 1e8;
    for (int i = 0; i < 100; i++) {
        double m = (l + r) / 2;
        if (f(m)) l = m;
        else r = m;
    }
    cout<<setprecision(20)<<l;
    return 0;
}