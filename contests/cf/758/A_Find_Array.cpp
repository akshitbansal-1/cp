/*
    Written by: akshitforever
*/

#include<iostream>
#include<vector>
using namespace std;
#define int long long int
int n = 1e5;
vector<bool> prime(n + 1, true);
void SieveOfEratosthenes()
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    
    // memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
 
    // // Print all prime numbers
    // for (int p = 2; p <= n; p++)
    //     if (prime[p])
    //         cout << p << " ";
}
 
int32_t main() {
    SieveOfEratosthenes();

    int t;
    cin>>t;
    while (t--) {
        int n1, i = 2;
        cin>>n1;
        while (n1) {
            if (prime[i]) {
                cout<<i<<" ";
                n1--;
            }
            i++;
        }
        cout<<endl;
    }
}