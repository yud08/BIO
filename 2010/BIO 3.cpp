#include <bits/stdc++.h>
using namespace std;

bool equals(vector<int> &jugs, int n) {
    for (int j : jugs) {
        if (j == n)
            return true;
    }
    return false;
}

int main() {
	int j, n;
	cin >> j;
	cin >> n;
	vector<int> jugs;
	for (int i = 0; i < j; i++) {
	    int a;
	    cin >> a;
	    jugs.push_back(a);
	}
	sort(jugs.begin(), jugs.end());
	if (j == 1) {
	    cout << "1" << endl;
	} else if (j == 2) {
	    vector<int> costs(jugs.back() + 1, -1);
        costs[jugs[0]] = 2; 
        int cpos1 = jugs[0], co1 = 2;
        while (1) {
            cpos1 += jugs[0]; co1 += 2;
            if (cpos1 > jugs[1]) 
                cpos1 -= jugs[1];
            if (cpos1 == jugs[1])
                break;
            costs[cpos1] = co1;
        }
        costs[jugs[1]] = 2; 
        int cpos2 = jugs[1], co2 = 2;
        while (1) {
            cpos2 -= jugs[0]; co2 += 2;
            if (cpos2 <= 0) 
                cpos2 += jugs[1];
            if (cpos2 == jugs[0])
                break;
            costs[cpos2] = min(co2, costs[cpos2]);
        }
        if (n <= jugs[0] || n == jugs[1])
            cout << costs[n] - 1 << endl;
        else
            cout << costs[n] << endl;
	} else {
	    cout << "Not finished" << endl;
	}
	return 0;
}
