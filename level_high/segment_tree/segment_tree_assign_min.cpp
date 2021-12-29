#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long mo = 1e9 + 7;
struct segtree {
    int size;
    vector<long long> values;
    vector<long long> ops;
    long long NO_OPERATION;
    long long NUETRAL_ELEMENT;

    long long modify_op(long long a, long long b) {
        if (b == NO_OPERATION) return a;
        return b;
    }

    void apply_modify_op(long long &a, long long b) {
        a = modify_op(a, b);
    }

    long long calc_op(long long a, long long b) {
        return min(a, b);
    }

    void propagate(int x, int lb, int rb) {
        if (rb - lb == 1) return;
        apply_modify_op(values[2 * x + 1], values[x]);
        apply_modify_op(ops[2 * x + 1], ops[x]);
        apply_modify_op(values[2 * x + 2], values[x]);
        apply_modify_op(ops[2 * x + 2], ops[x]);
        ops[x] = NO_OPERATION;
    }

    void init(int n) {
        size = 1;
        NO_OPERATION = LLONG_MAX - 1;
        NUETRAL_ELEMENT = LLONG_MAX;
        while (size < n) size *= 2;
        values.assign(2 * size, 0ll);
        ops.assign(2 * size, 0ll);
    }

    long long calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }

    long long calc(int l, int r, int x, int lb, int rb) {
        propagate(x, lb, rb);
        if (l >= rb || r <= lb) return NUETRAL_ELEMENT;
        if (l <= lb && r >= rb) {
            return values[x];
        }
        int m = (lb + rb) / 2;
        long long s1 = calc(l, r, 2 * x + 1, lb, m);
        long long s2 = calc(l, r, 2 * x + 2, m, rb);
        long long res = calc_op(s1, s2);
        // apply_modify_op(res, ops[x]);
        return res;
    }


    void modify(int l, int r, int &v) {
        modify(l, r, v, 0, 0, size);
    }

    void modify(int l, int r, int &v, int x, int lb, int rb) {
        propagate(x, lb, rb);
        if (l >= rb || r <= lb) return;
        if (l <= lb && r >= rb) {
            apply_modify_op(values[x], v);
            apply_modify_op(ops[x], v);
            return;
        }
        int m = (lb + rb) / 2;
        modify(l, r, v, 2 * x + 1, lb, m);
        modify(l, r, v, 2 * x + 2, m, rb);
        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
        // apply_modify_op(values[x], ops[x]);
    }

    void print() {
        for (int i = 0; i < 2 * size; i++) cout<<values[i]<<" ";
        cout<<endl; 
    }
};

//unfinished
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
            long long res = st.calc(l, r);
            cout<<res<<endl;
        } else {
            int l, r, v;
            cin>>l>>r>>v;
            st.modify(l, r, v);
            st.print(); 
        }
    }
    return 0;
}