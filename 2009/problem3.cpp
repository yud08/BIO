#include<bits/stdc++.h>
using namespace std;

#define int long long

int dp[33];

int findN(int n) {
    if (dp[n] == -1) {
        int tmp = 0;
        for (int i = 1; i <= n && i <= 9; i++) 
            tmp += findN(n - i);
        dp[n] = tmp;
    }
    return dp[n];
}

void findNth(int n, int s) {
    if (n == 0) {
        cout << '\n';
        return;
    }
    int counter = 0;
    int addsum = 0;
    while (addsum <= s) {
        ++addsum;
        int tmp = counter;
        counter += findN(s - addsum);
        if (counter >= n) {
            cout << addsum << ' ';
            findNth(n - tmp, s - addsum);
            break;
        }
    }
    
}

int32_t main() {
	memset(dp, -1, sizeof(dp));
	dp[1] = 1; dp[0] = 1;
	int s, n;
	cin >> s; cin >> n;
	findNth(n, s);
	return 0;
}