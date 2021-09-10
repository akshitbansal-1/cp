#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define int long long int

int lcs(string &X, string &Y)
{
    int m = X.length(), n = Y.length();
    int L[m + 1][n + 1];
    int i, j;
     
    /* Following steps build L[m+1][n+1] in
    bottom up fashion. Note that L[i][j]
    contains length of LCS of X[0..i-1]
    and Y[0..j-1] */
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = 0;
     
        else if (X[i - 1] == Y[j - 1])
            L[i][j] = L[i - 1][j - 1] + 1;
     
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
         
    /* L[m][n] contains length of LCS
    for X[0..n-1] and Y[0..m-1] */
    return L[m][n];
}
unordered_set<string> sm;
vector<string> v;
int ans = INT_MAX;
string x;
void bf(string &s, string temp, int i) {
    // cout<<temp<<endl;
    if (i > s.length()) {
        return;
    }
    if (find(sm.begin(), sm.end(), temp) != sm.end()) {
        // cout<<"temp: "<<temp<<endl;
        ans = min(ans, abs((int)temp.length() - (int)s.length()));
    }
    for (int i = 0; i < v.size();i++) {
        
        string k = temp + v[i];
        if (find(sm.begin(), sm.end(), k) != sm.end()) {
            // cout<<"k: "<<k<<endl;
            ans = min(ans, abs((int)s.length() - (int)temp.length() + 1));
        }
    }
    if (i < s.length())
        bf(s, temp + s[i], i + 1);
    bf (s, temp, i + 1);
}


int32_t main() {
    int t;
    cin>>t;
    int up = 1e9;
    int x1 = 1;
    v.push_back("2");
    v.push_back("4");
    v.push_back("6");
    v.push_back("8");
    while (x1 <= up) {
        sm.insert(to_string(x1));
        x1 = x1 * 2;
    }
    while (t--) {
        int n;
        cin>>n;
        if ((n & (n - 1)) == 0) {
            cout<<0<<endl;
            continue;
        }
        x = to_string(n);
        bf(x, "", 0);
        cout<<ans<<endl;
        // int m = -1, idx = 0, ans = INT_MAX;
        // for (int i  = 0; i < strs.size() && strs[i].length() <= x.length() + 1; i++) {
        //     int y = lcs(x, strs[i]);
        //     if (m < y) {
        //         // int x = stoll(strs[i]);
        //         cout<<strs[i]<<" ";
        //         ans = min((int)x.length() - m, ans);
        //         idx = i;
        //         m = y;
        //     }
        //     // m = max(lcs(x, strs[i]), m);
        // }
        // cout<<ans<<endl;
        // int res = x.length() - m + 1;
        // cout<<res<<endl;
    }
}
