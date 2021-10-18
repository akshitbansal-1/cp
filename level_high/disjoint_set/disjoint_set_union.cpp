#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<int> v;

int find(int a) {
    if (v[a] != a) v[a] = find(v[a]);
    return v[a];
}

void _union(int a, int b) { 
    int x = find(a);
    int y = find(b);
    v[x] = y;
}
int main() {

    cin>>n>>m;
    v.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) v[i] = i;
    while (m--) {
        string s;
        int a, b;
        cin>>s>>a>>b;
        if (s == "union") {
            _union(a, b);
        } else {
            int x = find(a);
            int y = find(b);
            if (x == y) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}