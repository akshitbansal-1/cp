#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct item {
    long long seg, pref, suf, sum;
    item() {seg = 0, pref = 0, suf = 0, sum = 0;}
    item(int s, int p, int su, int sum) {
        seg = s;
        pref = p;
        suf = su;
        this -> sum = sum;
    }
};
struct segtree {
    int size;
    vector<item> mins;

    item get(int v) {
        if (v > 0) return item(v, v, v, v);
        return item(0, 0, 0, v);
    }

    item DEFAULT_ELE;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        mins.assign(2 * size, DEFAULT_ELE);
    }

    item merge(item a, item b) {
        return item(
            max(a.seg, max(b.seg, a.suf + b.pref)),
            max(a.pref, a.sum + b.pref),
            max(b.suf, b.sum + a.suf),
            a.sum + b.sum
        );
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

    item calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }

    item calc(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return DEFAULT_ELE;
        if (l <= lb && r >= rb) return mins[x];
        int m = (lb + rb) / 2;
        item s1 = calc(l, r, 2 * x + 1, lb, m);
        item s2 = calc(l, r, 2 * x + 2, m, rb);
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
    cout<<st.calc(0, n).seg<<endl;
    while (m--) {
        int i, v;
        cin>>i>>v;
        st.set(i, v);
        cout<<st.calc(0, n).seg<<endl;
    }
    return 0;
}