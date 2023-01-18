#include <bits/stdc++.h>
using namespace std;

char board[5][5];

inline bool outside(int y, int x) { return (y < 0 || y >= 5 || x < 0 || x >= 5); }

pair<int, int> move(int type, int y, int x) {
    if (type == 1) {
        while (!outside(y - 1, x) && board[y - 1][x] == '.') 
            y--;
        return {y, x};
    } 
    if (type == 2) {
        while (!outside(y - 1, x + 1) && board[y - 1][x + 1] == '.') {
            y--; x++;
        }
        return {y, x};
    } 
    if (type == 3) {
        while (!outside(y, x + 1) && board[y][x + 1] == '.') 
            x++;
        return {y, x};
    } 
    if (type == 4) {
        while (!outside(y + 1, x + 1) && board[y + 1][x + 1] == '.') {
            y++; x++;
        }
        return {y, x};
    } 
    if (type == 5) {
        while (!outside(y + 1, x) && board[y + 1][x] == '.') 
            y++; 
        return {y, x};
    } 
    if (type == 6) {
        while (!outside(y + 1, x - 1) && board[y + 1][x - 1] == '.') {
            y++; x--;
        }
        return {y, x};
    } 
    if (type == 7) {
        while (!outside(y, x - 1) && board[y][x - 1] == '.') 
            x--;
        return {y, x};
    } 
    if (type == 8) {
        while (!outside(y - 1, x - 1) && board[y - 1][x - 1] == '.') {
            y--; x--;
        }
        return {y, x};
    }
}

bool blocked(int y, int x) {
    if (!outside(y - 1, x) && board[y - 1][x] == '.') 
        return false;
    if (!outside(y - 1, x + 1) && board[y - 1][x + 1] == '.') 
        return false;
    if (!outside(y, x + 1) && board[y][x + 1] == '.') 
        return false;
    if (!outside(y + 1, x + 1) && board[y + 1][x + 1] == '.') 
        return false;
    if (!outside(y + 1, x) && board[y + 1][x] == '.') 
        return false;
    if (!outside(y + 1, x - 1) && board[y + 1][x - 1] == '.') 
        return false;
    if (!outside(y, x - 1) && board[y][x - 1] == '.') 
        return false;
    if (!outside(y - 1, x - 1) && board[y - 1][x - 1] == '.')
        return false;
    return true;
}

void printboard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    } 
    cout << '\n';
}

int main() {
	vector<int> p1order, p2order;
	for (int it1 = 0; it1 < 5; it1++) {
	    int t1;
	    cin >> t1;
	    p1order.push_back(t1);
	}
	for (int it2 = 0; it2 < 5; it2++) {
	    int t2;
	    cin >> t2;
	    p2order.push_back(t2);
	}
	for (int fd = 0; fd < 5; fd++) {
	    for (int fg = 0; fg < 5; fg++) {
	        board[fd][fg] = '.';
	    }
	}
	vector<pair<int, int>> p1pieces = {{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}};
	board[4][0] = 'F'; board[4][1] = 'F'; board[4][2] = 'F'; board[4][3] = 'F'; board[4][4] = 'F';
	vector<pair<int, int>> p2pieces = {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}};
	board[0][0] = 'S'; board[0][1] = 'S'; board[0][2] = 'S'; board[0][3] = 'S'; board[0][4] = 'S';
	int ny = 2, nx = 2;
	board[ny][nx] = '*';
	int first = true;
	int currpiece1 = 0, currpiece2 = 0;
	bool firstprint1 = false, firstprint2 = false;
	while (1) {
	    //cout << "ello" << endl;
	    if (first) {
	        //cout << "one" << endl;
	        bool win = false;
	        int pieceY = p1pieces[currpiece1].first;
	        int pieceX = p1pieces[currpiece1].second;
            for (int i = 1; i <= 8; i++) {
                pair<int, int> tmp = move(i, ny, nx);
                if (tmp.first == 4) {
                    board[ny][nx] = '.';
                    board[tmp.first][tmp.second] = '*';
                    win = true;
                    break;
                }
            }
            if (win) {
                break;
            }
            bool moved = false;
            for (int j = 1; j <= 8; j++) {
                pair<int, int> pos = move(j, ny, nx);
                if ((pos.first != ny || pos.second != nx) && pos.first != 0) {
                    board[pos.first][pos.second] = '*';
                    if (blocked(pieceY, pieceX)) {
                        //cout << "WTF" << endl;
                        board[pos.first][pos.second] = '.';
                    } else {
                        moved = true;
                        board[ny][nx] = '.';
                        ny = pos.first;
                        nx = pos.second;
                        break;
                    }
                }
            }
            bool final = false;
            if (!moved) {
                for (int z = 1; z <= 8; z++) {
                    pair<int, int> sus = move(z, ny, nx);
                    if (sus.first != ny || sus.first != nx) {
                        board[sus.first][sus.second] = '*';
                        if (blocked(pieceY, pieceX)) {
                            board[sus.first][sus.second] = '.';
                        } else {
                            final = true;
                            board[ny][nx] = '.';
                            ny = sus.first;
                            nx = sus.second;
                            break;
                        }
                    }
                }
                if (final)
                    break;
                assert(final != false);
            }
            bool movePiece = false;
            for (int c = 1; c <= 8; c++) {
                pair<int, int> temporal = move(c, pieceY, pieceX);
                if (temporal.first != pieceY || temporal.second != pieceX) {
                    movePiece = true;
                    board[pieceY][pieceX] = '.';
                    board[temporal.first][temporal.second] = 'F';
                    pair<int, int> update = {temporal.first, temporal.second};
                    p1pieces[currpiece1] = update;
                    break;
                }
            }
            assert(movePiece == true);
            currpiece1 += 1;
            currpiece1 %= 5;
	        first = !first;
	        if (firstprint1 == false) {
	            firstprint1 = true;
	            printboard();
	        }
	    } else {
	        //cout << "two" << endl;
	        //cout << ny << " " << nx << endl;
	        bool win = false;
	        int pieceY = p2pieces[currpiece2].first;
	        int pieceX = p2pieces[currpiece2].second;
            for (int i = 1; i <= 8; i++) {
                //cout << i << " ";
                pair<int, int> tmp = move(i, ny, nx);
                //cout << tmp.first << " " << tmp.second << endl;
                if (tmp.first == 0) { 
                    board[ny][nx] = '.';
                    board[tmp.first][tmp.second] = '*';
                    win = true;
                    break;
                }
            }
            if (win) {
                break;
            }
            bool moved = false;
            for (int j = 1; j <= 8; j++) {
                pair<int, int> pos = move(j, ny, nx);
                //cout << j << " " << pos.first << " " << pos.second << endl;
                if ((pos.first != ny || pos.second != nx) && pos.first != 4) {
                    board[pos.first][pos.second] = '*';
                    if (blocked(pieceY, pieceX)) {
                        board[pos.first][pos.second] = '.';
                    } else {
                        moved = true;
                        board[ny][nx] = '.';
                        ny = pos.first;
                        nx = pos.second;
                        break;
                    }
                }
            }
            bool final = false;
            if (!moved) {
                for (int z = 1; z <= 8; z++) {
                    pair<int, int> sus = move(z, ny, nx);
                    if (sus.first != ny || sus.first != nx) {
                        board[sus.first][sus.second] = '*';
                        if (blocked(pieceY, pieceX)) {
                            board[sus.first][sus.second] = '.';
                        } else {
                            final = true;
                            board[ny][nx] = '.';
                            ny = sus.first;
                            nx = sus.second;
                            break;
                        }
                    }
                }
                if (final)
                    break;
                assert(final != false);
            }
            bool movePiece = false;
            for (int c = 1; c <= 8; c++) {
                pair<int, int> temporal = move(c, pieceY, pieceX);
                if (temporal.first != pieceY || temporal.second != pieceX) {
                    movePiece = true;
                    board[pieceY][pieceX] = '.';
                    board[temporal.first][temporal.second] = 'S'; 
                    pair<int, int> update = {temporal.first, temporal.second};
                    p2pieces[currpiece2] = update;
                    break;
                }
            }
            assert(movePiece == true);
            currpiece2 += 1;
            currpiece2 %= 5;
	        first = !first;
	        if (firstprint2 == false) {
	            firstprint2 = true;
	            printboard();
	        }
	    } 
	}
	printboard();
	return 0;
}
