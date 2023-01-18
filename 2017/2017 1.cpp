#include<bits/stdc++.h>
using namespace std;

int main() {
	string row;
	cin >> row;
	while (row.size() > 1) {
	    string tmp = "";
	    for (int i = 0; i < row.size() - 1; i++) {
	        if (row[i] == row[i + 1]) {
	            tmp += row[i];
	        } else if ((row[i] == 'R' && row[i + 1] == 'G') || (row[i] == 'G' && row[i + 1] == 'R')) {
	            tmp += 'B';
	        } else if ((row[i] == 'R' && row[i + 1] == 'B') || (row[i] == 'B' && row[i + 1] == 'R')) {
	            tmp += 'G';
	        } else if ((row[i] == 'B' && row[i + 1] == 'G') || (row[i] == 'G' && row[i + 1] == 'B')) {
	            tmp += 'R';
	        } else
	            assert (1 == 2);
	    }
	    row = tmp;
	}
	cout << row[0] << '\n';
	return 0;
}
