/*
Problem(4): Insert an element into a sorted circular linked list.
Input 
10->20->30->(head) , Target = 25
Output
10->20->25->30->(head)
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

        void insertSorted(int value){
            Node* insertNode = new Node(value);
            if(head == nullptr){
                head = insertNode;
                insertNode->next = head;
                return;
            }
            if(value <= head->value){
                Node* temp = head;
                while(temp->next != head){
                    temp = temp->next;
                }
                insertNode->next = head;
                temp->next = insertNode;
                head = insertNode;
                return;
            }
            Node* temp = head;
            while(temp->next != head && temp->next->value < value){
                temp = temp->next;
            }
            insertNode->next = temp->next;
            temp->next = insertNode;
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
};

int main(){
    CircularLinkedList cll;
    cll.insertNodeAtEnd(10);
    cll.insertNodeAtEnd(20);
    cll.insertNodeAtEnd(30);

    cll.insertSorted(25);
    cll.traverseLinkedList();
}