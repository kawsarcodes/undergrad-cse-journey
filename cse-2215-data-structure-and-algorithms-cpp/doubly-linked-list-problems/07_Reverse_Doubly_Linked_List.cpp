/*
Problem(7): Reverse a doubly linked list.
Input 
1<->2<->3<->4
Output
4<->3<->2<->1
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

        void reverse(){
            if(head == nullptr) return;
            Node* temp = nullptr;
            Node* current = head;
            while(current != nullptr){
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
            }
            if(temp != nullptr){
                head = temp->prev;
            }
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
    dll.insertNodeAtEnd(1);
    dll.insertNodeAtEnd(2);
    dll.insertNodeAtEnd(3);
    dll.insertNodeAtEnd(4);

    dll.reverse();
    dll.traverseLinkedList();
}