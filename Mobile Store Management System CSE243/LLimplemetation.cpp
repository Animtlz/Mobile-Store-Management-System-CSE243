#include "Linked_List.h"
#include<iostream>
using namespace std;
LinkedList::Node::Node() {}
LinkedList::Node::~Node() { delete this; }
void LinkedList::insert(int val)
{
    Node* NewNode = new Node();
    NewNode->data = val;

    if (Head == NULL) {
        Head = NewNode;
    }
    else {
        Head->next = NewNode;
    }
}
void LinkedList::insertAtBeginnig(int val)
{
    {
        Node* newnode= new Node();
        newnode->data = val;

        if (Head== NULL) {
            Head = newnode;
        }
        else {
            newnode->next = Head;
            Head = newnode;
        }
    }
}
bool LinkedList::remove(int val) {

    bool found = 0;
    Node* current = Head;
    if (Head == NULL) {
        cout << "empty";
        return 0;
    }
    while (current != NULL) {
        if (current->data == val) {
            cout << "removed successfully";
            delete current;
            return 1;
        }
        current = current->next;
    }
    return 0;
    

}
void LinkedList::displayer() {
	Node* H = Head;
	while (H != nullptr)
	{
		cout << H->data << endl;
		H = H->next;
	}

}
int LinkedList::search(int val)
{
    if (Head == NULL) return -1;

    int found = -1;
    Node* current = Head;
    int i = 0;
    while (current != NULL) {
        if (current->data == val) {
            found = i;
            break;
        }
        current = current->next;
        i++;
    }
    if (found == -1)
    {
        cout << "not found";
    }
    return found;
}