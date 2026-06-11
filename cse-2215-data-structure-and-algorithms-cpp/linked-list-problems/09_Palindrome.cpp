/*
Problem(9): Given a singly linked list, print "YES" if it is a palindrome otherwise print "NO".
Input 
1->2->2->1
Output
YES
*/

#include<iostream>
#include<vector> 
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int value, Node* next){
            this->value = value;
            this->next = next;
        }
};

class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head = nullptr;
        }

        void insertNodeAtEnd(int value){
            Node* insertNode = new Node(value, nullptr);
            if(head == nullptr){
                head = insertNode;
                return;
            }
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = insertNode;
        }

        void traverseLinkedList(){
            Node* temp = head;
            while (temp != nullptr){
                cout << temp->value;
                if (temp->next != nullptr) cout << "->";
                temp = temp->next;
            }
            cout << endl;
        }

        // --- PROBLEM 9 - PALIDROME ---
        void checkPalindrome(){
            vector<int> values;
            Node* temp = head;

            // Step 1: Copy all nodes to a vector
            while(temp != nullptr){
                values.push_back(temp->value);
                temp = temp->next;
            }

            // Step 2: Check if vector is palindrome
            int left = 0;
            int right = values.size() - 1;
            bool isPalindrome = true;

            while(left <= right){
                if(values[left] != values[right]){
                    isPalindrome = false;
                    break;
                }
                left++;
                right--;
            }

            if(isPalindrome){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
};

int main(){
    // Test Case 1: Palindrome
    LinkedList ll1;
    ll1.insertNodeAtEnd(1);
    ll1.insertNodeAtEnd(2);
    ll1.insertNodeAtEnd(2);
    ll1.insertNodeAtEnd(1);
    
    cout << "List 1: ";
    ll1.traverseLinkedList();
    ll1.checkPalindrome(); // Output: YES

    cout << "-----------------" << endl;

    // Test Case 2: Not Palindrome
    LinkedList ll2;
    ll2.insertNodeAtEnd(1);
    ll2.insertNodeAtEnd(2);
    ll2.insertNodeAtEnd(3);
    ll2.insertNodeAtEnd(1);

    cout << "List 2: ";
    ll2.traverseLinkedList();
    ll2.checkPalindrome(); // Output: NO
    
    return 0;
}