/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
#define int long long int


int f(int x) {
    x += 1;
    while (x % 10 == 0) {
        x /= 10;
    }
    return x;
}
int32_t main() {
    int n;
    cin>>n;
    unordered_set<int> s;
    int ans = 1;
    s.insert(n);
    while (true) {
        int x = f(n);
        if (s.find(x) != s.end()) break;
        ans++;
        s.insert(x);
        n = x;
    }
    cout<<ans<<endl;
}