#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	map<char, int> m1, m2;
	for (char a1 : s1)
	    m1[a1]++;
	for (char a2 : s2)
	    m2[a2]++;
	for (auto p1 : m1) {
	    if (m2.find(p1.first) == m2.end() || m2[p1.first] != p1.second) {
	        cout << "Not anagrams" << '\n';
	        return 0;        
	    }
	}
	for (auto p2 : m2) {
	    if (m1.find(p2.first) == m1.end() || m1[p2.first] != p2.second) {
	        cout << "Not anagrams" << '\n';
	        return 0;
	    }
	}
	cout << "Anagrams" << '\n';
	return 0;
}