/*
PROBLEM 02. Word Search II

Given an m x n board of characters and a list of strings words, return all words on the board.
Each word must be constructed from letters of sequentially adjacent cells.

Sample input
4 4
o a a n
e t a e
i h k r
i f l v
4
oath pea eat rain

Sample output
eat oath 
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26] = {};
    string word = "";
};

void insertWord(TrieNode* root, const string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        if (!curr->children[c - 'a']) curr->children[c - 'a'] = new TrieNode();
        curr = curr->children[c - 'a'];
    }
    curr->word = word;
}

void dfs(int r, int c, vector<vector<char>>& board, TrieNode* node, vector<string>& found) {
    char ch = board[r][c];
    if (ch == '#' || !node->children[ch - 'a']) return;

    node = node->children[ch - 'a'];
    if (!node->word.empty()) {
        found.push_back(node->word);
        node->word = ""; // Avoid duplicate captures
    }

    board[r][c] = '#'; // Mark cell visited
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
            dfs(nr, nc, board, node, found);
        }
    }
    board[r][c] = ch; // Backtrack
}

int main() {
    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<vector<char>> board(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> board[i][j];
    }

    int w_size;
    cin >> w_size;
    TrieNode* root = new TrieNode();
    for (int i = 0; i < w_size; i++) {
        string w;
        cin >> w;
        insertWord(root, w);
    }

    vector<string> found;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dfs(i, j, board, root, found);
        }
    }

    sort(found.begin(), found.end());
    for (int i = 0; i < found.size(); i++) {
        cout << found[i] << (i == found.size() - 1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}