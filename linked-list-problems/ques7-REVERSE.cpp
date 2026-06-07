/*
Problem(7): Reverse a singly linked list.
Input 
7->12->8->65->10 
Output
10->65->8->12->7
*/

#include<iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node(int value, Node* next){
            this->value = value;
            this->next = next;
        }
};

class LinkedList{
    public:
        Node* head; 
        LinkedList(){
            head = nullptr;
        }

        void insertNodeAtEnd(int value){
            Node* newNode = new Node(value, nullptr);

            if(head == nullptr){
                head = newNode;
                return;
            }

            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }

        void traverseLinkedList(){
            Node* temp = head;
            while (temp != nullptr){
                cout << temp->value;
                if (temp->next != nullptr) cout << "->";
                temp = temp->next;
            }
            cout << endl;
        }

        void reverseSinglyLinkedList(){
            Node* prevNode = nullptr;
            Node* currNode = head;
            Node* nextNode = nullptr;
            while (currNode != nullptr){
                nextNode = currNode->next;
                currNode->next = prevNode;
                prevNode = currNode;
                currNode = nextNode;
            }
            head = prevNode;
        }

        

};


int main(){
    LinkedList ll;
    ll.insertNodeAtEnd(7);
    ll.insertNodeAtEnd(12);
    ll.insertNodeAtEnd(8);
    ll.insertNodeAtEnd(65);
    ll.insertNodeAtEnd(10);

    ll.traverseLinkedList();
    ll.reverseSinglyLinkedList();
    ll.traverseLinkedList();
}