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
bool LinkedList::remove(int val) {

    bool found = 0;
    if (Head->data == val) {
        Head = Head->next;
        return 0;
    }
    Node* current = Head;
    while (current == NULL) {
        if (current->next->data == val) {
            current->next = current->next->next;
            cout << "removed successfully";
            found = 1;
            break;
        }
        current = current->next;
    }
    return found;
    

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
    return found;
}