#include <bits/stdc++.h>
using namespace std;

string alpha = "abcdefghijklmnopqrstuvwxyz";
int num_arrange = 1;
vector<vector<char>> slots;

void create(int n, int pos) {
    if (n == 0) {
        cout << '\n';
        return;
    }
    int sum = 0;
    int sizeN = slots[pos].size();
    for (int i = 0; i < sizeN; i++) {
        if (sum + (num_arrange / sizeN) >= n) {
            num_arrange /= sizeN;
            cout << slots[pos][i] << ' ';
            create(n - sum, pos + 1);
            return;
        } else
            sum += (num_arrange / sizeN);
    }
}

int main() {
    
    string arrangement;
	cin >> arrangement;
	int n;
	cin >> n;
	int numcars = arrangement.size();
	string parking(numcars, '0');
	for (int i = 0; i < numcars; i++) {
	    int ind = -1, count = 0;
	    for (int x = 0; x < numcars; x++) {
	        if (arrangement[x] == alpha[i]) {
	            ind = x;
	            break;
	        }
	    }
	    //cout << ind << endl;
	    parking[ind] = alpha[i];
	    vector<char> v;
	    for (int y = ind; y >= 0; y--) {
	        if (parking[y] != '0') {
	            v.push_back(toupper(alpha[y]));
	            count++;
	        } else
	            break;
	    }
	    reverse(v.begin(), v.end());
	    slots.push_back(v);
	    num_arrange *= count;
	}
	create(n, 0);
	return 0;
}
