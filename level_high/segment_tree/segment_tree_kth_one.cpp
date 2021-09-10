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

    int find(int k) {
        return calc(k, 0, 0, size);
    }

    int calc(int k, int x, int lb, int rb) {
        if (lb > size || rb < 0 || lb > rb) return -1;
        if (rb - lb == 1) return lb;
        int m = (lb + rb) / 2;
        int l = sums[2 * x + 1];

        if (k < l) {
            return calc(k, 2 * x + 1, lb, m);
        } else {
            k -= l;
            return calc(k, 2 * x + 2, m, rb);
        }
    }
};


int main() {
    int n, m;
    cin>>n>>m;
    struct segtree st;
    st.init(n);
    vector<int> x;
    for (int i = 0; i < n; i++) {
        int a;
        cin>>a;
        x.push_back(a);
        st.set(i, a);
    }
    while (m--) {
        int op;
        cin>>op;

        if (op == 1) {
            int i, v;
            cin>>i;
            x[i] = !x[i];
            st.set(i, x[i]);
        } else {
            int k;
            cin>>k;
            cout<<st.find(k)<<endl; 
        }
    }
    return 0;
}