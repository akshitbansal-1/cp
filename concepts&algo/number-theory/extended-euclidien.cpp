#include<bits/stdc++.h>
using namespace std;

// If you have a formula like 
// ax + by = gcd(a,b); where x and y are cofficients of numbers.
// You are given a and b, find any valid values of x and y.
// We can change the equation to 
// bx' + (a % b)y' = gcd(b, a % b); where x' is new cofficient after changing the variables
// as you know gcd(a, b) == gcd(b, a % b), these two would be equal.
// following same process
// (a % b)x'' + b % (a % b)y''
// and so on, at the end we'll get a=1 and b = 0, so we can recurse to get prev sol
// and follow on for original values of x and y.
// The values of x' and y' from x'' and y'' will be by equating any two eq is
// x' = y'', y' = x'' * a/b * y''

vector<int> extended_euclidean(int a, int b) {
    if (b == 0) {
        return {1, 0, a}; //a, b, gcd
    }
    vector<int> mid = extended_euclidean(b, a % b);
    return {mid[1], mid[0] - a/b * mid[1], mid[2]};
}
int main() {
    int a, b;
    cin>>a>>b;
    vector<int> ans = extended_euclidean(a, b);
}