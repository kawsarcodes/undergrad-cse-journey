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
            Node* insertNode = new Node(value, nullptr);
            if (head == nullptr){
                head = insertNode;
                return;
            }

            Node* temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = insertNode;
        }

        void traverserLinkedList(){
            Node* temp = head;
            while (temp != nullptr){
                cout << temp->value;
                if(temp->next != nullptr) cout << "->";
                temp = temp->next;
            }
            cout << endl;
        }

        void insertAtSortedLinkedList(int target){
            Node* insertNode = new Node (target, nullptr);
            Node* temp = head;
            while (temp->next != nullptr){
                if(temp->next->value > target){
                    Node* temp1 = temp->next;
                    temp->next = insertNode;
                    temp->next->next = temp1;
                    return;
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
    ll.traverserLinkedList();
    int target = 3;
    ll.insertAtSortedLinkedList(target);
    ll.traverserLinkedList();
}