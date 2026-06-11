/*
Problem(2): Find the middle value of a doubly linked list.
Input 
34<->12<->55<->42<->11 
Output
55
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

        int middleValue(){
            if(head == nullptr) return -1;
            Node* slow = head;
            Node* fast = head;
            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow->value;
        }
};

int main(){
    DoublyLinkedList dll;
    dll.insertNodeAtEnd(34);
    dll.insertNodeAtEnd(12);
    dll.insertNodeAtEnd(55);
    dll.insertNodeAtEnd(42);
    dll.insertNodeAtEnd(11);

    cout << "Middle Value: " << dll.middleValue();
}