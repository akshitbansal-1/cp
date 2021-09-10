#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct segtree {
    int size;
    vector<long long> mins;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        mins.assign(2 * size, INT_MAX);
    }

    void set(int i, int &v, int x, int lb, int rb) {
        if (rb - lb == 1) {
            mins[x] = v;
            return;
        }
        int m = (lb + rb) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lb, m);
        } else {
            set(i, v, 2 * x + 2, m, rb);
        }
        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) return INT_MAX;
        if (l <= lb && r >= rb) return mins[x];
        int m = (lb + rb) / 2;
        long long s1 = sum(l, r, 2 * x + 1, lb, m);
        long long s2 = sum(l, r, 2 * x + 2, m, rb);
        return min(s1, s2);
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
            long long sum = st.sum(l, r);
            cout<<sum<<endl;
        }
    }
    return 0;
}