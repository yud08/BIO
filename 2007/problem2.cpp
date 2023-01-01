#include<bits/stdc++.h>
using namespace std;

//O = P1
//X = P2

string layout;

int loop(int n) {
    if (n == 0)
        return 8;
    if (n == 9)
        return 1;
    return n;
}

bool canMoveP1() {
    if (layout[0] == 'O') {
        for (int j = 1; j < 9; j++) {
            if (layout[j] == 'E') {
                return true;
            }
        }    
    } 
    for (int i = 1; i < 9; i++) {
        if (layout[i] == 'O') {
            if (layout[0] == 'E' && (layout[loop(i - 1)] != 'O' || layout[loop(i + 1)] != 'O')) {
                return true;
            }
            if (layout[loop(i - 1)] == 'E' || layout[loop(i + 1)] == 'E') {
                return true;
            }
        }
    }
    return false;
}

bool canMoveP2() {
    if (layout[0] == 'X') {
        for (int j = 1; j < 9; j++) {
            if (layout[j] == 'E') {
                return true;
            }
        }    
    } 
    for (int i = 1; i < 9; i++) {
        if (layout[i] == 'X') {
            if (layout[0] == 'E' && (layout[loop(i - 1)] != 'X' || layout[loop(i + 1)] != 'X')) {
                return true;
            }
            if (layout[loop(i - 1)] == 'E' || layout[loop(i + 1)] == 'E') {
                return true;
            }
        }
    }
    return false;
}

bool canWinP1(bool update) {
    if (layout[0] == 'O') {
        for (int j = 1; j < 9; j++) {
            if (layout[j] == 'E') {
                layout[0] = 'E'; layout[j] = 'O';
                if (!canMoveP2()) {
                    if (update) {
                        cout << layout << '\n';
                        cout << "Player 1 wins" << '\n';
                    } else
                        layout[0] = 'O'; layout[j] = 'E'; 
                    return true;
                }
                layout[0] = 'O'; layout[j] = 'E'; 
            }
        }    
    } 
    for (int i = 1; i < 9; i++) {
        if (layout[i] == 'O') {
            if (layout[0] == 'E' && (layout[loop(i - 1)] != 'O' || layout[loop(i + 1)] != 'O')) {
                layout[0] = 'O'; layout[i] = 'E'; 
                if (!canMoveP2()) {
                    if (update) {
                        cout << layout << '\n';
                        cout << "Player 1 wins" << '\n';
                    } else
                        layout[0] = 'E'; layout[i] = 'O';
                    return true;
                }
                layout[0] = 'E'; layout[i] = 'O';
            }
            if (layout[loop(i - 1)] == 'E') {
                layout[loop(i - 1)] = 'O'; layout[i] = 'E';
                if (!canMoveP2()) {
                    if (update) {
                        cout << layout << '\n';
                        cout << "Player 1 wins" << '\n';
                    } else
                        layout[loop(i - 1)] = 'E'; layout[i] = 'O';
                    return true;
                }
                layout[loop(i - 1)] = 'E'; layout[i] = 'O';
            }
            if (layout[loop(i + 1)] == 'E') {
                layout[loop(i + 1)] = 'O'; layout[i] = 'E';
                if (!canMoveP2()) {
                    if (update) {
                        cout << layout << '\n';
                        cout << "Player 1 wins" << '\n';
                    } else
                        layout[loop(i + 1)] = 'E'; layout[i] = 'O';
                    return true;
                }
                layout[loop(i + 1)] = 'E'; layout[i] = 'O';
            }
        }
    }
    return false;
}

bool canWinP2(bool update) {
    if (layout[0] == 'X') {
        for (int j = 1; j < 9; j++) {
            if (layout[j] == 'E') {
                layout[0] = 'E'; layout[j] = 'X';
                if (!canMoveP1()) {
                    if (update) {
                        cout << layout << '\n';
                        cout << "Player 2 wins" << '\n';
                    } else
                        layout[0] = 'X'; layout[j] = 'E'; 
                    return true;
                }
                layout[0] = 'X'; layout[j] = 'E'; 
            }
        }    
    } 
    for (int i = 1; i < 9; i++) {
        if (layout[i] == 'X') {
            if (layout[0] == 'E' && (layout[loop(i - 1)] != 'X' || layout[loop(i + 1)] != 'X')) {
                layout[0] = 'X'; layout[i] = 'E'; 
                if (!canMoveP1()) {
                    if (update) {
                        cout << layout << '\n';
                        cout << "Player 2 wins" << '\n';
                    } else
                        layout[0] = 'E'; layout[i] = 'X';
                    return true;
                }
                layout[0] = 'E'; layout[i] = 'X';
            }
            if (layout[loop(i - 1)] == 'E') {
                layout[loop(i - 1)] = 'X'; layout[i] = 'E';
                if (!canMoveP1()) {
                    if (update) {
                        cout << layout << '\n';
                        cout << "Player 2 wins" << '\n';
                    } else
                        layout[loop(i - 1)] = 'E'; layout[i] = 'X';
                    return true;
                }
                layout[loop(i - 1)] = 'E'; layout[i] = 'X';
            }
            if (layout[loop(i + 1)] == 'E') {
                layout[loop(i + 1)] = 'X'; layout[i] = 'E';
                if (!canMoveP1()) {
                    if (update) {
                        cout << layout << '\n';
                        cout << "Player 2 wins" << '\n';
                    } else
                        layout[loop(i + 1)] = 'E'; layout[i] = 'X';
                    return true;
                }
                layout[loop(i + 1)] = 'E'; layout[i] = 'X';
            }
        }
    }
    return false;
}

bool moveP1() {
    //cout << "move1" << endl;
    if (canWinP1(true)) {
        return true;
    }
    if (layout[0] == 'O') {
        for (int j = 1; j < 9; j++) {
            if (layout[j] == 'E') {
                layout[j] = 'O'; layout[0] = 'E';
                if (canWinP2(false)) {
                    layout[j] = 'E'; layout[0] = 'O'; 
                } else
                    return false;
            }
        }
    }
    for (int i = 1; i < 9; i++) {
        if (layout[i] == 'O') {
            if (layout[0] == 'E' && (layout[loop(i - 1)] != 'O' || layout[loop(i + 1)] != 'O')) {
                layout[0] = 'O'; layout[i] = 'E'; 
                if (canWinP2(false)) {
                    layout[0] = 'E'; layout[i] = 'O'; 
                } else
                    return false;
            }
            if (layout[loop(i - 1)] == 'E') {
                layout[loop(i - 1)] = 'O'; layout[i] = 'E';
                if (canWinP2(false)) {
                    layout[loop(i - 1)] = 'E'; layout[i] = 'O'; 
                } else
                    return false;
            }
            if (layout[loop(i + 1)] == 'E') {
                layout[loop(i + 1)] = 'O'; layout[i] = 'E';
                if (canWinP2(false)) {
                    layout[loop(i + 1)] = 'E'; layout[i] = 'O'; 
                } else
                    return false;
            }
        }
    }
    if (layout[0] == 'O') {
        for (int x = 1; x < 9; x++) {
            if (layout[x] == 'E') {
                layout[x] = 'O'; layout[0] = 'E';
                canWinP2(true);
                cout << layout << '\n';
                cout << "Player 2 wins" << '\n';
                return true;
            }
        }
    }
    for (int y = 1; y < 9; y++) {
        if (layout[y] == 'O') {
            if (layout[0] == 'E' && (layout[loop(y - 1)] != 'O' || layout[loop(y + 1)] != 'O')) {
                layout[0] = 'O'; layout[y] = 'E';
                canWinP2(true);
                return true;
            }
            if (layout[loop(y - 1)] == 'E') {
                layout[loop(y - 1)] = 'O'; layout[y] = 'E';
                canWinP2(true);
                return true;
            }
            if (layout[loop(y + 1)] == 'E') {
                layout[loop(y + 1)] = 'O'; layout[y] = 'E';
                canWinP2(true);
                return true;                
            }
        }
    }
    // assert(2 + 1 != 3);
    return false;
}

bool moveP2() {
    //cout << "move2" << endl;
    if (canWinP2(true)) {
        return true;
    }
    if (layout[0] == 'X') {
        for (int j = 1; j < 9; j++) {
            if (layout[j] == 'E') {
                layout[j] = 'X'; layout[0] = 'E';
                if (canWinP1(false)) {
                    layout[j] = 'E'; layout[0] = 'X'; 
                } else
                    return false;
            }
        }
    }
    for (int i = 1; i < 9; i++) {
        if (layout[i] == 'X') {
            if (layout[0] == 'E' && (layout[loop(i - 1)] != 'X' || layout[loop(i + 1)] != 'X')) {
                layout[0] = 'X'; layout[i] = 'E'; 
                if (canWinP1(false)) {
                    layout[0] = 'E'; layout[i] = 'X'; 
                } else
                    return false;
            }
            if (layout[loop(i - 1)] == 'E') {
                layout[loop(i - 1)] = 'X'; layout[i] = 'E';
                if (canWinP1(false)) {
                    layout[loop(i - 1)] = 'E'; layout[i] = 'X'; 
                } else
                    return false;
            }
            if (layout[loop(i + 1)] == 'E') {
                layout[loop(i + 1)] = 'X'; layout[i] = 'E';
                if (canWinP1(false)) {
                    layout[loop(i + 1)] = 'E'; layout[i] = 'X'; 
                } else
                    return false;
            }
        }
    }
    if (layout[0] == 'X') {
        for (int x = 1; x < 9; x++) {
            if (layout[x] == 'E') {
                layout[x] = 'X'; layout[0] = 'E';
                canWinP1(true);
                cout << layout << '\n';
                cout << "Player 1 wins" << '\n';
                return true;
            }
        }
    }
    for (int y = 1; y < 9; y++) {
        if (layout[y] == 'X') {
            if (layout[0] == 'E' && (layout[loop(y - 1)] != 'X' || layout[loop(y + 1)] != 'X')) {
                layout[0] = 'X'; layout[y] = 'E';
                canWinP1(true);
                return true;
            }
            if (layout[loop(y - 1)] == 'E') {
                layout[loop(y - 1)] = 'X'; layout[y] = 'E';
                canWinP1(true);
                return true;
            }
            if (layout[loop(y + 1)] == 'E') {
                layout[loop(y + 1)] = 'X'; layout[y] = 'E';
                canWinP1(true);
                return true;                
            }
        }
    }
    assert(2 + 1 != 3);
    return false;
}

int main() {
	cin >> layout;
	int isP1 = true;
	while (1) {
	    char a;
	    cin >> a;
	    if (a == 'n') {
	        if (isP1) {
    	        if (!moveP1()) {
    	            cout << layout << '\n';
    	            isP1 = false;
    	        } else
    	            return 0;
	        } else {
	            if (!moveP2()) {
	                cout << layout << '\n';
	                isP1 = true;
	            } else
	                return 0;
	        }
	    } else if (a == 'r') {
	        for (int i = 0; i < 1e4; i++) {
    	        if (isP1) {
        	        if (!moveP1()) {
        	            //cout << layout << '\n';
        	            isP1 = false;
        	        } else {
        	            //cout << layout << '\n';
        	            return 0;
        	        }
    	        } else {
    	            if (!moveP2()) {
    	                //cout << layout << '\n';
    	                isP1 = true;
    	            } else {
    	                //cout << layout << '\n';
    	                return 0;
    	            }
    	        }
	        }
	        //cout << layout << '\n';
	        cout << "Draw" << '\n';
	    }
	}
	return 0;
}