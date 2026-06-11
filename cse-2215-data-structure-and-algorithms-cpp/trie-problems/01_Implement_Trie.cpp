/*
PROBLEM 01. Implement Trie (Prefix Tree)

Build a complete interface evaluating incoming streaming operations for insert, search, 
and startsWith on text entries.

Sample input
5
insert apple
search apple
search app
startsWith app
insert app

Sample output
1
0
1
*/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isWord = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return node->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (!node->children[c - 'a']) return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};

int main() {
    int q;
    if (!(cin >> q)) return 0;

    Trie t;
    while (q--) {
        string type, word;
        cin >> type >> word;
        if (type == "insert") {
            t.insert(word);
        } else if (type == "search") {
            cout << t.search(word) << "\n";
        } else if (type == "startsWith") {
            cout << t.startsWith(word) << "\n";
        }
    }
    return 0;
}