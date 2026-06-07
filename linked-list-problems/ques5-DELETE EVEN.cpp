/*
Problem(4): Given a sorted linked list, insert a number so that after insertion, 
it remains sorted.
Input 
1->4->6->7->9->11, num = 3 
Output
1->3->4->6->7->9->11
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
            Node* temp = head;
            Node* prev = temp;
            while (temp != nullptr){
                if(temp->value % 2 == 0){
                prev->next = temp->next;
                temp = temp->next;
            }
            else{
                prev = temp;
                temp = temp->next;
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
}