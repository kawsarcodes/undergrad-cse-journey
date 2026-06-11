/*
CORE IMPLEMENTATION: Custom Prefix Tree (Trie)

A scratch template tracking character tree arrays using custom struct node configurations 
for linear string insertions, containment validations, and prefix checks.
*/

#include <iostream>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isEndOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return curr->isEndOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return true;
    }
};

int main() {
    Trie t;
    t.insert("apple");
    cout << "Search apple: " << t.search("apple") << "\n";   // Outputs 1
    cout << "Search app: " << t.search("app") << "\n";       // Outputs 0
    cout << "Prefix app: " << t.startsWith("app") << "\n";   // Outputs 1
    return 0;
}