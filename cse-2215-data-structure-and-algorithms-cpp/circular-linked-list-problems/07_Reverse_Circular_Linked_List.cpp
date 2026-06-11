/*
Problem(7): Reverse a circular linked list.
Input 
1->2->3->4->(head)
Output
4->3->2->1->(head)
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

        void reverse(){
            if(head == nullptr) return;
            Node* prev = nullptr;
            Node* current = head;
            Node* nextNode = nullptr;
            Node* tail = head;
            while(tail->next != head){
                tail = tail->next;
            }
            do {
                nextNode = current->next;
                current->next = prev;
                prev = current;
                current = nextNode;
            } while(current != head);
            head->next = prev;
            head = prev;
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
    cll.insertNodeAtEnd(1);
    cll.insertNodeAtEnd(2);
    cll.insertNodeAtEnd(3);
    cll.insertNodeAtEnd(4);

    cll.reverse();
    cll.traverseLinkedList();
}