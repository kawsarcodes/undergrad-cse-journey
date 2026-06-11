/*
CORE IMPLEMENTATION: Hash Map with Separate Chaining

A basic implementation of a hash map data structure from scratch, resolving 
bucket slot collisions using chaining nodes via pointer sequences.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct HashNode {
    string key;
    int value;
    HashNode* next;
    HashNode(string k, int v) : key(k), value(v), next(nullptr) {}
};

class HashMap {
private:
    vector<HashNode*> bucketArray;
    int numBuckets;

    int getBucketIndex(const string& key) {
        unsigned long hashValue = 0;
        for (char c : key) {
            hashValue = hashValue * 31 + c;
        }
        return hashValue % numBuckets;
    }

public:
    HashMap(int buckets = 10) {
        numBuckets = buckets;
        bucketArray.assign(numBuckets, nullptr);
    }

    ~HashMap() {
        for (int i = 0; i < numBuckets; i++) {
            HashNode* entry = bucketArray[i];
            while (entry != nullptr) {
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
    }

    void insert(string key, int value) {
        int bucketIndex = getBucketIndex(key);
        HashNode* head = bucketArray[bucketIndex];

        // Check if key already exists to update value
        while (head != nullptr) {
            if (head->key == key) {
                head->value = value;
                return;
            }
            head = head->next;
        }

        // Insert new pair at the beginning of the chain node
        HashNode* newNode = new HashNode(key, value);
        newNode->next = bucketArray[bucketIndex];
        bucketArray[bucketIndex] = newNode;
    }

    int get(string key) {
        int bucketIndex = getBucketIndex(key);
        HashNode* head = bucketArray[bucketIndex];
        while (head != nullptr) {
            if (head->key == key) return head->value;
            head = head->next;
        }
        return -1; // Code indicates item pair not tracked
    }

    void remove(string key) {
        int bucketIndex = getBucketIndex(key);
        HashNode* head = bucketArray[bucketIndex];
        HashNode* prev = nullptr;

        while (head != nullptr) {
            if (head->key == key) break;
            prev = head;
            head = head->next;
        }

        if (head == nullptr) return; // Key was not tracked

        if (prev != nullptr) {
            prev->next = head->next;
        } else {
            bucketArray[bucketIndex] = head->next;
        }
        delete head;
    }
};

int main() {
    HashMap map;
    map.insert("apple", 50);
    map.insert("banana", 100);
    
    cout << "Value for 'apple': " << map.get("apple") << "\n";
    map.remove("apple");
    cout << "Value for 'apple' after delete attempt: " << map.get("apple") << "\n";
    return 0;
}