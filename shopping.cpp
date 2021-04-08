/*
* Enigma Swan Adams
* CS201-HW6
* 4/7/21
*
* Additional program 2 as described in the homework assignment on blackbuard
* calling the function shopping() from main runs the full Additional 2 program
*
*/

#include "shopping.h"
#include <iostream>
#include<map>
#include <string>

using std::string;
using std::map;


void shopping() {

	//create Recors struct for possible items to buy
	struct Record {
		double unitPrice;
		int units;
	};

	//declare the available items an store them in a map
	Record cup{ 4.99, 10 };
	Record banana{ 1.50, 12};
	Record happiness{ 1999.99, 1};
	Record pencil{ 0.25, 25};
	Record housePlant{ 11.95, 5};
	Record rice{ 5.95, 7};
	
	map<string, Record> shelves = {
		{"cup", cup},
		{"banana", banana},
		{":)", happiness},
		{ "pencil", pencil},
		{"housePlant", housePlant},
		{"rice", rice}
	};

	//making the empty shopping cart
	map <string, Record> cart;

	//function to let them remove things form the cart 
	void removeItem(map<string, Record>& cart) {

	}
	//function to let them add things to the cart

	
}

