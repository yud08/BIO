#include<bits/stdc++.h>
using namespace std;

map<char, int> convert;

void rewrite(string &s) {
    string ans = "";
    for (char a : s) {
        if (a == 'A') {
            ans += 'B';
        } else if (a == 'B') {
            ans += "AB";
        } else if (a == 'C') {
            ans += "CD";
        } else if (a == 'D') {
            ans += "DC";
        } else {
            ans += "EE";
        }
    }
    s = ans;
}

int count(vector<int> nums, int rewritingSteps) {
    for (int i = 0; i < rewritingSteps; i++) {
        int tmp = nums[0];
        nums[0] = nums[1];
        nums[1] += tmp;
        int tmp2 = nums[2];
        nums[2] += nums[3];
        nums[3] += tmp2;
        nums[4] *= 2;
    }
    return nums[0] + nums[1] + nums[2] + nums[3] + nums[4];
}

vector<int> summation(vector<int> nums, int rewritingSteps) {
    for (int i = 0; i < rewritingSteps; i++) {
        int tmp = nums[0];
        nums[0] = nums[1];
        nums[1] += tmp;
        int tmp2 = nums[2];
        nums[2] += nums[3];
        nums[3] += tmp2;
        nums[4] *= 2;
    }    
    return nums;
}

vector<int> recurse(int rewritingSteps, int position, string s) {
    //cout << rewritingSteps << " " << position << endl;
    //cout << s << endl;
    if (position == 0)
        return {0, 0, 0, 0, 0};
    if (rewritingSteps == 0) {
        vector<int> v = {0, 0, 0, 0, 0};
        v[convert[s[position]]]++;
        return v;
    }
    vector<int> v = {0, 0, 0, 0, 0};
    int sum = 0, it = -1;
    while (1) {
        it++;
        vector<int> give = {0, 0, 0, 0, 0};
        give[convert[s[it]]]++;
        sum += count(give, rewritingSteps);
        if (sum > position) {
            break;
        } else if (sum == position) {
            vector<int> ADD = summation(give, rewritingSteps);
            for (int j = 0; j < 5; j++) {
                v[j] += ADD[j];
            }
            break;
        } else {
            vector<int> ADD = summation(give, rewritingSteps);
            for (int j = 0; j < 5; j++) {
                v[j] += ADD[j];
            }
        }
    }
    string newS = "";
    for (int x = it; x < s.size(); x++) {
        newS += s[x];
    }
    s = newS;
    rewrite(s);
    //cout << position << " | " << sum << endl;
    vector<int> rest = recurse(rewritingSteps - 1, sum - position, s);
    //cout << "tf" << endl;
    for (int i = 0; i < 5; i++) {
        v[i] += rest[i];
    }
    return v;
}

int main() {
    string s;
	cin >> s;
	int rewritingSteps, position;
	cin >> rewritingSteps;
	cin >> position;
    convert['A'] = 0;
    convert['B'] = 1;
    convert['C'] = 2;
    convert['D'] = 3;
    convert['E'] = 4;
    vector<int> ans = recurse(rewritingSteps, position, s);
    //cout << "hre" << endl;
    for (int i = 0; i < 5; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
	return 0;
}