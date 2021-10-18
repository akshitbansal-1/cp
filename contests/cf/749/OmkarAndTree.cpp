#include<bits/stdc++.h>

using namespace std;
vector<int> v;
void solve() {
    int root = 1;
    int n = v.size() - 1;
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) { 
            root = i; 
            for (int j = 1; j <= n; j++) {
                if (j != root) cout<< root << " "<<j<<endl;
            }
            return;
        }
    }
    

}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        v.assign(n + 1, 0);
        int sum = 0;
        for (int i = 0; i < k; i++) {
            int a, b, c;
            cin>>a>>b>>c;
            v[b] = 1;
        }
        solve();
    }




}