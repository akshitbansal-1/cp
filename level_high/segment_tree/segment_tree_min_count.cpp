#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct item {
    int v, c;
    item() {}
    item(int v, int c) {
        this->v = v;
        this -> c = c;
    }
};
struct segtree {
    int size;
    vector<item> mins;

    item get(int v) {
        return item(v, 1);
    }

    item DEFAULT_ELE;

    segtree() { 
        DEFAULT_ELE = item(INT_MAX, 0);
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        mins.assign(2 * size, DEFAULT_ELE);
    }

    item merge(item a, item b) {
        if (a.v < b.v) return a;
        else if (a.v > b.v) return b;
        return item(a.v, a.c + b.c);
    }

    void set(int i, int &v, int x, int lb, int rb) {
        if (rb - lb == 1) {
            mins[x] = get(v);
            return;
        }
        int m = (lb + rb) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lb, m);
        } else {
            set(i, v, 2 * x + 2, m, rb);
        }
        mins[x] = merge(mins[2 * x + 1], mins[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    item sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    item sum(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return DEFAULT_ELE;
        if (l <= lb && r >= rb) return mins[x];
        int m = (lb + rb) / 2;
        item s1 = sum(l, r, 2 * x + 1, lb, m);
        item s2 = sum(l, r, 2 * x + 2, m, rb);
        return merge(s1, s2);
    }
};


int main() {
    int n, m;
    cin>>n>>m;
    struct segtree st;
    st.init(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        st.set(i, a);
    }

    while (m--) {
        int op;
        cin>>op;
        if (op == 1) {
            int i, v;
            cin>>i>>v;
            st.set(i, v);
        } else {
            int l, r;
            cin>>l>>r;
            item sum = st.sum(l, r);

            cout<<sum.v<<" "<<sum.c<<endl;
        }
    }
    return 0;
}