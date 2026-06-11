/*
Problem(2): Given the head of a linked list, print the value of the middle node.
Input 
34->12->55->42->11 
12->8->65->10
Output
55
8
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
        }

        void middleValue(){
            if(head == nullptr) return;

            Node* slow = head;
            Node* fast = head;
            while(fast->next != nullptr && fast->next->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            cout << endl << "Middle value is: " << slow->value << endl;
        }

};

int main(){
    LinkedList ll1;

    ll1.insertNodeAtEnd(34);
    ll1.insertNodeAtEnd(12);
    ll1.insertNodeAtEnd(55);
    ll1.insertNodeAtEnd(42);
    ll1.insertNodeAtEnd(11);
    ll1.traverseLinkedList();
    ll1.middleValue();

    cout << "---------------" << endl;

    LinkedList ll2;

    ll2.insertNodeAtEnd(12);
    ll2.insertNodeAtEnd(8);
    ll2.insertNodeAtEnd(65);
    ll2.insertNodeAtEnd(10);
    ll2.traverseLinkedList();
    ll2.middleValue();
}
