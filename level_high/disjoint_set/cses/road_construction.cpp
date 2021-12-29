#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, m;
vector<int> v, _rank;

int find(int a) {
    if (v[a] != a) v[a] = find(v[a]);
    return v[a];
}

int _union(int a, int b) { 
    int x = find(a);
    int y = find(b);
    if (_rank[x] < _rank[y]) swap(x, y);
    v[y] = x;
    _rank[x] += _rank[y];
    return _rank[x];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>m;
    v.assign(n + 1, 0);
    _rank.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        v[i] = i;
    }
    int mx = 0;
    int c = n;
    while (m--) {
        int a, b;
        cin>>a>>b;
        int x = find(a);
        int y = find(b);
        if (x != y) {
            mx = max(mx, _union(a, b));
            c--;
        }

        cout<<c<<" "<<mx<<endl;
    }
    return 0;
}