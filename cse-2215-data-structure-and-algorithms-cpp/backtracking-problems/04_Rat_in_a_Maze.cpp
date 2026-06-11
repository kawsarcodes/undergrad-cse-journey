/*
PROBLEM 04. Rat in a Maze

A rat starts from source index (0,0) and wants to reach destination index (N-1, N-1) 
in an N x N matrix grid. Find all paths consisting of directions: 'D' (Down), 'L' (Left), 'R' (Right), 'U' (Up).

Sample input
4
1 0 0 0
1 1 0 1
1 1 0 0
0 1 1 1

Sample output
DDRDRR DRDDRR 
*/

#include <bits/stdc++.h>
using namespace std;

void findPaths(int r, int c, vector<vector<int>>& maze, int n, string path, vector<string>& result) {
    if (r == n - 1 && c == n - 1) {
        result.push_back(path);
        return;
    }

    // Mark current cell visited by modifying the matrix grid safely
    maze[r][c] = 0;

    // Down
    if (r + 1 < n && maze[r + 1][c] == 1) findPaths(r + 1, c, maze, n, path + 'D', result);
    // Left
    if (c - 1 >= 0 && maze[r][c - 1] == 1) findPaths(r, c - 1, maze, n, path + 'L', result);
    // Right
    if (c + 1 < n && maze[r][c + 1] == 1) findPaths(r, c + 1, maze, n, path + 'R', result);
    // Up
    if (r - 1 >= 0 && maze[r - 1][c] == 1) findPaths(r - 1, c, maze, n, path + 'U', result);

    maze[r][c] = 1; // Backtrack
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> maze(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    vector<string> result;
    if (maze[0][0] == 1) {
        findPaths(0, 0, maze, n, "", result);
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}