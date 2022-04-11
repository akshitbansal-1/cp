#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<class Fun> class y_combinator_result {Fun fun_;public:template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }};template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef AKSHIT_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define all(x) (x).begin(), (x).end()
#define isEven(x) (x % 2 == 0)
#define int long long int


int lv(string str, int j) {
    int maxi = 0;
    int sum = 0;
    int n = str.length();
    // Traversing the string.
    for (int i = j; i < n; i++) {
 
        // If open bracket add 1 to sum.
        if (str[i] == '(')
            sum += 1;
 
        // If closed bracket subtract 1
        // from sum
        else
            sum -= 1;
 
        // if first bracket is closing bracket
        // then this condition would help
        if (sum < 0)
            break;
 
        // If sum is 0, store the index
        // value.
        if (sum == 0)
            maxi = i + 1;
    }
 
    return maxi;
}

bool isPalin(string &str, int l, int h) {
    map<char, char> mp;
    mp['('] = ')';
    mp[')'] =  '(';
    // for (int i = l; i<=h; i++) {
    //     cout<<mp[str[i]];
    // }
    // cout<<endl;
    while (l < h) {
        if (str[l] != str[h])
            return false;
        l++;
        h--;
    }
    return true;
}
int longestBracketsPalindrome(string &str, int j) {
    int n = str.length();
    int l = j, h = n - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (isPalin(str, j, m)) {
            if (l - j >= 2) break;
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return l - j;
}
int LongestPalindromicPrefix(string &s, int j)
{
    string str = s.substr(j);
	// Create temporary string
	string temp = str + '?';

	// Reverse the string str
	reverse(str.begin(), str.end());

	// Append string str to temp
	temp += str;

	// Find the length of string temp
	int n = temp.length();

	// lps[] array for string temp
	int lps[n];

	// Initialise every value with zero
	fill(lps, lps + n, 0);
    
	// Iterate the string temp
	for (int i = 1; i < n; i++) {

		// Length of longest prefix
		// till less than i
		int len = lps[i - 1];

		// Calculate length for i+1
		while (len > 0
			&& temp[len] != temp[i]) {
			len = lps[len - 1];
		}

		// If character at current index
		// len are same then increment
		// length by 1
		if (temp[i] == temp[len]) {
			len++;
		}
        // if (len > 2) return 2;
		// Update the length at current
		// index to len
        dbg(len);
		lps[i] = len;
	}
    for (int i = 0; i < n / 2; i++) {
        if (lps[i] == lps[i + n / 2] && lps[i] >= 2) return 2;
    }

    return lps[n - 1];
	// Print the palindromic string of
	// max_len
    // return lps[n - 1] - j;
	// cout << temp.substr(0, lps[n - 1]);
}

int l3(string &s, int j) {
    int n = s.length();
    for (int i = j + 1; i < n; i++) {
        int k = j, l = i;
        dbg(k, l);
        bool b = false;
        while (k <= l) {
            if (s[k] != s[l]){
                b = true;
                break;
            };
            k++;
            l--;
        }
        if (!b) return i - j + 1;
    }
    return 0;
}

void run_case() {
    int n;
    cin>>n;
    string str;
    int op = 0, i;
    cin>>str;
    for (i = 0; i < n;) {
        int longestValid = lv(str, i);
        int lpalin = l3(str, i);
        if (longestValid) {
            if (lpalin < 2) i += longestValid;
            else if (lpalin == 0) break;
            else i += min(lpalin, longestValid);
        } else if (lpalin) {
            if (lpalin < 2) break;
            else if (lpalin == 0) break;
            else i += lpalin;
        } else break;
        
        dbg(i, longestValid, lpalin);
        op++;
    }
    dbg();
    cout<<op<<" "<<max(0ll, n - i)<<endl;
    // dbg(longestValid);
}
int32_t main() {
    ios::sync_with_stdio(false);
#ifndef AKSHIT_DEBUG
    cin.tie(nullptr);
#endif
 
    int tests = 1;
    cin >> tests;
 
    while (tests--)
        run_case();

}