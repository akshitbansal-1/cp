/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define int long long int
bool isPerm(string &a, string &t) {
    int j = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == t[j]) j++;
    }
    return j >= t.length();
}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        string s, t;
        cin>>s>>t;
        sort(s.begin(), s.end());
        if (t == "abc") {
            unordered_map<char, int> ma;
            for (int i = 0; i < s.length(); i++) {
                ma[s[i]]++;
            }
            if (ma['a'] && ma['b'] && ma['c']) {

            } else {
                cout<<s<<endl;
                continue;
            }
            int i = 0;
            while (i < s.length() && s[i] == 'a') {
                cout<<s[i];
                i++;
            }
            if (i < s.length() && s[i] == 'b') {
                int y = ma['c'];
                for (int j = 0; j < y; j++) cout<<'c';
                while (i < s.length() && s[i] == 'b') i++;
            }
            if (i < s.length() && s[i] == 'c') {
                int y = ma['b'];
                for (int j = 0; j < y; j++) cout<<'b';
                while (i < s.length() && s[i] == 'c') i++;
            }
            while (i < s.length()) cout<<s[i++];
            // for (int i = 0; i < s.length(); i++) {
            //     if (s[i] == 'b') {
            //         int y = ma['c'];
                    
            //     }
            //     else if (s[i] == 'c') s[i] = 'b';
            //     else cout<<s[i];
            // }
            cout<<endl;
            // cout<<s<<endl;
        } else {
            cout<<s<<endl;
        }
        // sort(s.begin(), s.end());
        // if (isPerm(s, t)) {
        //     for (int i = 0; i < s.length(); i++) {
        //         if (s[i] == t[1]) s[i] = t[2];
        //         if (s[i] == t[2]) s[i] = t[1];
        //     }
        // } else {
        //     cout<<s<<endl;
        //     continue;
        // }
        // if (isPerm(s, t)) {
        //     for (int i = 0; i < s.length(); i++) {
        //         if (s[i] == t[0]) s[i] = t[1];
        //         if (s[i] == t[1]) s[i] = t[0];
        //     }
        // } else {
        //     cout<<s<<endl;
        //     continue;
        // }
        // if (isPerm(s, t)) {
        //     for (int i = 0; i < s.length(); i++) {
        //         if (s[i] == t[0]) s[i] = t[2];
        //         if (s[i] == t[2]) s[i] = t[0];
        //     }
        // } else {
        //     cout<<s<<endl;
        //     continue;
        // }
    }
}