/*
    Written by: akshitforever
*/

#include<iostream>
using namespace std;


int d(int a, int b, int c, int d) {
    return abs(c-a) + abs(d-b);
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int a, b;
        cin>>a>>b;
        if ((a+b) % 2 == 1) {
            cout<<"-1 -1"<<endl;
            continue;
        }
        int dist = d(0, 0, a, b) / 2;
        if (a % 2 == 0 && b % 2 == 0) {
            cout<<a/2<<" "<<b/2<<endl;
        }else {
            if (a > b) {
                cout<<a/2<<" "<<(dist - a / 2)<<endl;
            } else {
                cout<<(dist - b/2)<<" "<<b/2<<endl;
            }
        }

    }
}