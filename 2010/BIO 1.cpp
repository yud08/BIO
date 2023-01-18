#include <bits/stdc++.h>
using namespace std;

vector<int> anagramNumber(int n) {
    vector<int> ans;
    string sn = to_string(n);
    sort(sn.begin(), sn.end());
    for (int i = 2 ; i <= 9; i++) {
        int pn = n * i;
        string cp = to_string(pn);
        sort(cp.begin(), cp.end());
        if (cp == sn)
            ans.push_back(i);
    }
    return ans;
}

vector<int> reverseAnagram(int n) {
    vector<int> ans;
    string sn = to_string(n);
    sort(sn.begin(), sn.end());
    for (int i = 2 ; i <= 9; i++) {
        if (n % i == 0) {
            string cp = to_string(n / i);
            sort(cp.begin(), cp.end());
            if (sn == cp)
                ans.push_back(n / i);
        }
    }
    return ans;
}

int main() {
/*    vector<int> generated = reverseAnagram(85247910);
    for (int gen : generated)
        cout << gen << endl;*/
/*    int numberofnums = 0;
    for (int i = 100000; i < 500000; i++) {
        vector<int> ans = anagramNumber(i);
        if (!ans.empty()) {
            string s = to_string(i);
            map<char, int> st;
            for (char a : s)
                st[a]++;
            bool duplicates = false;
            for (auto p : st) {
                if (p.second > 1) {
                    duplicates = true;
                    break;
                }
            }
            if (!duplicates)
                numberofnums++;
        }
    }
    cout << numberofnums << endl;*/
    cout << "Read in number(1 <= n <= 123456789): ";
    int N;
    cin >> N;
	vector<int> ans = anagramNumber(100);
	if (ans.empty()) {
	    cout << "NO" << endl;
	} else {
	    for (int nums : ans)
	        cout << nums << " ";
	    cout << endl;
	}
	return 0;
}
