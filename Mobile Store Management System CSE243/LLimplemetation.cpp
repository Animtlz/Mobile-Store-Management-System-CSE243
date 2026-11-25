#include "Linked_List.h"
#include<iostream>
using namespace std;

template<typename T>
LinkedList<T>::Node::Node() {}

template<typename T>
LinkedList<T>::Node::~Node() { delete this; }

template<typename T>
LinkedList<T>::LinkedList() {}
template<typename T>
LinkedList<T>::~LinkedList()
{
    Node* current = Head;
    while (current != NULL)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    Head = tail = NULL;
    length = 0;
    delete this;
}

template<typename T>
void LinkedList<T>::insertEnd( T& val)
{
    Node* NewNode = new Node();
    NewNode->data = val;

    if (Head == NULL) {
        Head = tail = NewNode;
    }
    else {
        tail->next = NewNode;
        tail = NewNode;
    }
    length++;
}

template<typename T>
void LinkedList<T>::insertStart (T& val)
{
    Node* newnode = new Node();
    newnode->data = val;

    if (Head == NULL) {
        Head =tail= newnode;
    }
    else {
        newnode->next = Head;
        Head = newnode;
    }
    length++;
}

template <typename T>
bool LinkedList<T>::deleteStart() {
    if (Head == NULL) {
        cout << "empty list";
        return 0;
    }

    Node* temp = Head;

    if (Head == tail) {       
        Head = tail = NULL;
    }
    else {
        Head = Head->next;     
    }

    delete temp;              
    length--;
    return 1;
}

template <typename T>
bool LinkedList<T>:: deleteEnd() {
    Node* current = Head;
    if (Head == NULL)
    {
        cout << "empty list";
        return 0;
    }
    if (Head == tail)
    {
        delete Head;
        Head = tail = NULL;
        length--;
        return 1;
    }
    while (current->next->next != NULL)
    {
        current = current->next;
    }
    delete tail;
    tail = current;
    tail->next = NULL;
    length--;
    return 1;
}

template<typename T>
bool LinkedList<T>::deleteAt(T& val) {

    if (Head == NULL) {
        cout << "empty";
        return 0;
    }
    if (Head->data == val) {
        Node* temp = Head;
        if (Head == tail) {     
            Head = tail = NULL;
        }
        else {
            Head = Head->next;
        }
        delete temp;
        length--;
        cout << "removed successfully";
        return 1;
    }

    Node* prev = Head;
    Node* current = Head->next;

    while (current != NULL) {
        if (current->data == val) {
            prev->next = current->next; 
            if (current == tail) {       
                tail = prev;
            }
            delete current;
            length--;
            cout << "removed successfully";
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0; 
}

template <typename T>
void LinkedList<T>::displayAll()
{
    Node* H = Head;
    while (H != NULL)
    {
        cout << H->val << " ";
        H = H->adrs;

    }
    cout << "\n";
}

template<typename T>
int LinkedList<T>::search(T& val)
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
template <typename T>
int LinkedList<T>::getLength()
{
    return length;
}
template <typename T>
bool LinkedList<T>::isEmpty()
{
    return Head == NULL;
}
template <typename T>
void LinkedList<T>::clear()
{
    Node* current = Head;
    while (current != NULL)
    {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    Head = tail = NULL;
    length = 0;
}

