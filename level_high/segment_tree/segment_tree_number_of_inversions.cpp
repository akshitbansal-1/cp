#include<iostream>
#include<algorithm>
#include<vector>
#define int long long int
using namespace std;

int r;
struct segtree {
    int size;
    vector<pair<int, vector<int> > > sums;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, make_pair(0, vector<int>(41, 0)));
    }

    pair<int, vector<int> > merge(pair<int, vector<int> > &v1, pair<int, vector<int> > &v2) {
        vector<int> temp1(41, 0);
        for (int i = 39; i >= 0; i--) {
            temp1[i] += temp1[i + 1] + v1.second[i + 1];
        }
        vector<int> temp(41, 0);
        int c = temp[0];
        for (int i = 0; i < 40; i++) {
            if (v2.second[i]) {
                cout<<i<<" "<<v1.second[i]<<" "<<temp1[i]<<endl;
                c += temp1[i + 1];
            }
            temp[i] = v1.second[i] + v2.second[i];
        }
        return make_pair(c + v1.first + v2.first, temp);
    }

    void set(int i, vector<int> &v, int x, int lb, int rb) {
        if (rb - lb == 1) {
            sums[x] = make_pair(0, v);
            return;
        }
        int m = (lb + rb) / 2;
        if (i < m) {
            set(i, v, 2 * x + 1, lb, m);
        } else {
            set(i, v, 2 * x + 2, m, rb);
        }
        sums[x] = merge(sums[2 * x + 1], sums[2 * x + 2]);
    }

    void set(int i, vector<int> &v) {
        set(i, v, 0, 0, size);
    }

    pair<int, vector<int> > sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    pair<int, vector<int> > sum(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) {
            vector<int> v(41, 0);
            return make_pair(0, v);
        };
        if (l <= lb && r >= rb) return sums[x];
        int m = (lb + rb) / 2;
        pair<int, vector<int> > s1 = sum(l, r, 2 * x + 1, lb, m);
        pair<int, vector<int> > s2 = sum(l, r, 2 * x + 2, m, rb);
        return merge(s1, s2);
    }
};


int32_t main() {
    int n, m;
    cin>>n>>m;
    struct segtree st;
    st.init(n);
    for (int i = 0; i < n; i++) {
        vector<int> temp(41, 0);
        int a;
        cin>>a;
        temp[a] = 1;
        st.set(i, temp);
    }

    while (m--) {
        int op;
        cin>>op;
        if (op == 1) {
            int l, r;
            cin>>l>>r;
            int x = st.sum(l - 1, r).first;
            cout<<(x)<<endl;
        } else {
            int i, v;
            cin>>i>>v;
            i--;
            vector<int> temp(41, 0);
            temp[v] = 1;
            st.set(i, temp);
        }
    }
    return 0;
}