#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    string s;
    cin>>s;
    s += "$";
    int n = s.length();
    vector<int> p(n), c(n);

    {
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++) {
            a[i] = make_pair(s[i], i);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }

    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int > > a(n);
        for (int i = 0; i < n; i++) {
            a[i] = make_pair(make_pair(c[i], c[(i + (1 << k)) % n]), i);
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) p[i] = a[i].second;
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }
    for (int i = 0; i < n; i++){
        cout<<p[i]<<" ";
    }

}