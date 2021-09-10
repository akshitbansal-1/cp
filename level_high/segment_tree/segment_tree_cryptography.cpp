#include<iostream>
#include<algorithm>
#include<vector>
#define int long long int
using namespace std;

int r;
struct segtree {
    int size;
    vector<vector<int> > sums;

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, vector<int>(4, 1));
    }

    vector<int> merge(vector<int> &v1, vector<int> &v2) {
        vector<int> temp;
        temp.push_back(v1[0] * v2[0]);
        temp.push_back(v1[1] * v2[2]);
        temp.push_back(v1[2] * v2[1]);
        temp.push_back(v1[3] * v2[3]);
        return temp;
    }

    void set(int i, vector<int> &v, int x, int lb, int rb) {
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
        sums[x] = merge(sums[2 * x + 1], sums[2 * x + 2]);
    }

    void set(int i, vector<int> &v) {
        set(i, v, 0, 0, size);
    }

    vector<int> sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    vector<int> sum(int l, int r, int x, int lb, int rb) {
        if (l >= rb || r <= lb) {
            vector<int> v;
            v.push_back(1);
            v.push_back(1);
            v.push_back(1);
            v.push_back(1);
            return v;
        };
        if (l <= lb && r >= rb) return sums[x];
        int m = (lb + rb) / 2;
        vector<int> s1 = sum(l, r, 2 * x + 1, lb, m);
        vector<int> s2 = sum(l, r, 2 * x + 2, m, rb);
        return merge(s1, s2);
    }
};


int32_t main() {
    int n, m;
    cin>>r>>n>>m;
    struct segtree st;
    st.init(n);
    for (int i = 0; i < n; i++) {
        vector<int> temp(4);
        for (int j = 0; j < 4; j++) {
            cin>>temp[j];
        }
        st.set(i, temp);
    }

    while (m--) {
        int l, r;
        cin>>l>>r;
        vector<int> v = st.sum(l - 1, r - 1);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cout<<v[i + j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}