#pragma once
#ifndef DLList
#define DLList
class LinkedList {
	class Node {
		int data;// add needed data right here
		Node* next;
		Node();
		~Node();
	};
	Node* Head;
	void insert();
	void remove();
	void search();

};
#endif DLList