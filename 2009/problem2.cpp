#include<bits/stdc++.h>
using namespace std;

bool isNumeric(string s) {
    for (int i = 0; i < s.size(); i++) {
        if ((s[i] >= '0' && s[i] <= '9') == false) 
            return false;
    }
    return true;
}

vector<vector<char>> startingBoard(4, vector<char>(4, '0'));
vector<vector<char>> board;
vector<queue<char>> overhead(4);
int score = 0;

void print() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

void refill() {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
            overhead[i].push(startingBoard[j][i]);
        }
    }
}

void dfs1(int y, int x, char find, vector<vector<bool>> &visited, int &amcells) {
    if (y >= 4 || y < 0 || x >= 4 || x < 0 || visited[y][x] || board[y][x] != find)
        return;
    visited[y][x] = true;
    ++amcells;
    dfs1(y + 1, x, find, visited, amcells);
    dfs1(y - 1, x, find, visited, amcells);
    dfs1(y, x + 1, find, visited, amcells);
    dfs1(y, x - 1, find, visited, amcells);
}

void dfs2(int y, int x, char find, int &amcells) {
    if (y >= 4 || y < 0 || x >= 4 || x < 0 || board[y][x] != find)
        return;
    ++amcells;
    board[y][x] = '0';
    dfs2(y + 1, x, find, amcells);
    dfs2(y - 1, x, find, amcells);
    dfs2(y, x + 1, find, amcells);
    dfs2(y, x - 1, find, amcells);
}

bool partOfSegment(int i, int j) {
    int inSegment = 0;
    vector<vector<bool>> visited(4, vector<bool>(4, false));
    dfs1(i, j, board[i][j], visited, inSegment);
    return inSegment >= 2;
}

void removeSegment(int i, int j, int &cscore) {
    int amcells = 0;
    dfs2(i, j, board[i][j], amcells);
    cscore *= amcells;
}

void moveBoardDown() {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {
            if (board[j][i] != '0') {
                char tmp = board[j][i];
                board[j][i] = '0';
                for (int x = 3; x >= 0; x--) {
                    if (board[x][i] == '0') {
                        board[x][i] = tmp;
                        break;
                    }
                }
            }
        }
    }
    for (int a = 0; a < 4; a++) {
        for (int b = 3; b >= 0; b--) {
            if (board[b][a] == '0') {
                board[b][a] = overhead[a].front();
                overhead[a].pop();
            }
        }
    }
}

bool move() {
    bool deleted = false;
    int cscore = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] != '0' && partOfSegment(i, j)) {
                if (cscore == 0) cscore = 1;
                removeSegment(i, j, cscore);
                deleted = true;
            }
        }
    }
    moveBoardDown();
    refill();
    //cout << "__________" << endl;
    //print();
    score += cscore;
    return deleted;
}

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char a;
            cin >> a;
            startingBoard[i][j] = a;
        }
    }
    board = startingBoard;
    refill();
    while (1) {
        string input;
        cin >> input;
        if (!isNumeric(input))
            continue;
        int n = stoi(input);
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            if (move() == false) {
                cout << "GAME OVER" << '\n';
                cout << score << '\n';
                return 0;
            }
        }
        print();
        cout << score << '\n' << '\n';
    }
	return 0;
}