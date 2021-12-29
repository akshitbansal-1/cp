/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        long long int sum = 1;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin>>v[i];
        
        for (int i = 0; i < n; i++) {
            while (v[i] % 2 == 0) {
                sum *= 2;
                v[i] /= 2;
            }
        }

        sort(v.begin(), v.end());
        v[n - 1] *= sum;
        sum = 0;
        for (int i = 0; i < n; i++) {
            // cout<<v[i]<<" ";
            sum += v[i];
        }
        cout<<sum<<endl;
    }
}