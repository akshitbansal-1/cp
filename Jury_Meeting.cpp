#include <bits/stdc++.h>
using namespace std;
// #define int long long int
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define fora(v) for (auto &x : v)
#define p(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define ll long long
#define vi vector<int>
#define vl vector<long>
#define vll vector<ll>
#define pii pair<int, int>
#define umxy(x, y) unordered_map<x, y>
#define umii unordered_map<int, int>
#define mii map<int, int>
#define usi unordered_set<int>
#define usx(x) unordered_set<x>
#define sortbe(x) sort(x.begin(), x.end())
#define sortn(x, n) sort(x, x + n)
#define S second
#define F first
#define pb push_back
#define vin(v, n) fori(n) { int a; cin>>a; v.pb(a);}
long mod = 998244353;
unsigned long long power(unsigned long long x, int y, int p) {
    unsigned long long res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
int nm = 3e5 + 1;
vector<long long int> factos(nm, 1); 
vector<long long int> invFact(nm, 1); 
 
unsigned long long modInverse(unsigned long long n, int p){
    return power(n, p - 2, p);
}
 
void compute() {
	long long ans = 1;
	for (int i = 2; i < nm; i++) {
		factos[i] = (factos[i - 1] * i + mod) % mod;
		invFact[i] = modInverse(factos[i], mod) % mod;
	}
}
 
int count(vector<int> &v, int n) {
	int c = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] <= n) c++;
	}
	return c;
}
int32_t main() {
	compute();
	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		vector<int> v(n);
		for (int i=0;i<n;i++) {cin>>v[i];}
		sort(v.begin(),v.end());
		if (n == 1) {
			cout<<1<<endl;
			continue;
		}
		if (n >= 2) {
			if (v[n - 1] == v[n - 2]) { 
				cout<<factos[n]<<endl;
				continue;
			}
			if (v[n - 1] - v[n - 2] > 1) {
				cout<<"0\n";
				continue;
			}
		}
		int lesserThanMax = count(v, v[n - 1] - 2);
		long long int ans = (factos[n] - factos[n - 1] + mod) % mod;
		for (int i = 1; i <= lesserThanMax; i++) {
            int r = i;
			long long k = (((factos[lesserThanMax] + mod) % mod) * (invFact[lesserThanMax - r])) % mod;
			long long int prev = factos[n - i - 1];
			long long int totalDeduct = (k * prev + mod) % mod;
			ans = (ans - totalDeduct + mod) % mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}