#include<bits/stdc++.h>

using namespace std;
vector<int> v;
bool is(int a) {
    for (int i = 2; i * i <= a; i++) if (a % i == 0) return true;
    return false;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        v.assign(n, 0);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin>>v[i];
            sum += v[i];
        }


        if (is(sum)) {
            cout<<n<<endl;
            for (int i = 0; i < n; i++) cout<<i + 1<<" ";
            cout<<endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (is(sum - v[i])) {
                cout<<n - 1<<endl;
                for (int j = 0; j < n; j++) if (i != j) cout<<j + 1<<" ";
                cout<<endl;
                break;
            }
        }

    }




}