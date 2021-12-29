#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<int> v, counts, mi, ma;

int find(int a) {
    if (v[a] != a) v[a] = find(v[a]);
    return v[a];
}

void _union(int a, int b) { 
    int x = find(a);
    int y = find(b);
    // cout<<x<<" "<<y<<endl;
    if (x != y) {
        counts[x]+=counts[y];
    }
    mi[x] = min(mi[x], mi[y]);
    ma[x] = max(ma[x], ma[y]);
    v[y] = x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    v.assign(n + 1, 0);
    counts.assign(n + 1, 1);
    mi.assign(n + 1, n + 1);
    ma.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        v[i] = i;
        mi[i] = i;
        ma[i] = i;
    }
    while (m--) {
        string s;
        cin>>s;
        if (s == "union") {
            int a, b;
            cin>>a>>b;
            _union(a, b);
        } else {
            int a;
            cin>>a;
            int x = find(a);
            cout<<mi[x]<<" "<<ma[x]<<" "<<counts[x]<<endl;
        }
    }
    return 0;
}