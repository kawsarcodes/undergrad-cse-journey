/*
Problem(3): Count the occurrence of a target element in circular list.
Input 
10->20->10->30->10->(head) , Target = 10
Output
3
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

        int countOccurrence(int target){
            if(head == nullptr) return 0;
            int count = 0;
            Node* temp = head;
            do {
                if(temp->value == target) count++;
                temp = temp->next;
            } while(temp != head);
            return count;
        }
};

int main(){
    CircularLinkedList cll;
    cll.insertNodeAtEnd(10);
    cll.insertNodeAtEnd(20);
    cll.insertNodeAtEnd(10);
    cll.insertNodeAtEnd(30);
    cll.insertNodeAtEnd(10);

    cout << "Occurrence of 10: " << cll.countOccurrence(10);
}