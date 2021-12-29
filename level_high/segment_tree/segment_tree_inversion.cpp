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

    int calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }

    int calc(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return 0;
        if (l <= lb && r >= rb) return sums[x];
        int m = (lb + rb) / 2;
        int sum1 = calc(l, r, 2 * x + 1, lb, m);
        int sum2 = calc(l, r, 2 * x + 2, m, rb);
        return sum1 + sum2;
    }
};


int main() {
    int n, m;
    cin>>n;
    struct segtree st;
    st.init(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        cout<<st.calc(a, n)<<" ";
        st.set(a - 1, 1);
    }
    return 0;
}