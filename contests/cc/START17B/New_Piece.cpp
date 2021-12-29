/*
    Written by: akshitforever
*/

#include<iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if (a == c && b == d) cout<<0<<endl;
        else if ((a + b) % 2) {
            if ((a + b) % 2 == 1) cout<<2<<endl;
            else cout<<1<<endl;
        } else {
            if ((a + b) % 2 == 0) cout<<2<<endl;
            else cout<<1<<endl;
        }
    }
}