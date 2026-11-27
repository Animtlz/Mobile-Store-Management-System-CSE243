#pragma once
#include <iostream>
using namespace std;

#ifndef SLList
#define SLList
template <typename T>
class LinkedList
{

    class Node
    {

    public:
        T data; // add needed data right here
        Node *next = NULL;
        Node() {}
        ~Node() { delete this; }
    };

private:
    int length = 0;

public:
    Node *Head;
    Node *tail;
    LinkedList() {}
    ~LinkedList()
    {
        Node *current = Head;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        Head = tail = NULL;
        length = 0;
        delete this;
    }
    void insertEnd(T &val) // according to data type
    {
        Node *NewNode = new Node();
        NewNode->data = val;

        if (Head == NULL)
        {
            Head = tail = NewNode;
        }
        else
        {
            tail->next = NewNode;
            tail = NewNode;
        }
        length++;
    }
    void insertStart(T &val)
    {
        Node *newnode = new Node();
        newnode->data = val;

        if (Head == NULL)
        {
            Head = tail = newnode;
        }
        else
        {
            newnode->next = Head;
            Head = newnode;
        }
        length++;
    }
    bool deleteStart()
    {
        if (Head == NULL)
        {
            cout << "empty list";
            return 0;
        }

        Node *temp = Head;

        if (Head == tail)
        {
            Head = tail = NULL;
        }
        else
        {
            Head = Head->next;
        }

        delete temp;
        length--;
        return 1;
    }
    bool deleteEnd()
    {
        Node *current = Head;
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
    bool deleteAt(T &val)
    { // according to data type

        if (Head == NULL)
        {
            cout << "empty";
            return 0;
        }
        if (Head->data == val)
        {
            Node *temp = Head;
            if (Head == tail)
            {
                Head = tail = NULL;
            }
            else
            {
                Head = Head->next;
            }
            delete temp;
            length--;
            cout << "removed successfully";
            return 1;
        }

        Node *prev = Head;
        Node *current = Head->next;

        while (current != NULL)
        {
            if (current->data == val)
            {
                prev->next = current->next;
                if (current == tail)
                {
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
    int search(T &val) // according to type
    {
        if (Head == NULL)
            return -1;

        int found = -1;
        Node *current = Head;
        int i = 0;
        while (current != NULL)
        {
            if (current->data == val)
            {
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
    void displayAll()
    {
        Node *H = Head;
        while (H != NULL)
        {
            cout << H->val << " ";
            H = H->adrs;
        }
        cout << "\n";
    }
    int getLength()
    {
        return length;
    }
    bool isEmpty()
    {
        return Head == NULL;
    }
    void clear()
    {
        Node *current = Head;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        Head = tail = NULL;
        length = 0;
    }
};
#endif SLList
