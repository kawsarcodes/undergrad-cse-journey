/*
Problem(2): Find the middle value of a circular linked list.
Input 
34->12->55->42->11->(head)
Output
55
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

        int middleValue(){
            if(head == nullptr) return -1;
            Node* slow = head;
            Node* fast = head;
            while(fast->next != head && fast->next->next != head){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow->value;
        }
};

int main(){
    CircularLinkedList cll;
    cll.insertNodeAtEnd(34);
    cll.insertNodeAtEnd(12);
    cll.insertNodeAtEnd(55);
    cll.insertNodeAtEnd(42);
    cll.insertNodeAtEnd(11);

    cout << "Middle Value: " << cll.middleValue();
}