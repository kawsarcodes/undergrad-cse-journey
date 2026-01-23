/*---------Backtracking DFS-----------
Problem 8: Word Search in 2D Grid
Given a 2D grid of characters and a word, check if the word can be formed by consecutive
letters in the grid (horizontally, vertically, or diagonally).

Sample Input:
Rows: 3, Cols: 4
A B C E
S F C S
A D E E
Word: ABCCED

Sample Output:
Word 'ABCCED' exists in the grid
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool dfsWordSearch(int x, int y, int index, string &word, vector<vector<char>> &grid, int rows, int cols)
{
    if (index == word.length())
    {
        return true;
    }
    if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != word[index])
    {
        return false;
    }
    char temp = grid[x][y];
    grid[x][y] = '#';
    for (int i = 0; i < 8; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (dfsWordSearch(newX, newY, index + 1, word, grid, rows, cols))
        {
            return true;
        }
    }
    grid[x][y] = temp;
    return false;
}
int main()
{
    int rows, cols;
    cout << "Enter Rows and Cols: ";
    cin >> rows >> cols;
    vector<vector<char>> grid(rows, vector<char>(cols));
    cout << "Enter the Grid characters:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> grid[i][j];
        }
    }
    string word;
    cout << "Enter the word to search: ";
    cin >> word;
    bool found = false;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == word[0])
            {
                if (dfsWordSearch(i, j, 0, word, grid, rows, cols))
                {
                    found = true;
                    break;
                }
            }
        }
        if (found)
            break;
    }
    if (found)
    {
        cout << "Word '" << word << "' exists in the grid" << endl;
    }
    else
    {
        cout << "Word '" << word << "' does NOT exist" << endl;
    }
    return 0;
}