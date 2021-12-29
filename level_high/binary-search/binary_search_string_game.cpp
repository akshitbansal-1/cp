#include<vector>
#include<iostream>
using namespace std;

string s1, s2;
vector<int> p;
vector<bool> v;
bool f(int m) {
    int j = 0;
    for (int i = 0; i <= m; i++) {
        v[p[i] - 1] = false;
    }
    // cout<<"N ";
    for (int i = 0; i < s1.length() && j < s2.length(); i++) {
        if (!v[i]) {
            continue;
        }
        // cout<<s2[j]<<" ";
        if (s2[j] == s1[i]) j++;
    }
    // cout<<j<<endl;
    return j == s2.length();
}

//unfinished    
int main() {

    cin>>s1>>s2;
    int n = s1.length();
    v.assign(n, true);
    p.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin>>p[i];
    }
    int l = 0, r = n;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (f(m)) {
            l = m;
        }
        else {
            r = m;
        }
        for (int i = 0; i < n; i++) v[i] = true;
    }
    cout<<l + 1;

    return 0;
}