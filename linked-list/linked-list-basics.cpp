#include<iostream>
using namespace std;

class Node
{
public:
    int value;
    Node* next;

    Node(int value, Node* next)
    {
        this->value = value;
        this->next = next;
    }
};


class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        this->head = nullptr;
    }


    void insertNodeAtStart(Node* newNode)
    {
        Node* temp = head;
        head = newNode;
        head->next = temp;
    }

    void insertNodeAtEnd(Node* newNode)
    {
        Node* temp = head;

        while ( temp -> next != nullptr)
        {
            temp = temp -> next;
        }
        temp -> next = newNode;
    }


    void traverseLinkedList()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout<<temp->value<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }

    int searchAtLinkedList(int target)
    {
        Node* temp = head;

        while(temp != nullptr)
        {
            if(temp -> value == target)
            {
                return 1;
            }
            temp = temp -> next;
        }
        return 0;
    }

    void insertNodeAtMiddle( Node* newNode, int target)
    {
        Node* temp = head;
        while(temp -> next != nullptr)
        {
            if(temp -> value == target)
            {
                Node* temp1 = temp -> next;
                temp -> next = newNode;
                newNode -> next = temp1;
                return;
            }
            else
            {
                temp =  temp -> next;
            }
        }

        temp ->next = newNode;
    }

    void deleteNodeFromBeginning()
    {
        head = head -> next;
    }

    void deleteNodeFromEnd()
    {
        Node* temp = head;
        Node* prev = temp;

        while (temp -> next != nullptr)
        {
            prev = temp;
            temp = temp -> next;
        }
        prev->next = nullptr;
    }


    void deleteNodeAtMiddle(int target)
    {
        Node* temp = head;
        Node* prev = temp;

        while(temp != nullptr)
        {
            if(temp->value == target)
            {
                prev -> next = temp->next;
                return;
            }
            else
            {
                prev = temp;
                temp = temp -> next;
            }
        }
    }

    void deleteEvenElementFromLinkedList()
    {
        Node* temp = head;
        Node* prev = temp;

        while(temp != nullptr)
        {
            if(temp->value % 2 == 0)
            {
                prev->next = temp->next;
                temp = temp -> next;
            }
            else
            {
                prev = temp;
                temp = temp -> next;
            }
        }
    }

    int countNumberofOccurrence(int target)
    {
        int count = 0;

        Node* temp = head;

        while(temp != nullptr)
        {
            if(temp -> value == target)
            {
                count++;
            }
            temp = temp -> next;
        }
        return count;
    }

    void insertAtSortedArray(int target)
    {
        Node* temp = head;
        while(temp -> next != nullptr)
        {
            if(temp->next->value > target)
            {
                Node* newNode = new Node(target, temp->next);
                temp -> next = newNode;
                return;
            }
            else
            {
                temp = temp -> next;
            }
        }
    }
};

int main()
{
    LinkedList linkedList;
    int target;

    Node* one = new Node(1, nullptr);
    linkedList.head = one;

    linkedList.traverseLinkedList();

    // insert node at the beginning
    Node* zero = new Node(0, nullptr);
    linkedList.insertNodeAtStart(zero);
    linkedList.traverseLinkedList();

    // insert node at the end
    Node* two = new Node(2, nullptr);
    linkedList.insertNodeAtEnd(two);
    linkedList.traverseLinkedList();

    // insert node at the end
    Node* three = new Node(3, nullptr);
    linkedList.insertNodeAtEnd(three);
    linkedList.traverseLinkedList();

    Node* six = new Node(6, nullptr);
    linkedList.insertNodeAtEnd(six);
    linkedList.traverseLinkedList();

    Node* eight = new Node(8, nullptr);
    linkedList.insertNodeAtEnd(eight);
    linkedList.traverseLinkedList();



//    // search at linked list
//    cout<<"Enter your target : ";
//    cin >> target;
//
//    int result = linkedList.searchAtLinkedList(target);
//    if( result == 1 )
//    {
//        cout << target << " is found at linked list"<<endl;
//    }
//    else
//    {
//        cout << target << " is not found at linked list"<<endl;
//    }
//
//
//    //insert node at the middle
//    cout<<"Enter your target node after which you want to insert : ";
//    cin >> target;
//    Node* temp = new Node(3, nullptr);
//    linkedList.insertNodeAtMiddle(three, target);
//    linkedList.traverseLinkedList();

    //delete node from beginning
//    linkedList.deleteNodeFromBeginning();
//    linkedList.traverseLinkedList();

    // delete node from end
//    linkedList.deleteNodeFromEnd();
//    linkedList.traverseLinkedList();

    //insert node at the middle
//    cout<<"Enter your target node you want to delete : ";
//    cin >> target;
//    linkedList.deleteNodeAtMiddle(target);
//    linkedList.traverseLinkedList();

//    linkedList.deleteEvenElementFromLinkedList();
//    linkedList.traverseLinkedList();

    linkedList.insertAtSortedArray(4);
    linkedList.traverseLinkedList();
}
