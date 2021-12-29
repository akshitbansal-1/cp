#include<vector>
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {


    double c;
    cin>>c;
    
    double l = 0, r = c, m;
    cout<<setprecision(20);
    for (int i = 0; i < 100; i++) {
        m  = (l + r) / 2;
        double x = m * m + sqrt(m);
        if (x == c) {
            cout<<m;
            return 0;
        }
        if (x < c) l = m;
        else r = m;
    }
    cout<<m;
    return 0;
}