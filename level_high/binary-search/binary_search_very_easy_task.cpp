#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, a, b;
bool f(int m) {
    return m / a + m / b >= n;
}
int main() {
    cin>>n>>a>>b;
    if (n == 1) {
        cout<<min(a, b);
        return 0;
    }
    int m = min(a, b);
    n--;
    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (!f(m)) l = m;
        else r = m;
    }
    cout<<l + m + 1;
}

