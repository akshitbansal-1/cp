#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long mo = 1e9 + 7;
struct segtree {
    int size;
    vector<long long> sums;
    vector<long long> ops;

    long long modify_op(long long &a, long long b) {
        return a | b;
    }

    void apply_modify_op(long long &a, long long b) {
        a = modify_op(a, b);
    }

    long long calc_op(long long a, long long b) {
        return a & b;
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0ll);
        ops.assign(2 * size, 0ll);
        // build(0, 0, size);
    }

    long long calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }

    long long calc(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return (-1);
        if (l <= lb && r >= rb) {
            return sums[x];
        }
        int m = (lb + rb) / 2;
        long long s1 = calc(l, r, 2 * x + 1, lb, m);
        long long s2 = calc(l, r, 2 * x + 2, m, rb);
        long long res = calc_op(s1, s2);
        apply_modify_op(res, ops[x]);
        return res;
    }


    void modify(int l, int r, int &v) {
        modify(l, r, v, 0, 0, size);
    }

    void modify(int l, int r, int &v, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return;
        if (l <= lb && r >= rb) {
            apply_modify_op(ops[x], v);
            apply_modify_op(sums[x], v);
            return;
        }
        int m = (lb + rb) / 2;
        modify(l, r, v, 2 * x + 1, lb, m);
        modify(l, r, v, 2 * x + 2, m, rb);
        sums[x] = calc_op(sums[2 * x + 1], sums[2 * x + 2]);
        apply_modify_op(sums[x], ops[x]);
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
            long long sum = st.calc(l, r);
            cout<<sum<<endl;
        } else {
            int l, r, v;
            cin>>l>>r>>v;
            st.modify(l, r, v);
        }
    }
    return 0;
}