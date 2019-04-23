// LinkedList3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

	struct item
	{
		int data = 0;
		item *nextitem;
	};

	item* firstitem = NULL; // list starts empty

	item* getnewitem(int datain) // Adds new item to front of list
	{
		item *newitem = new item;
		newitem->nextitem = firstitem;
		firstitem = newitem;
		newitem->data = datain;
		return newitem;
	}

	void readlist()
	{
		item *p_current = firstitem;

		std::cout << "Reading out the list.\n";

		while (p_current != NULL)
		{
			std::cout << p_current->data;
			std::cout << " ";
			p_current = p_current->nextitem;
		}

		std::cout << "\n";
	}

	void reverse()
	{
		// Initialize current, previous and 
		// next pointers 
		item *p_current = firstitem;
		item *previous = NULL, *nextitem = NULL;


		while (p_current != NULL)
		{
			// Store next item
			nextitem = p_current->nextitem;

			// Reverse current node's pointer 
			p_current->nextitem = previous;

			// Move pointers. 
			previous = p_current;
			p_current = nextitem;
		}
		firstitem = previous;
	}

	

int main()
{
	// Create a singly-linked list of the first 5 prime numbers in order.
	getnewitem(11);
	getnewitem(7);
	getnewitem(5);
	getnewitem(3);
	getnewitem(2);

	readlist();

	reverse();

	// Print the list in reversed order.
	readlist();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
