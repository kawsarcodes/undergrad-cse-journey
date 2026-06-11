/*
Problem(5): Given a linked list, delete all nodes that contain even numbers.
Input 
1->4->6->7->9->11
Output
1->7->9->11
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

        void DeleteEvenNodes(){
            while (head != nullptr && head->value % 2 == 0) {
                Node* nodeToDelete = head;
                head = head->next;
                delete nodeToDelete;
            }

            if (head == nullptr) return;

            Node* current = head;
            while (current->next != nullptr) {
                if (current->next->value % 2 == 0) {
                    Node* nodeToDelete = current->next;
                    current->next = current->next->next;
                    delete nodeToDelete;
                } else {
                    current = current->next;
                }
            }
        }
};

int main(){
    LinkedList ll;
    ll.insertNodeAtEnd(1);
    ll.insertNodeAtEnd(4);
    ll.insertNodeAtEnd(6);
    ll.insertNodeAtEnd(7);
    ll.insertNodeAtEnd(9);
    ll.insertNodeAtEnd(11);

    ll.traverseLinkedList();
    ll.DeleteEvenNodes();
    ll.traverseLinkedList();
    
    return 0;
}