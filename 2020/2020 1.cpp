#include<bits/stdc++.h>
using namespace std;

map<int, string> toRoman;

void lookAndSay(string &s) {
    string ans = "";
    char c = '0';
    int occur = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != c) {
            if (c != '0') {
                ans = ans + toRoman[occur];
                ans += c;
            }
            c = s[i];
            occur = 1;
        } else {
            occur++;
        }
    }
    ans += toRoman[occur];
    ans += c;
    s = ans;
}

int main() {
	string s;
	cin >> s;
	//cout << s << endl;
	int n;
	cin >> n;
	//cout << n << endl;
	toRoman[1] = "I";
	toRoman[2] = "II";
	toRoman[3] = "III";
	toRoman[4] = "IV";
	toRoman[5] = "V";
	for (int i = 0; i < n; i++) {
	    lookAndSay(s);
	}
	int nI = 0, nV = 0;
	for (char a : s) {
	    if (a == 'I')
	        nI++;
	    else if (a == 'V')
	        nV++;
	}
	cout << s << endl;
	cout << nI << " " << nV << '\n';
	return 0;
}
