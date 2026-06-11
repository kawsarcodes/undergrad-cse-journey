/*
Problem(5): Delete all even values from the circular linked list.
Input 
11->12->13->14->15->(head)
Output
11->13->15->(head)
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

        void deleteEven(){
            if(head == nullptr) return;
            Node* current = head;
            Node* prev = nullptr;
            Node* tail = head;
            while(tail->next != head){
                tail = tail->next;
            }
            bool headDeleted = false;
            do {
                if(current->value % 2 == 0){
                    Node* toDelete = current;
                    if(current == head){
                        if(head->next == head){
                            head = nullptr;
                            delete toDelete;
                            return;
                        }
                        head = head->next;
                        tail->next = head;
                        current = head;
                        headDeleted = true;
                    } else {
                        prev->next = current->next;
                        if(current == tail){
                            tail = prev;
                        }
                        current = current->next;
                    }
                    delete toDelete;
                } else {
                    prev = current;
                    current = current->next;
                    headDeleted = false;
                }
            } while(current != head || headDeleted);
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
    cll.insertNodeAtEnd(11);
    cll.insertNodeAtEnd(12);
    cll.insertNodeAtEnd(13);
    cll.insertNodeAtEnd(14);
    cll.insertNodeAtEnd(15);

    cll.deleteEven();
    cll.traverseLinkedList();
}