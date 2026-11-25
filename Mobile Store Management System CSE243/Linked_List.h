#pragma once
#ifndef SLList
#define SLList
template <typename T>
class LinkedList {
	
	class Node {

	public:
		T data;// add needed data right here
		Node* next=NULL;
		Node();
		~Node();
	};
	
	private:
		int length = 0;
	public:
		Node* Head;
		Node* tail;	
		LinkedList();
		~LinkedList();
		void insertEnd( T& data); //according to data type
		void insertStart(T& data);
		bool deleteStart();
		bool deleteEnd();
		bool deleteAt(T& val);  //according to data type
		int  search(T& data); //according to type
		void displayAll();
		int getLength();
		bool isEmpty();
		void clear();
		

};
#endif SLList