/*
Problem(2): Print the number of occurrences of a given number in a linked list.
Input 
1->2->1->2->1->3->1, num = 1 
Output
4
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

        int findOccurance(int target){
            Node* temp = head;
            int count = 0;
            while(temp != nullptr){
                if(temp->value == target){
                    count++;
                    temp = temp->next;
                }
                else temp = temp->next;
            }
            return count;
        }

};

int main(){
    LinkedList ll;
    ll.insertNodeAtEnd(1);
    ll.insertNodeAtEnd(2);
    ll.insertNodeAtEnd(1);
    ll.insertNodeAtEnd(2);
    ll.insertNodeAtEnd(1);
    ll.insertNodeAtEnd(3);
    ll.insertNodeAtEnd(1);
    ll.traverserLinkedList();
    cout << "Enter the target: ";
    int target; cin >> target;
    int count = ll.findOccurance(target);
    cout << "Occurance: " << count;
}