#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct segtree {
    int size;
    vector<long long> sums;

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

    long long calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }

    long long calc(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return 0;
        if (l <= lb && r >= rb) return sums[x];
        int m = (lb + rb) / 2;
        long long sum1 = calc(l, r, 2 * x + 1, lb, m);
        long long sum2 = calc(l, r, 2 * x + 2, m, rb);
        return sum1 + sum2;
    }
};

//unfinished
int main() {
    int n;
    cin>>n;
    segtree st;
    st.init(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        if (i % 2 == 0) st.set(i, a);
        else st.set(i, -a);
    }
    int m;
    cin>>m;
    while (m--) {
        int op;
        cin>>op;
        if (op == 1) {
            int l, r;
            cin>>l>>r;
            int ans = st.calc(l - 1, r);
            if (l % 2 == 0) ans = -ans;
            cout<<ans<<endl;
        } else {
            int i, v;
            cin>>i>>v;
            i--;
            if (i % 2) v = -v;
            st.set(i, v);
        }
    }
    return 0;
}