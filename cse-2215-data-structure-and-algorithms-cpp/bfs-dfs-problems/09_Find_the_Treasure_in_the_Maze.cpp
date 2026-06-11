/*
Problem 9: Find the Treasure in the Maze
Given a 2D matrix representing a maze, where '0' represents a free cell and '1' represents a blocked cell, find the path from the top-left corner to the treasure (marked as ‘999’). You can move up, down, left, or right.

Sample Input:
Rows: 4, Cols: 4
0 0 0 0
0 1 1 0
0 1 999 0
0 0 0 1

Sample Output:
Path to treasure: (0,0), (0,1), (0,2), (0,3), (1,3), (2,3), (2,2)
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main()
{
    int rows, cols;
    cout << "Enter Rows and Cols: ";
    cin >> rows >> cols;
    vector<vector<int>> maze(rows, vector<int>(cols));
    cout << "Enter the Maze:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> maze[i][j];
        }
    }
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols, {-1, -1}));
    q.push({0, 0});
    visited[0][0] = true;
    int targetX = -1, targetY = -1;
    bool found = false;
    while (!q.empty())
    {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        if (maze[x][y] == 999)
        {
            targetX = x;
            targetY = y;
            found = true;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY] && maze[newX][newY] != 1)
            {
                visited[newX][newY] = true;
                q.push({newX, newY});
                parent[newX][newY] = {x, y};
            }
        }
    }
    if (found)
    {
        vector<pair<int, int>> path;
        pair<int, int> curr = {targetX, targetY};
        while (curr.first != -1)
        {
            path.push_back(curr);
            curr = parent[curr.first][curr.second];
        }
        reverse(path.begin(), path.end());
        cout << "Path to treasure: ";
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
        cout << "Treasure not reachable!" << endl;
    }
    return 0;
}