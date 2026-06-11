/*
Problem(1): Print the size of a circular linked list.
Input 
34->12->55->42->11->(head)
Output
5
*/

#include<iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int value, Node* next = nullptr){
            this->value = value;
            this->next = next;
        }
};

class CircularLinkedList{
    public:
        Node* head;
        CircularLinkedList(){
            head = nullptr;
        }

        void insertNodeAtEnd(int value){
            Node* insertNode = new Node(value);
            if(head == nullptr){
                head = insertNode;
                insertNode->next = head;
                return;
            }
            Node* temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            temp->next = insertNode;
            insertNode->next = head;
        }

        void traverseLinkedList(){
            if(head == nullptr) return;
            Node* temp = head;
            do {
                cout << temp->value << "->";
                temp = temp->next;
            } while(temp != head);
            cout << "(head)" << endl;
        }

        int sizeOfLinkedList(){
            if(head == nullptr) return 0;
            int count = 0;
            Node* temp = head;
            do {
                count++;
                temp = temp->next;
            } while(temp != head);
            return count;
        }
};

int main(){
    CircularLinkedList cll;
    cll.insertNodeAtEnd(34);
    cll.insertNodeAtEnd(12);
    cll.insertNodeAtEnd(55);
    cll.insertNodeAtEnd(42);
    cll.insertNodeAtEnd(11);

    cll.traverseLinkedList();

    int size = cll.sizeOfLinkedList();
    cout << "Size: " << size;
}