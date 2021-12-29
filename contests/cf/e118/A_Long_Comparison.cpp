/*
    Written by: akshitforever
*/

#include<iostream>
using namespace std;
#define int long long int
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        string a;
        int z1;
        string b;
        int z2;
        cin>>a>>z1>>b>>z2;
        int i = 0, j = 0;
        if (z1 > z2) {
            z1 = z1 - z2;
            if (a.length() + z1 > b.length()) {
                cout<<">\n";
                continue;
            } else if (a.length() + z1 == b.length()) {
                int i = 0, j = 0;
                bool c = true;
                while (i < a.length() + z1 && j < b.length()) {
                    char ch = i < a.length() ? a[i] : '0';
                    if (ch > b[j]) {
                        break;
                    } else if (ch < b[j]) {
                        c = false;
                        break;
                    }
                    i++; j++;
                }
                if (i == a.length() + z1 && j == b.length()) {
                    cout<<"=\n";
                    continue;
                }
                else if (c) {
                    cout<<">\n";
                    continue;
                } else {
                    cout<<"<\n";
                    continue;
                }
            } else {
                cout<<"<\n";
            }
        } else {
            z2 = z2 - z1;
            if (b.length() + z2 > a.length()) {
                cout<<"<\n";
                continue;
            } else if (b.length() + z2 == a.length()) {
                int i = 0, j = 0;
                bool c = true;
                while (i < a.length() && j < b.length() + z2) {
                    char ch = j < b.length() ? b[j] : '0';
                    if (ch > a[i]) {
                        break;
                    } else if (ch < a[i]) {
                        c = false;
                        break;
                    }
                    i++; j++;
                }
                if (i == a.length() && j == b.length() + z2) {
                    cout<<"=\n";
                    continue;
                }
                else if (c) {
                    cout<<"<\n";
                    continue;
                } else {
                    cout<<">\n";
                    continue;
                }
            } else {
                cout<<">\n";
            }
        }
    }
}