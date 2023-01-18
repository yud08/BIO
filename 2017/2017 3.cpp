#include<bits/stdc++.h>
using namespace std;

void totalsums(int &parcelWeight, int &weightRange, int &totalNumber, vector<int> &parcels, int cs, int n, int cnumparcels) {
    if (parcelWeight < n || cnumparcels > totalNumber)
        return;
    if (parcelWeight == n) {
        parcels.push_back(cnumparcels);
        return;
    }
    for (int i = cs; i <= weightRange && n + i <= parcelWeight; i++) {
        int Cnum = n + i, cadd = 1;
        while (Cnum <= parcelWeight) {
            totalsums(parcelWeight, weightRange, totalNumber, parcels, i + 1, Cnum, cnumparcels + cadd); 
            Cnum += i; cadd++;
        }
    }
}

int NumSums(vector<vector<unsigned int>> &dp, vector<int> &parcels, int &numParcels, int &totalNumber, int csum, int cnumParcels) {
    //cout << csum << " " << cnumParcels << endl;
    if (cnumParcels > numParcels || csum > totalNumber) {
        return 0;
    }
    if (dp[cnumParcels][csum] == -1) {
        unsigned int cumusum = 0;
        for (int n : parcels) {
            cumusum += NumSums(dp, parcels, numParcels, totalNumber, csum + n, cnumParcels + 1);
        }
        dp[cnumParcels][csum] = cumusum;
    } 
    return dp[cnumParcels][csum];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numParcels, weightRange, totalNumber, parcelWeight;
    cin >> numParcels;
    cin >> weightRange;
    cin >> totalNumber;
    cin >> parcelWeight; 
    vector<int> parcels;
    totalsums(parcelWeight, weightRange, totalNumber, parcels, 1, 0, 0);
    unsigned int total = 0;
    sort(parcels.begin(), parcels.end());
    // for (int n : parcels) {
    //     cout << n << " ";
    // }
    // cout << '\n';
    vector<vector<unsigned int>> dp(numParcels + 1, vector<unsigned int>(totalNumber + 1, -1));
    dp[numParcels][totalNumber] = 1;
    cout << NumSums(dp, parcels, numParcels, totalNumber, 0, 0) << '\n';
    return 0;
}