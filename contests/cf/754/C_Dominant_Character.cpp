/*
    Written by: akshitforever
*/

#include<bits/stdc++.h>
using namespace std;
int solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    n = s.length();
    int start = 0, i = 0;
    int ans = INT_MAX;
    vector<int> v(3, 0);
    for (int i = 0; i < n; i++) {
        int j = i;
        if (i > 0 && s[i - 1] == 'a' && s[i] == 'a') return 2;
        while (j < n && j <= i + 7) {
            v[s[j]-'a']++;
            if (j - i >= 2 && v[0] > v[1] && v[0] > v[2]) {
                ans = min(ans, j - i + 1);
            }
            j++;
        }
        v[0] = 0, v[1] = 0, v[2] = 0;
    }

    return ans == INT_MAX ? -1 : ans;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        cout<<solve()<<endl;;
    }
}