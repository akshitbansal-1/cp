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
        // for (int i = 0; i < 2 * size; i++) cout<<sums[i]<<" ";
        // cout<<endl;
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


int main() {
    int n, m;
    cin>>n;
    struct segtree st;
    st.init(2 * n);
    vector<int> a(2 * n);
    vector<vector<int > > v(n);
    vector<int> ans(n);
    for (int i = 0; i < 2 * n; i++) {
        cin>>a[i];
        if (v[a[i] - 1].size() > 0) {
            ans[a[i] - 1] = st.calc(v[a[i] - 1][0], i);
            st.set(v[a[i] - 1][0], 1);
        }
        v[a[i] - 1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        // cout<<v[i].size();
        cout<<(ans[i])<<" ";
    }
    return 0;
}