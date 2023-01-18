#include <bits/stdc++.h>
using namespace std;

struct dice {
    int topbottom[2];
    int leftright[2];
    int frontback[2];
    dice(int top, int bottom, int left, int right, int front, int back) {
        topbottom[0] = top; topbottom[1] = bottom;
        leftright[0] = left; leftright[1] = right;
        frontback[0] = front; frontback[1] = back;
    }
    void forwards() {
        int tmp1 = topbottom[0];
        topbottom[0] = frontback[1];
        int tmp2 = frontback[0];
        frontback[0] = tmp1;
        int tmp3 = topbottom[1];
        topbottom[1] = tmp2;
        frontback[1] = tmp3;
    }
    void backwards() {
        int tmp1 = topbottom[0];
        topbottom[0] = frontback[0];
        int tmp2 = frontback[1];
        frontback[1] = tmp1;
        int tmp3 = topbottom[1];
        topbottom[1] = tmp2;
        frontback[0] = tmp3;
    }
    void leftwards() {
        int tmp1 = topbottom[0];
        topbottom[0] = leftright[1];
        int tmp2 = leftright[0];
        leftright[0] = tmp1;
        int tmp3 = topbottom[1];
        topbottom[1] = tmp2;
        leftright[1] = tmp3;
    }
    void rightwards() {
        int tmp1 = topbottom[0];
        topbottom[0] = leftright[0];
        int tmp2 = leftright[1];
        leftright[1] = tmp1;
        int tmp3 = topbottom[1];
        topbottom[1] = tmp2;
        leftright[0] = tmp3;
    }
};

void move(vector<vector<int>> &board, int &y, int &x, int &heading, dice &Die) {
    int sum = (board[y][x] + Die.topbottom[0]);
    //cout << board[y][x] << " -> ";
    if (sum > 6)
        sum -= 6;
    board[y][x] = sum;
    //cout << board[y][x] << endl;
    if (sum == 2) {
        heading = (heading + 1) % 4;
    } else if (sum == 5) {
        if (heading == 0)
            heading = 3;
        else
            heading -= 1;
    } else if (sum == 3 || sum == 4) {
        if (heading == 1)
            heading = 3;
        else 
            heading = abs(heading - 2);
    }
    if (heading == 0) {
        Die.forwards();
        y--;
    } else if (heading == 1) {
        Die.rightwards();
        x++;
    } else if (heading == 2) {
        Die.backwards();
        y++;
    } else {
        Die.leftwards();
        x--;
    }
}

void print(vector<vector<int>> &board, int y, int x) {
    for (int i = -1; i < 2; i++) {
    	for (int j = -1; j < 2; j++) {
            if (y + i < 0 || y + i >= 11 || x + j < 0 || x + j >= 11)
                cout << "X";
            else
                cout << board[y + i][x + j];
    	}
    	cout << endl;
    }
    cout << endl;
}

int main() {
	dice Die(1, 6, 3, 4, 2, 5);
	vector<vector<int>> board(11, vector<int>(11, 1));
    for (int g1 = 0; g1 < 3; g1++) {
    	for (int g2 = 0; g2 < 3; g2++) {
    	   int a;
    	   cin >> a;
    	   board[4 + g1][4 + g2] = a;
    	}
    }
    int y = 5, x = 5, heading = 0;
	while (1) {
	    int n;
	    cin >> n;
	    if (n == 0)
	        break;
	    if (n > 0) {
	        for (int i = 0; i < n; i++) {
	            //cout << "points " << heading << endl;
	            assert(x >= 0 && x < 11);
	            assert(y >= 0 && y < 11);
	            move(board, y, x, heading, Die);
	        }
	        print(board, y, x);
	    }
	}
	return 0;
}
