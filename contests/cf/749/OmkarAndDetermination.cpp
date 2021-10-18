#include<bits/stdc++.h>

using namespace std;
vector<string> v, v2;
vector<int> is;

struct segtree {
    int size;
    vector<long long> mins;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        mins.assign(2 * size, 1);
    }

    void set(int i, int &v, int x, int lb, int rb) {
        if (rb - lb == 1) {
            mins[x] = v;
            return;
        }
        int m = (lb + rb) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lb, m);
        } else {
            set(i, v, 2 * x + 2, m, rb);
        }
        mins[x] = (mins[2 * x + 1] && mins[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size - 1);
    }

    long long sum(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return 1;
        if (l <= lb && r >= rb) return mins[x];
        int m = (lb + rb) / 2;
        long long s1 = sum(l, r, 2 * x + 1, lb, m);
        long long s2 = sum(l, r, 2 * x + 2, m, rb);
        // cout<<lb<<" "<<rb<<" -> "<<(s1 && s2)<<endl;
        return (s1 && s2);
    }

    void print() {
        for (int i = 0; i < 2 * size; i++) {cout<<mins[i]<<" ";} cout<<endl;
    }
};

struct segtree st;

void make() {
    int n = v[0].length();
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j < v.size(); j++) {
            if (v[j][i - 1] == 'X' && v[j - 1][i] == 'X') {
                is[i] = 0;
            }
        }
    }

    st.init(n);
    for (int i = 0; i < n; i++) {
        st.set(i, is[i]);
    }
    st.print();
}
int main() {
    int n, m;
    cin>>n>>m;
    v.assign(n, "");
    is.assign(m, 1);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    make();
    int q;
    cin>>q;
    while (q--) {
        int m1, m2;
        cin>>m1>>m2;
        if (m1 == m2) cout<<"YES\n";
        else {
            m1--,m2--;
            // cout<<m1<<" "<<m2<<endl;
            int x = st.sum(m1, m2);
            // cout<<endl<<endl;
            if (x) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}