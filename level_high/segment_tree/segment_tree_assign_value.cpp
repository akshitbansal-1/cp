#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct segtree {
    int size;
    long long NO_OPERATION;
    vector<long long> sums;

    void init(int n) {
        size = 1;
        NO_OPERATION = 1<<31;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0ll);
    }

    int get(int i, int x, int lb, int rb) {
        propagate(x, lb, rb);
        if (rb - lb == 1) {
            return sums[x];
        }
        int m = (lb + rb) / 2;
        int res;
        if (i < m) {
            res = get(i, 2 * x + 1, lb, m);
        } else {
            res = get(i, 2 * x + 2, m, rb);
        }
        return res;
    }

    int get(int i) {
        return get(i, 0, 0, size);
    }

    void set(int l, int r, int v) {
        set(l, r, v, 0, 0, size);
    }

    long long op(long long x, long long y) {
        if (y == NO_OPERATION) return x;
        return y;
    }

    void apply(long long &x, long long y) {
        x = op(x, y);
    }

    void propagate(int x, int lb, int rb) {
        if (rb - lb == 1) return;
        apply(sums[2 * x + 1], sums[x]);
        apply(sums[2 * x + 2], sums[x]);
        sums[x] = NO_OPERATION;
    }

    void set(int l, int r, int &v, int x, int lb, int rb) {
        propagate(x, lb, rb);
        if (l >= rb || r <= lb) return;
        if (l <= lb && r >= rb) {
            apply(sums[x], v);
            return;
        }
        int m = (lb + rb) / 2;
        set(l, r, v, 2 * x + 1, lb, m);
        set(l, r, v, 2 * x + 2, m, rb);
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
            int i;
            cin>>i;
            int sum = st.get(i);
            cout<<sum<<endl;
        } else {
            int l, r, v;
            cin>>l>>r>>v;
            st.set(l, r, v);
        }
    }
    return 0;
}