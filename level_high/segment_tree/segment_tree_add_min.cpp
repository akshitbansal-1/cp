#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct segtree {
    int size;
    vector<long long> mins;
    vector<long long> ops;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        mins.assign(2 * size, 0ll);
        ops.assign(2 * size, 0ll);
    }

    void set(int i, int &v, int x, int lb, int rb) {
        if (rb - lb == 1) {
            mins[x] = v;
        }
        int m = (lb + rb) / 2;
        long long sum = 0;
        if (i < m) {
            set(i, v, 2 * x + 1, lb, m);
        } else {
            set(i, v, 2 * x + 2, m, rb);
        }
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]) + ops[x];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long get(int l, int r) {
        return get(l, r, 0, 0, size);
    }

    long long get(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return LLONG_MAX;
        if (l <= lb && r >= rb) {
            return mins[x];
        }
        int m = (lb + rb) / 2;
        long long s1 = get(l, r, 2 * x + 1, lb, m);
        long long s2 = get(l, r, 2 * x + 2, m, rb);
        return min(s1, s2) + ops[x];
    }


    void add(int l, int r, int &v) {
        add(l, r, v, 0, 0, size);
    }

    void add(int l, int r, int &v, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return;
        if (l <= lb && r >= rb) {
            mins[x] += v;
            ops[x] += v;
            return;
        }
        int m = (lb + rb) / 2;
        add(l, r, v, 2 * x + 1, lb, m);
        add(l, r, v, 2 * x + 2, m, rb);
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]) + ops[x];
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