#include<bits/stdc++.h>
using namespace std;

#define int long long

string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char A, B;
    cin >> A; cin >> B;
    int a = A & 31, b = B & 31;
    int n; 
    cin >> n;
    if (n == 1)
        cout << A << '\n';
    else if (n == 2)
        cout << B << '\n';
    else {
        for (int i = 0; i < n - 2; i++) {
            int tmp = b + a;
            a = b;
            b = tmp % 26;
            if (b == 0)
                b = 26;
        }
        cout << alpha[b - 1] << '\n';
    }
    return 0;
}