//Erik Ring-Walters
//October 28, 2016
//CST 238 Data Structures
//Project 2
//Linked List Project
//ID: 002488407

#include <iostream>
using namespace std;

#include "LinkedList.h"

//-- Default constructor
LinkedList::LinkedList()
{
	mySize = 0;
	first = NULL;
}

//-- Definition of the copy constructor
LinkedList::LinkedList(const LinkedList & origList)
{
	mySize = origList.mySize;
	first = NULL;

	if (mySize == 0)
		return;

	Node * origPtr, *lastPtr;
	first = new Node(origList.first->data); // copy first node
	lastPtr = first;
	origPtr = origList.first->next;
	while (origPtr != NULL)
	{
		lastPtr->next = new Node(origPtr->data);
		origPtr = origPtr->next;
		lastPtr = lastPtr->next;
	}
}


//-- Definition of the destructor
LinkedList::~LinkedList()
{
	Node * prev = first;
	Node * ptr;

	while (prev != NULL)
	{
		ptr = prev->next;
		delete prev;
		prev = ptr;
	}
}

// Traverse the LinkedList and process data in each node
void LinkedList::traverse()
{
	Node * ptr = first;
	ElementType sum = 0;

	while (ptr != NULL)
	{
		// Process part of data
		// For example find sum of all data.
		sum += ptr->data;
		ptr = ptr->next;
	}
	return;
}


//-- Definition of insert()
void LinkedList::insert(ElementType dataVal, int index)
{
	if (index < 0 || index > mySize)
	{
		cerr << "Illegal location to insert -- " << index << endl;
		return;
	}

	mySize++;
	Node * newPtr = new Node(dataVal);
	Node * predPtr = first;
	if (index == 0)
	{
		newPtr->next = first;
		first = newPtr;
	}
	else
	{
		for (int i = 1; i < index; i++)
			predPtr = predPtr->next;
		newPtr->next = predPtr->next;
		predPtr->next = newPtr;
	}

}


//-- Definition of erase()
void LinkedList::erase(int index)
{
	if (index < 0 || index >= mySize)
	{
		cerr << "Illegal location to delete -- " << index << endl;
		return;
	}

	mySize--;
	Node * ptr;
	Node * predPtr = first;
	if (index == 0)
	{
		ptr = first;
		first = ptr->next;
		delete ptr;
	}
	else
	{
		for (int i = 1; i < index; i++)
			predPtr = predPtr->next;
		ptr = predPtr->next;
		predPtr->next = ptr->next;
		delete ptr;
	}
}



//-- Definition of display()
void LinkedList::display(ostream & out) const
{
	Node * ptr = first;
	while (ptr != 0)
	{
		out << ptr->data << " ";
		ptr = ptr->next;
	}
}

//--Definition of countHowManyElements()
int LinkedList::countHowManyElements()
{
	int counter = 0;
	Node * ptr = first;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		counter++;
	}
	return counter;
}

//--Definition of overloaded count(int searchFor)
int LinkedList::count(int searchFor)
{
	Node *ptr = first;
	int counter = 0;
	while (ptr != NULL)
	{
		if (ptr->data == searchFor)
		{
			counter++;
		}
		ptr = ptr->next;
	}
	return counter;
}

//--Definition of getNth(n)
ElementType LinkedList::getNth(int n)
{
	Node *ptr = first;
	for (int i = 0; i < n - 1; i++)
	{
		ptr = ptr->next;
	}
	return ptr->data;
}

//--Definition of pop()
ElementType LinkedList::pop()
{
	Node * ptr = first;
	if (first == NULL)//checks whether list is empty
	{
		cout << "---LIST IS EMPTY---\n";
		return -1;
	}
	else
	{
		ElementType data;
		data = ptr->data;
		erase(0);
		return data;
	}
}

//--Definition of append()
void LinkedList::append(LinkedList b)//argument for looking at second list
{
	Node *bptr = b.first;//sets pointer to beginning of second list
	while (bptr != NULL)//until we reach the end of second list
	{
		insert(bptr->data, mySize);//take second list's element's data and put it at the end of first list.
		bptr = bptr->next;//increment bptr
	}
}

//--Definiton of duplicates()
void LinkedList::duplicates()//this was the hardest one for me.
{
	Node *ptr1 = first;
	Node *ptr2 = first;
	Node * dupPtr = ptr2;
	int index = 0;
	while (ptr1 != NULL)
	{
		//cout << "Pointer 1 is " << ptr1 << endl;
		ptr2 = first;
		index = 0;
		while (ptr2 != NULL)
		{
			if (ptr1->data == ptr2->data && ptr1 != ptr2)//checks if data is same but Node is not.
			{
				ptr2 = ptr2->next;
				erase(index);
			}
			else
			{
				ptr2 = ptr2->next;
				index++;
			}
		}
			ptr1 = ptr1->next;
	}
}