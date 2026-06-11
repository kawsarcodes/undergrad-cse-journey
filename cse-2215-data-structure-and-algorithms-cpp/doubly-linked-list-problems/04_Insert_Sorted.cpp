/*
Problem(4): Insert an element into a sorted doubly linked list.
Input 
10<->20<->30 , Target = 25
Output
10<->20<->25<->30
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

        void insertSorted(int value){
            Node* insertNode = new Node(value);
            if(head == nullptr){
                head = insertNode;
                return;
            }
            if(value <= head->value){
                insertNode->next = head;
                head->prev = insertNode;
                head = insertNode;
                return;
            }
            Node* temp = head;
            while(temp->next != nullptr && temp->next->value < value){
                temp = temp->next;
            }
            insertNode->next = temp->next;
            if(temp->next != nullptr){
                temp->next->prev = insertNode;
            }
            temp->next = insertNode;
            insertNode->prev = temp;
        }

        void traverseLinkedList(){
            Node* temp = head;
            while (temp != nullptr){
                cout << temp->value;
                if (temp->next != nullptr) cout << "<->";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    DoublyLinkedList dll;
    dll.insertNodeAtEnd(10);
    dll.insertNodeAtEnd(20);
    dll.insertNodeAtEnd(30);

    dll.insertSorted(25);
    dll.traverseLinkedList();
}