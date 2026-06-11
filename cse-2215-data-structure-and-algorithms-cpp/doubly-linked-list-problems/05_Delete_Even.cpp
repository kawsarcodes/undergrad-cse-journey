/*
Problem(5): Delete all even values from the doubly linked list.
Input 
11<->12<->13<->14<->15
Output
11<->13<->15
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

        void deleteEven(){
            Node* temp = head;
            while(temp != nullptr){
                if(temp->value % 2 == 0){
                    Node* toDelete = temp;
                    if(temp == head){
                        head = head->next;
                        if(head != nullptr) head->prev = nullptr;
                        temp = head;
                    } else {
                        temp->prev->next = temp->next;
                        if(temp->next != nullptr) temp->next->prev = temp->prev;
                        temp = temp->next;
                    }
                    delete toDelete;
                } else {
                    temp = temp->next;
                }
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
    dll.insertNodeAtEnd(11);
    dll.insertNodeAtEnd(12);
    dll.insertNodeAtEnd(13);
    dll.insertNodeAtEnd(14);
    dll.insertNodeAtEnd(15);

    dll.deleteEven();
    dll.traverseLinkedList();
}