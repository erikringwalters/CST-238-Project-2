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
	cout << " \nDisplaying second list: \n";
	z.display(cout);
	cout << endl;
	y.append(z);
	cout << "Displaying appended list: \n";
	y.display(cout);
	cout << endl;
	cout << "counting the number zero in appended list: \n";
	cout << y.count(0) << endl;
	cout << "Constructing new list 'd'...\n";
	LinkedList d;
	for (int i = 0; i < 10; i++)
	{
		d.insert(i / 2, i);
	}
	cout << "Displaying list 'd':  \n";
	d.display(cout);
	cout << "Deleting duplicates of list 'd': \n";
	d.duplicates();
}