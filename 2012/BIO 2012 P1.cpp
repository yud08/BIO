#include<bits/stdc++.h>
using namespace std;

vector<int> soe(int upTo) {
    vector<int> primes;
    vector<bool> isPrime(upTo + 1, true);
    for (int i = 2; i <= upTo; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            int iter = i;
            while (iter + i <= upTo) {
                iter += i;
                isPrime[iter] = false;
            }
        }
    }
    return primes;
}

int productOfDistinctPrimeFactors(int n, vector<int> &primes) {
   //for (int p : primes) {
    //    cout << p << " ";
    //}
    //cout << '\n';
    int ans = 1;
    for (int Prime : primes) {
        if (Prime * Prime > n)
            break;
        if (n % Prime == 0) {
            ans *= Prime;
            while (n % Prime == 0) 
                n /= Prime;
        }
    }
    if (n != 1)
        ans *= n;
    return ans;
}

int main() {
    vector<int> primes = soe(1e6);
    cout << primes.size() << endl;
/*    map<int, int> freq; 
    for (int i = 2; i < 1000000; i++) {
        freq[productOfDistinctPrimeFactors(i, primes)]++;
        if (productOfDistinctPrimeFactors(i, primes) == 10) {
            cout << i << ' ';
        }
    }
    cout << '\n';*/
/*    int maxn = -1, occursTheMost = -1;
    for (auto p : freq) {
        if (p.second > maxn) {
            maxn = p.second;
            occursTheMost = p.first;
        }
    }*/
    //cout << occursTheMost << " " << maxn << '\n';
	int n;
	cin >> n;
	cout << productOfDistinctPrimeFactors(n, primes) << '\n';
	return 0;
}
