/*
Problem(1): Print the size of a doubly linked list.
Input 
34<->12<->55<->42<->11 
Output
5
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

        void traverseLinkedList(){
            Node* temp = head;
            while (temp != nullptr){
                cout << temp->value;
                if (temp->next != nullptr) cout << "<->";
                temp = temp->next;
            }
            cout << endl;
        }

        int sizeOfLinkedList(){
            Node* temp = head;
            int count = 0;
            while (temp != nullptr){
                count++;
                temp = temp->next;
            }
            return count;
        }
};

int main(){
    DoublyLinkedList dll;
    dll.insertNodeAtEnd(34);
    dll.insertNodeAtEnd(12);
    dll.insertNodeAtEnd(55);
    dll.insertNodeAtEnd(42);
    dll.insertNodeAtEnd(11);

    dll.traverseLinkedList();

    int size = dll.sizeOfLinkedList();
    cout << "Size: " << size;
}