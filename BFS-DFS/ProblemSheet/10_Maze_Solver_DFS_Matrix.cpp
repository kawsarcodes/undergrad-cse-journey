/*----------Backtracking DFS---------Matrix-------
Problem 10: Maze Solver (DFS in Matrix)
Given a maze represented as a 2D matrix, find a path from the top-left corner to the bottom-right corner.
The path can only move through '1's (open spaces) and not through '0's (walls).

Sample Input:
Rows: 4, Cols: 4
1 0 0 0
1 1 1 0
0 1 0 0
0 1 1 1

Sample Output:
Path from (0,0) to (3,3): (0,0), (1,0), (1,1), (2,1), (3,1), (3,2), (3,3)
*/

#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> path;
bool dfsMaze(int x, int y, int rows, int cols, vector<vector<int>> &maze, vector<vector<bool>> &visited)
{
    if (x < 0 || x >= rows || y < 0 || y >= cols || maze[x][y] == 0 || visited[x][y])
    {
        return false;
    }
    path.push_back({x, y});
    visited[x][y] = true;
    if (x == rows - 1 && y == cols - 1)
    {
        return true;
    }
    if (dfsMaze(x + 1, y, rows, cols, maze, visited))
        return true;
    if (dfsMaze(x, y + 1, rows, cols, maze, visited))
        return true;
    if (dfsMaze(x - 1, y, rows, cols, maze, visited))
        return true;
    if (dfsMaze(x, y - 1, rows, cols, maze, visited))
        return true;
    path.pop_back();
    return false;
}
int main()
{
    int rows, cols;
    cout << "Enter Rows and Cols: ";
    cin >> rows >> cols;
    vector<vector<int>> maze(rows, vector<int>(cols));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    cout << "Enter the Maze (1 for path, 0 for wall):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> maze[i][j];
        }
    }
    if (dfsMaze(0, 0, rows, cols, maze, visited))
    {
        cout << "Path from (0,0) to (" << rows - 1 << "," << cols - 1 << "): ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << "(" << path[i].first << "," << path[i].second << ")";
            if (i < path.size() - 1)
                cout << ", ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path found!" << endl;
    }
    return 0;
}