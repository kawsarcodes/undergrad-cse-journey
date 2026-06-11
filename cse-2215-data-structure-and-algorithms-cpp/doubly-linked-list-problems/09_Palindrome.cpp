/*
Problem(9): Check if the doubly linked list is a palindrome.
Input 
1<->2<->3<->2<->1
Output
1 (True)
*/

#include<iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node* prev;
        Node(int value, Node* next = nullptr, Node* prev = nullptr){
            this->value = value;
            this->next = next;
            this->prev = prev;
        }
};

class DoublyLinkedList{
    public:
        Node* head;
        DoublyLinkedList(){
            head = nullptr;
        }

        void insertNodeAtEnd(int value){
            Node* insertNode = new Node(value);
            if(head == nullptr){
                head = insertNode;
                return;
            }
            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = insertNode;
            insertNode->prev = temp;
        }

        bool isPalindrome(){
            if(head == nullptr) return true;
            Node* left = head;
            Node* right = head;
            while(right->next != nullptr){
                right = right->next;
            }
            while(left != right && right->next != left){
                if(left->value != right->value) return false;
                left = left->next;
                right = right->prev;
            }
            return true;
        }
};

int main(){
    DoublyLinkedList dll;
    dll.insertNodeAtEnd(1);
    dll.insertNodeAtEnd(2);
    dll.insertNodeAtEnd(3);
    dll.insertNodeAtEnd(2);
    dll.insertNodeAtEnd(1);

    cout << "Is Palindrome: " << dll.isPalindrome();
}