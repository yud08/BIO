#include <bits/stdc++.h>
using namespace std;

#define int long long

int dp[201][9];

int create(int n, int d) {
    if (d == 0 && n != 0)
        return 0;
    if (dp[n][d] == -1) {
        int sum = 0;
        for (int i = 1; i <= 20 && n - i >= 0; i++) {
            sum += create(n - i, d - 1);
        }
        dp[n][d] = sum;
    }
    return dp[n][d];
}

int32_t main() {
    memset(dp, -1, sizeof dp);
    dp[0][0] = 1;
    int s, d;
    cin >> s;
    cin >> d;
    int sum = 0;
    for (int i = 1; i <= 20 && s - (2 * i) >= 0; i++) {
        sum += create(s - (2 * i), d - 1);
    }
    cout << sum << '\n';
	return 0;
}
