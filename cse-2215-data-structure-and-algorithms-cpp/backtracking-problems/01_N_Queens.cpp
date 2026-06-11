/*
PROBLEM 01. N-Queens

Place N queens on an N x N chessboard such that no two queens attack each other. 
Return all unique boards where 'Q' represents a queen and '.' represents an empty space.

Sample input
4

Sample output
. Q . . 
. . . Q 
Q . . . 
. . Q . 

. . Q . 
Q . . . 
. . . Q 
. Q . . 
*/

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, const vector<string>& board, int n) {
    // Check upper left diagonal
    int r = row, c = col;
    while (r >= 0 && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r--; c--;
    }

    // Check left row
    c = col;
    while (c >= 0) {
        if (board[row][c] == 'Q') return false;
        c--;
    }

    // Check lower left diagonal
    r = row; c = col;
    while (r < n && c >= 0) {
        if (board[r][c] == 'Q') return false;
        r++; c--;
    }

    return true;
}

void solve(int col, vector<string>& board, int n) {
    if (col == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solve(col + 1, board, n);
            board[row][col] = '.'; // Backtrack
        }
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<string> board(n, string(n, '.'));
    solve(0, board, n);
    return 0;
}