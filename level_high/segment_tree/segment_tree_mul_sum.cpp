#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long mo = 1e9 + 7;
struct segtree {
    int size;
    vector<long long> sums;
    vector<long long> ops;

    void build(int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = 1;
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m);
        build(2 * x + 2, m, rx);
        sums[x] = (sums[2 * x + 1] + sums[2 * x + 2]) % mo;
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0ll);
        ops.assign(2 * size, 1ll);
        build(0, 0, size);
    }

    void set(int i, int &v, int x, int lb, int rb) {
        if (rb - lb == 1) {
            sums[x] = v;
        }
        int m = (lb + rb) / 2;
        long long sum = 0;
        if (i < m) {
            set(i, v, 2 * x + 1, lb, m);
        } else {
            set(i, v, 2 * x + 2, m, rb);
        }
        sums[x] = min(sums[2 * x + 1], sums[2 * x + 2]) + ops[x];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long get(int l, int r) {
        return get(l, r, 0, 0, size);
    }

    long long get(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return 0;
        if (l <= lb && r >= rb) {
            return sums[x];
        }
        int m = (lb + rb) / 2;
        long long s1 = get(l, r, 2 * x + 1, lb, m);
        long long s2 = get(l, r, 2 * x + 2, m, rb);
        return (((s1 + s2) % mo) * ops[x]) % mo;
    }


    void add(int l, int r, int &v) {
        add(l, r, v, 0, 0, size);
    }

    void add(int l, int r, int &v, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return;
        if (l <= lb && r >= rb) {
            sums[x] = (sums[x] * v) % mo;
            ops[x] = (ops[x] * v) % mo;
            return;
        }
        int m = (lb + rb) / 2;
        add(l, r, v, 2 * x + 1, lb, m);
        add(l, r, v, 2 * x + 2, m, rb);
        long long sum = (sums[2 * x + 1] + sums[2 * x + 2]) % mo;
        sums[x] = (sum * ops[x]) % mo;
    }

    void print() {
        for (int i = 0; i < size; i++) cout<<sums[i]<<" ";
        cout<<endl; 
    }
};


int main() {
    int n, m;
    cin>>n>>m;
    struct segtree st;
    st.init(n);

    while (m--) {
        int op;
        cin>>op;
        if (op == 2) {
            int l, r;
            cin>>l>>r;
            long long sum = st.get(l, r);
            cout<<sum<<endl;
        } else {
            int l, r, v;
            cin>>l>>r>>v;
            st.add(l, r, v);
        }
    }
    return 0;
}