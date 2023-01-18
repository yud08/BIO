#include <bits/stdc++.h>
using namespace std;

void convert(vector<string> &rules, string &s, string curr, int pos) {
    if (s.size() > 12)
        return;
    if (pos == s.size()) {
        rules.push_back(curr);
        return;
    }
    char a = s[pos];
    if (a == 'x' || a == 'u' || a == 'd') {
        if (s[pos + 1] == '?') {
            convert(rules, s, curr, pos + 2);
            convert(rules, s, curr + a, pos + 2);
        } else if (s[pos + 1] == '*') {
            convert(rules, s, curr, pos + 2);
            string pass = curr;
            while (pass.size() < 12) {
                pass += a;
                convert(rules, s, pass, pos + 2);
            }
        } else
            convert(rules, s, curr + a, pos + 1);
    } else {
        assert(a == '(');
        string parse = "";
        int i = pos + 1;
        for (; s[i] != ')'; i++) 
            parse += s[i];    
        if (s[++i] == '?') {
            convert(rules, s, curr, i + 1);
            convert(rules, s, curr + parse, i + 1);
        } else {
            assert(s[i] == '*');
            convert(rules, s, curr, i + 1);
            string tmp = curr;
            while (tmp.size() + parse.size() <= 12) {
                tmp += parse;
                convert(rules, s, tmp, i + 1);
            }
        }
    }
}

bool match(vector<string> &rules, string s) {
    for (string rule : rules) {
        if (rule.size() == s.size()) {
            bool possible = true;
            for (int i = 0; i < s.size(); i++) {
                if (rule[i] == 'u') {
                    if (s[i - 1] >= s[i]) {
                        possible = false;
                        break;
                    }
                } else if (rule[i] == 'd') {
                    if (s[i - 1] <= s[i]) {
                        possible = false;
                        break;
                    }
                }
            }
            if (possible)
                return true;
        }
    }
    return false;
}

int main() {
	string rule;
	cin >> rule;
	string a, b;
	cin >> a;
	cin >> b;
	vector<string> rules;
	convert(rules, rule, "", 0);
    if (match(rules, a)) 
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
    if (match(rules, b)) 
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
	return 0;
}