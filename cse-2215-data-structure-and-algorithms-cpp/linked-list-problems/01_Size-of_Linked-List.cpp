/*
Problem(1): Print the size of a linked list.
Input 
34->12->55->42->11 
Output
5
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
            Node* insertNode = new Node(value, nullptr);

            if(head == nullptr){
                head = insertNode;
                return;
            }

            Node* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = insertNode;
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

        int sizeOfLinkedList(){
            Node* temp = head;
            int count = 0;
            while (temp != nullptr){
                count++;
                temp = temp->next;
            }
            return count;
        }
};

int main(){
    LinkedList ll;
    ll.insertNodeAtEnd(34);
    ll.insertNodeAtEnd(12);
    ll.insertNodeAtEnd(55);
    ll.insertNodeAtEnd(42);
    ll.insertNodeAtEnd(11);

    ll.traverseLinkedList();

    int size = ll.sizeOfLinkedList();
    cout << "Size: " << size;
}