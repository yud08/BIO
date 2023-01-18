#include<bits/stdc++.h>
using namespace std;

int p, i, n, w;

void create(int pW, int cnum, int use, vector<int> &parcelWeights) {
    if (pW == 0) {
        parcelWeights.push_back(cnum);
        return;
    }
    if (use > i)
        return;
    while (pW >= 0) {
        create(pW, cnum, use + 1, parcelWeights);
        pW -= use;
        cnum++;
    }
}

int dp[6][26];

int createDP(int nP, int tI, vector<int> &parcelWeights) {
    if (nP < 0 || tI < 0)
        return 0;
    if (dp[nP][tI] == -1) {
        int sum = 0;
        int curr = -1, val = 0;
        for (int i = 0; i < parcelWeights.size(); i++) {
            if (curr != parcelWeights[i]) 
                val = createDP(nP - 1, tI - parcelWeights[i], parcelWeights);
            sum += val;
        }
        dp[nP][tI] = sum;
    }
    return dp[nP][tI];
} 

//get all the possible numbers of items contained in one parcel(including duplicates) and then dp

int main() {
	cin >> p; //number of parcels
	cin >> i; //range of weights
	cin >> n; //total items in all parcels
	cin >> w; //weight of each parcel
	map<vector<int>, bool> present;
    vector<int> parcelWeights;	
    create(w, 0, 1, parcelWeights);
    sort(parcelWeights.begin(), parcelWeights.end());
    memset(dp, -1, sizeof dp);
    dp[0][0] = 1;
    cout << createDP(p, n, parcelWeights) << '\n';
	return 0;
}
