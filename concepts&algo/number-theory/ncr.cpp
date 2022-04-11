#include<vector>
using namespace std;
// if m is prime and difference between 
// n > 5000
int MAXN = 5000;
vector<vector<int>> C(MAXN, vector<int>(MAXN));
void precom(int m) {
    for (int i = 1; i <= MAXN; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%m;
        }
    }
}
int ncr(int n, int r, int m) {
    return C[n][r];
}

//n implementation
int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}