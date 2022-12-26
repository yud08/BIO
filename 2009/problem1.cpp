#include<bits/stdc++.h>
using namespace std;

vector<string> numbers = {"NULL", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main() {
    string S;
    cin >> S;
	for (int i = 1; i < 10; i++) {
	    int it = 0;
	    for (char a : S) {
	        if (a == numbers[i][it]) 
	            ++it;
	        if (it == numbers[i].size()) {
	            cout << i << '\n';
	            return 0;   
	        }
	    }
	}
	cout << "NO" << '\n';
	return 0;
}