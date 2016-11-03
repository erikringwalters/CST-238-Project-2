//Erik Ring-Walters
//October 28, 2016
//CST 238 Data Structures
//Project 2
//Linked List Project
//ID: 002488407
#include "LinkedList.h"
void main()
{
	LinkedList y;
	LinkedList z;
	for (int i = 0; i < 10; i++)
	{
		y.insert(i, i);
	}
	for (int i = 0; i < 10; i++)
	{
		z.insert(i*10, i);
	}
	cout << "Displaying first list: \n";
	y.display(cout);
	cout << " \n Displaying second list: \n";
	z.display(cout);
	y.append(z);
}