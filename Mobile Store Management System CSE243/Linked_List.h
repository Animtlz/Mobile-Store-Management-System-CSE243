#pragma once
#ifndef SLList
#define SLList
class LinkedList {
	class Node {
	public:
		int data;// add needed data right here
		Node* next;
		Node();
		~Node();
	};
	Node* Head;
	void insert(int data); //according to data type
	void insertAtBeginnig(int data);
	bool remove(int val);  //according to data type
	int search(int data); //according to type
	void displayer();

};
#endif SLList