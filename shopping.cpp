/*
* Enigma Swan Adams
* CS201-HW6
* 4/7/21
*
* Additional program 2 as described in the homework assignment on blackbuard
* 
*
*/

#include "shopping.h"
#include <iostream>
#include<map>
#include <string>
#include<algorithm>
#include<iterator>
#include <numeric>
#include <vector>


using std::string;
using std::map;
using std::cout; using std::endl; using std::cin;
using std::end; using std::begin;
using std::accumulate;
using std::pair;
using std::vector;


//create Record struct for possible items to buy
	struct Record {
		double unitPrice;
		int units;
	};

int main() { 

	//declare the available items an store them in a map
	Record cup{ 4.99, 10 };
	Record banana{ 1.50, 12 };
	Record happiness{ 1999.99, 1 };
	Record pencil{ 0.25, 25 };
	Record plants{ 11.95, 5 };
	Record tablets{ 259.99, 7 };

	map<string, Record> shelves = {
		{"cups", cup},
		{"bananas", banana},
		{"happiness", happiness},
		{ "pencils", pencil},
		{"plants", plants},
		{"tablets", tablets}
	};

	
	//making the empty shopping cart
	map <string, Record> cart;
	cart = shelves;
	cart["cups"].units = 0;
	cart["bananas"].units = 0;
	cart["happiness"].units = 0;
	cart["pencils"].units = 0;
	cart["plants"].units = 0;
	cart["tablets"].units = 0;

	
	//prompt user
	cout << "You have arived at the happy healthy grociery store. \n"
		"Currently we have " << shelves.size() << " items. \n"
		"We have: " << endl;;
	for (const auto p: shelves) {
		cout <<p.second.units <<" " << p.first << " at $" << p.second.unitPrice <<  endl;
	}
	cout << endl;
	cout << "Right now your cart is empty." << endl;
	

	while (true) {
		string desire;
		double cost = 0.0; 
		//cost = accumulate(cart.end(), cart.begin(), 0.0, [](double acc, pair<string, Record> c) {return (acc + c.second.unitPrice*c.second.unit); });
		//couldn't figure out how to ge the above line to work, so I very cheetingly will be placing all
		//the prices in a vector and then using accumulate on it
		vector<double> pricesPerItem;
		for (const auto p : cart) {
			if (p.second.units > 0) {
				pricesPerItem.push_back(p.second.unitPrice * p.second.units);
			}
		}

		cost = accumulate(pricesPerItem.begin(), pricesPerItem.end(), 0.00);

		cout << "Would you like to add or remove something from your cart? Or are you done shopping \n"
			"Type \"add\", \"remove\" , or \"done\" ";
		cin >> desire;
		std::transform(desire.begin(), desire.end(), desire.begin(), tolower);


		//if they are done shopping we check them out
		if (desire == "done") {
			if (cost == 0) {
				cout << "Thanks for visiting us. Come again!" << endl;
				return 0;
			}

			else {
				cout << "Would you like to buy what is currently in your cart? ";

				//let them know what they bought
				cout << "In your cart you have: " << endl;
				for (const auto p : cart) {
					if (p.second.units > 0) {
						cout << p.second.units << " " << p.first << endl;
					}
				}

				//let them know a total price
				cout << "Your total is " << cost << endl;

					double payment;
					cout << "how much do money do you hand us? ";
					cin >> payment;
					if (payment - cost < 0) {
						cout << "thats not enough money" << endl;
					}
					else {
						cout << "You change is " << payment - cost << ". Thank you for shopping with us" << endl;
						return 0;
					}
				}
			}
		
		// if they are not done shopping we let them add or remove items from the cart
		else {
				// add however many of a certain item they want
				if (desire == "add") {
					string key;
					int amount;
					cout << "What would you like to add? ";
					cin >> key;
					std::transform(key.begin(), key.end(), key.begin(), tolower);
					cout << endl;
					cout << "How many would you like to add? ";
					cin >> amount;

					//if they ask for to many they get sent back to asking what they want to add or remove
					if (amount > shelves[key].units) {
						cout << "Sorry we don't have that item/quantity in stock. Try again. " << endl;
					}
					//otherwise add however many they wanted to the cart
					else {
						cart[key].units =  cart[key].units + amount;
						shelves[key].units = shelves[key].units - amount;
						cout << "Now You cart has: " << endl;
						for (const auto p : cart) {
							if (p.second.units > 0) {
								cout << p.second.units << " " << p.first << endl;
							}
						}
					}

				}

				// remove however many of an item they want
				else if (desire == "remove") {
					string key;
					int amount;
					cout << "What would you like to remove? ";
					cin >> key;
					std::transform(key.begin(), key.end(), key.begin(), tolower);
					cout << endl;
					cout << "How many would you like to remove? ";
					cin >> amount;

					//if they ask for to many I erase it from the cart
					if (amount >= cart[key].units) {
						cout << "Thats all of them or more, so you don't have that item anymore. " << endl;
						//amount = cart[key].units;
						cart[key].units = 0;
					}

					//otherwise I reduce the number of units int their cart
					else {
						cart[key].units = cart[key].units - amount;
						shelves[key].units = shelves[key].units + amount;
						cout << "Now You cart has: " << endl;
						for (const auto p : cart) {
							if (p.second.units > 0) {
								cout << p.second.units << " " << p.first << endl;
							}
						}
					}
					

				}

				else {
					cout << "Sorry I didn't understand, try again" << endl;
				}
		}

	}
	

}


