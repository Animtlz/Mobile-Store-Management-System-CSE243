#pragma once
#include <iostream>
#include <string>
using namespace std;

// Singly linked list. T must provide operator== (for deleteAt/search)
// and display() (for displayAll).
template <typename T>
class LinkedList
{
public:
    class Node
    {
    public:
        T data;
        Node *next = nullptr;

        explicit Node(const T &value) : data(value) {}
    };

    Node *Head = nullptr;
    Node *tail = nullptr;

    LinkedList() = default;
    LinkedList(const LinkedList &other) { copyFrom(other); }
    LinkedList &operator=(const LinkedList &other)
    {
        if (this != &other)
        {
            clear();
            copyFrom(other);
        }
        return *this;
    }
    ~LinkedList() { clear(); }

    void insertEnd(const T &val)
    {
        Node *n = new Node(val);
        if (Head == nullptr)
            Head = tail = n;
        else
        {
            tail->next = n;
            tail = n;
        }
        length++;
    }
    void insertStart(const T &val)
    {
        Node *n = new Node(val);
        if (Head == nullptr)
            Head = tail = n;
        else
        {
            n->next = Head;
            Head = n;
        }
        length++;
    }
    bool deleteStart()
    {
        if (Head == nullptr)
            return false;
        Node *temp = Head;
        Head = Head->next;
        if (Head == nullptr)
            tail = nullptr;
        delete temp;
        length--;
        return true;
    }
    bool deleteEnd()
    {
        if (Head == nullptr)
            return false;
        if (Head == tail)
            return deleteStart();
        Node *current = Head;
        while (current->next != tail)
            current = current->next;
        delete tail;
        tail = current;
        tail->next = nullptr;
        length--;
        return true;
    }
    bool deleteAt(const T &val)
    {
        Node *prev = nullptr;
        Node *current = Head;
        while (current != nullptr)
        {
            if (current->data == val)
            {
                if (prev == nullptr)
                    Head = current->next;
                else
                    prev->next = current->next;
                if (current == tail)
                    tail = prev;
                delete current;
                length--;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false;
    }
    int search(const T &val) const
    {
        int i = 0;
        for (Node *c = Head; c != nullptr; c = c->next, i++)
            if (c->data == val)
                return i;
        return -1;
    }
    void displayAll(bool showZeroStock = false) const // USERS AND MOBILES
    {
        if (Head == nullptr)
        {
            cout << "(nothing to show)\n";
            return;
        }
        Head->data.displayHeader();
        for (Node *c = Head; c != nullptr; c = c->next)
            c->data.display(showZeroStock);
        Head->data.displayFooter();
    }

    void displayAllOrders(string customerId = "") const // ORDERS
    {
        if (Head == nullptr)
        {
            cout << "(nothing to show)\n";
            return;
        }
        Head->data.displayHeader();
        for (Node *c = Head; c != nullptr; c = c->next)
            c->data.displayOrder(customerId);
        Head->data.displayFooter();
    }

    int getLength() const { return length; }
    bool isEmpty() const { return Head == nullptr; }
    void clear()
    {
        Node *current = Head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        Head = tail = nullptr;
        length = 0;
    }

private:
    int length = 0;
    void copyFrom(const LinkedList &other)
    {
        for (Node *c = other.Head; c != nullptr; c = c->next)
            insertEnd(c->data);
    }
};
