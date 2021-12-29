#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int search(string& s, string& pat) {
    int l = 0, h = s.length() - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        int res = strncmp(pat.c_str(), s.c_str() + m, pat.length());
        if (res == 0) return true;
        else if (res < 0) h = m - 1;
        else l = m + 1;
    }
    return false;
}
void sort(vector<pair<pair<int, int>, int > > &a) {
    {
        int n = a.size();
        vector<pair<pair<int, int>, int > > a_new(n);
        vector<int> pos(n);
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            pair<pair<int, int>, int> &x = a[i];
            cnt[x.first.second]++;
        }
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (int i = 0; i < n; i++) {
            pair<pair<int, int>, int> x = a[i];
            int idx = x.first.second;
            a_new[pos[idx]] = x;
            pos[idx]++;
        }
        a = a_new;
    }
    {
        int n = a.size();
        vector<pair<pair<int, int>, int > > a_new(n);
        vector<int> pos(n);
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            pair<pair<int, int>, int> &x = a[i];
            cnt[x.first.first]++;
        }
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i - 1] + cnt[i - 1];
        }
        for (int i = 0; i < n; i++) {
            pair<pair<int, int>, int> x = a[i];
            int idx = x.first.first;
            a_new[pos[idx]] = x;
            pos[idx]++;
        }
        a = a_new;
    }
}
//unfinished
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
        sort(a);
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
    for (int i = 0; i < n; i++) {
        cout<<p[i]<<" "<<s.substr(p[i], n - 1 - p[i])<<" "<<c[i]<<endl;
    }
    s = s.substr(0, s.length() - 1);
    // int q;
    // cin>>q;
    // while (q--) {
    //     string pat;
    //     cin>>pat;
    //     bool found = search(s, pat);
    //     if (found)cout<<"Yes";
    //     else cout<<"No";
    //     cout<<endl;
    // }

}