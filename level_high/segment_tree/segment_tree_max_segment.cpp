#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct segtree {
    int size;
    vector<int> sums;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, 0ll);
    }

    int get(int i, int x, int lb, int rb) {
        if (rb - lb == 1) {
            return sums[x];
        }
        int m = (lb + rb) / 2;
        int sum = 0;
        if (i < m) {
            sum = get(i, 2 * x + 1, lb, m);
        } else {
            sum = get(i, 2 * x + 2, m, rb);
        }
        return max(sum, sums[x]);
    }

    int get(int i) {
        return get(i, 0, 0, size);
    }

    void set(int l, int r, int v) {
        set(l, r, v, 0, 0, size);
    }

    void set(int l, int r, int &v, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return;
        if (l <= lb && r >= rb) {
            sums[x] = max(v, sums[x]);
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