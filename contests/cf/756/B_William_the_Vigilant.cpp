/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    string s, s1;
    cin>>s;
    s1 = s;
    int c = 0;
    // vector<int> v(n + 1, 0);
    for (int i = 0; i < n - 2; i++) {
        if (s.substr(i, 3) == "abc") {
            i += 2;
            c++;
        }
    }
    while (m--) {
        int a;
        cin>>a;
        char ch;
        cin>>ch;
        a--;
        int i = a;
        if (ch != s[a]) {
            if (s[a] == 'c' && a - 2 >= 0  && s[a - 1] == 'b' && s[a - 2] == 'a') {
                c--;
            }
            else if (s[a] == 'b' && a - 1 >= 0 && a + 1 < n && s[a - 1] == 'a' && s[a + 1] == 'c') {
                c--;
            }
            else if (s[a] == 'a' && a + 2 < n && s[a + 1] == 'b' && s[a + 2] == 'c') {
                c--;
            }
            s[a] = ch;
            if (s[a] == 'c' && a - 2 >= 0  && s[a - 1] == 'b' && s[a - 2] == 'a') {
                c++;
            }
            else if (s[a] == 'b' && a - 1 >= 0 && a + 1 < n && s[a - 1] == 'a' && s[a + 1] == 'c') {
                c++;
            }
            else if (s[a] == 'a' && a + 2 < n && s[a + 1] == 'b' && s[a + 2] == 'c') {
                c++;
            }
        }

        cout<<c<<endl;
    }


}