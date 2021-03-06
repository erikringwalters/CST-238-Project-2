//Erik Ring-Walters
//October 28, 2016
//CST 238 Data Structures
//Project 2
//Linked List Project
//ID: 002488407

//----- LinkedList.h -----
#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>
using namespace std;

typedef int ElementType;

class LinkedList
{
public:
	LinkedList();   // constructor
	~LinkedList();  // destructor
	LinkedList(const LinkedList & original); //copy constructor
	void insert(ElementType item, int pos);
	void erase(ElementType item);
	void traverse();
	void display(ostream & out) const;
	int countHowManyElements();//I understand this is not part of the projects requirements
	int count(int searchFor);
	ElementType getNth(int n);
	ElementType pop();
	void append(LinkedList b);
	void duplicates();
	/*--------------------------------------------------------------------
	Display the contensts of this LinkedList.
	Precondition: ostream out is open
	Postcondition: Elements of this LinkedList have been output to out.
	--------------------------------------------------------------------*/

private:
	class Node
	{
	public:
		ElementType data;
		Node * next;
		//------ Node OPERATIONS
		//-- Default constrctor: initializes next member to
		Node()
			: next(NULL)
		{ }
		//-- Explicit-value constructor: initializes data member to dataValue
		//-- and next member to 0
		Node(ElementType dataValue)
			: data(dataValue), next(NULL)
		{ }
	};
	Node * first;
	int mySize;
	Node * last; // This is for the pop() funtion;
};

#endif
