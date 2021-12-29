/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> v(n);
        int m = 0, mi = 0;
        for (int i = 0; i <  n; i++) {
            cin>>v[i];
            if (v[i] > m) {
                m = v[i];
                mi = i;
            }
        }
        if (n == 1) {
            cout<<v[0]<<endl;
            continue;
        } else if (n == 2) {
            cout<<v[0]<<" "<<v[1]<<endl;
            continue;
        }
        if (mi != n - 1 && mi != 0) {
            cout<<-1<<endl;
            continue;
        }
        deque<int> q;
        q.push_back(m);
        int i = 0, j = n - 1;
        if (mi == i) i++;
        else j--;
        for (; i <= j; ) {
            if (v[i] < v[j]) {
                q.push_front(v[i++]);
            } else {
                q.push_back(v[j--]);
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop_front();
            cout<<x<<" ";
        }
        cout<<endl;
    }
}