#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> cards;
	for (int i = 0; i < 5; i++) {
	    int a;
	    cin >> a;
	    cards.push_back(a);
	}
	int score = 0;
	for (int j = 0; j < 4; j++) {
	    for (int z = j + 1; z < 5; z++) {
	        if (cards[j] == cards[z])
	            ++score;
	    }
	}
	for (int k = 0; k < 5; k++) {
	    if (cards[k] == 15)
	        ++score;
	}
	for (int p = 0; p < 4; p++) {
	    for (int q = p + 1; q < 5; q++) {
	        if (cards[p] + cards[q] == 15)
                ++score;
	    }
	}
	for (int b = 0; b < 3; b++) {
	    for (int c = b + 1; c < 4; c++) {
	        for (int d = c + 1; d < 5; d++) {
	            if (cards[b] + cards[c] + cards[d] == 15) {
	                ++score;
	            }
	        }
	    }
	}
	for (int e = 0; e < 2; e++) {
	    for (int f = e + 1; f < 3; f++) {
	        for (int g = f + 1; g < 4; g++) {
	            for (int h = g + 1; h < 5; h++) {
	                if (cards[e] + cards[f] + cards[g] + cards[h] == 15) {
	                    
	                }
	            }
	        }
	    }
	}
	if (cards[0] + cards[1] + cards[2] + cards[3] + cards[4] == 15) {
	    ++score;
	}
	cout << score << '\n';
	return 0;
}201057