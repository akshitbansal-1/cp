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
        sums.assign(2 * size, 0);
    }

    void set(int i, int v, int x, int lb, int rb) {
        if (rb - lb == 1) {
            sums[x] = v;
            return;
        }
        int m = (lb + rb) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lb, m);
        } else {
            set(i, v, 2 * x + 2, m, rb);
        }
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int calc(int k) {
        // for (int i = 0; i < 2 * size; i++) cout<<sums[i]<<" ";
        // cout<<endl;
        return calc(k, 0, 0, size);
    }

    int calc(int k, int x, int lb, int rb) {
        int m = (lb + rb) / 2;
        if (rb - lb == 1) return lb;
        int lc = sums[2 * x + 1];
        if (k <= lc) {
            return calc(k, 2 * x + 1, lb, m);
        } else {
            return calc(k - lc, 2 * x + 2, m, rb);
        }
    }
};


int main() {
    int n, m;
    cin>>n;
    struct segtree st;
    st.init(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        st.set(i, 1);
    }
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int k = 0;
    for (int i = n - 1; i >= 0; i--) {
        int idx = (st.calc(i + 1 - a[i]));
        st.set(idx, 0);
        a[i] = idx + 1;
    }
    for (int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}