/*
    Written by: akshitforever
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++) cin>>arr[i];
        bool b = true;
        for (int i = 0; i < n - 1; i++) if (arr[i + 1] > arr[i]) {
            cout<<-1<<endl;
            b = false;
        }
        if (!b) continue;
        long long int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) cout<<arr[i]<<" ";
            else if (arr[i] == 1) {
                cout<<(1e9 + 7)<<" ";
            } else {
                cout<<(sum + arr[i])<<" ";
            }
            sum += arr[i];
        }
        cout<<endl;
    }
}