/*
Problem(9): Check if the circular linked list is a palindrome.
Input 
1->2->3->2->1->(head)
Output
1 (True)
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

        bool isPalindrome(){
            if(head == nullptr) return true;
            int count = 0;
            Node* temp = head;
            do {
                count++;
                temp = temp->next;
            } while(temp != head);
            int* arr = new int[count];
            temp = head;
            for(int i = 0; i < count; i++){
                arr[i] = temp->value;
                temp = temp->next;
            }
            int left = 0, right = count - 1;
            while(left < right){
                if(arr[left] != arr[right]){
                    delete[] arr;
                    return false;
                }
                left++;
                right--;
            }
            delete[] arr;
            return true;
        }
};

int main(){
    CircularLinkedList cll;
    cll.insertNodeAtEnd(1);
    cll.insertNodeAtEnd(2);
    cll.insertNodeAtEnd(3);
    cll.insertNodeAtEnd(2);
    cll.insertNodeAtEnd(1);

    cout << "Is Palindrome: " << cll.isPalindrome();
}