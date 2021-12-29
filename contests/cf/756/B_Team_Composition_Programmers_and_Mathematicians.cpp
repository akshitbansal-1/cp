/*
    Written by: akshitforever
*/

#include<iostream>
using namespace std;
void solve(int a, int b) {
    // if ((a + b) < 4) {
    //     cout<<0<<endl;
    //     return;
    // }
    // int ans = 0;
    // int a1 = a, b1 = b;
    // while (a && b) {
    //     if (a < b) swap(a, b);
    //     int t = min(a / 3, b);
    //     if (t == 0) break;
    //     ans += t;
    //     a = a - t * 3, b = max(b - t, 0);
    // }
    // a = a1, b = b1;
    // int ans2 = 0;
    // while (a && b) {
    //     if (a < b) swap(a, b);
    //     int t = min(a / 2, b / 2);
    //     if (t == 0) break;
    //     ans2 += t;
    //     a = a - t * 2, b = max(b - t * 2, 0);
    // }
    cout<<min((a + b) / 4, min(a, b))<<endl;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int a, b;
        cin>>a>>b;
        if (a == b) {
            cout<<(a+b) / 4<<endl;
        } else if (a < b) {
            swap(a, b);
            solve(a, b);
        } else {
            solve(a, b);
        }


    }
}