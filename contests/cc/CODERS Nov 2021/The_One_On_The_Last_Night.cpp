/*
    Written by: akshitforever
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        string n;
        int k;
        cin>>n>>k;
        while (k--) {
            sort(n.begin(), n.end());
            int i = 0;
            while (n[i] == '9') {
                i++;
            }
            if (i >= n.length()) break;
            n[i] = n[i] + 1;
        }
        int i = 0;
        long long int ans = 1;
        while (i < n.length()) {
            ans *= n[i++] - '0';
        }
        cout<< ans<<endl;;
    }
}