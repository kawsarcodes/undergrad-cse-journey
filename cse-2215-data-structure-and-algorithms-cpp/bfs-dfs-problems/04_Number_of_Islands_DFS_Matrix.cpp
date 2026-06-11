/*---------DFS----Matrix-----------
Problem 4: Number of Islands (DFS on Matrix)
Given a 2D matrix representing a grid of '1's (land) and '0's (water), count the number of
islands. An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically.

Sample Input:
rows = 4, cols = 5
1 1 0 0 0
1 1 0 1 0
0 0 1 0 0
0 0 0 1 1

Sample Output:
Number of islands: 3
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, int rows, int cols, vector<vector<int>> &grid)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0)
    {
        return;
    }
    grid[i][j] = 0;
    dfs(i + 1, j, rows, cols, grid);
    dfs(i - 1, j, rows, cols, grid);
    dfs(i, j + 1, rows, cols, grid);
    dfs(i, j - 1, rows, cols, grid);
}
int countIslands(vector<vector<int>> &grid, int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 1)
            {
                count++;
                dfs(i, j, rows, cols, grid);
            }
        }
    }
    return count;
}
int main()
{
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    cout << "Enter the Grid (0s and 1s):" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }
    int result = countIslands(grid, rows, cols);
    cout << "Number of islands: " << result << endl;
    return 0;
}