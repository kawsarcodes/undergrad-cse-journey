/*
Problem(3): Count the occurrence of a target element.
Input 
10<->20<->10<->30<->10 , Target = 10
Output
3
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

        int countOccurrence(int target){
            int count = 0;
            Node* temp = head;
            while(temp != nullptr){
                if(temp->value == target) count++;
                temp = temp->next;
            }
            return count;
        }
};

int main(){
    DoublyLinkedList dll;
    dll.insertNodeAtEnd(10);
    dll.insertNodeAtEnd(20);
    dll.insertNodeAtEnd(10);
    dll.insertNodeAtEnd(30);
    dll.insertNodeAtEnd(10);

    cout << "Occurrence of 10: " << dll.countOccurrence(10);
}