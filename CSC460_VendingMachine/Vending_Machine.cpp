//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdlib.h>
using namespace std;

class InventoryChange {
private:
	int quarterQuantity = 40;
public:
	InventoryChange();
	//void QuarterQuantitySet(int inputQuarterQuantity);
	int QuarterQuantityGet();
	void QuarterQuantityDecrement();
	void QuarterQuantityIncrement();
};

//For initializing inventory array


class InventoryTotals {
private:
	string inventoryItemName;
	double inventoryItemPrice;
	int inventoryItemQuantity;

public:

	InventoryTotals();

	void ItemNameSet(string inputInventoryItemName);
	string ItemNameGet();
	void ItemPriceSet(double inputInventoryItemPrice);
	double ItemPriceGet();
	void ItemQuantitySet(int inputInventoryItemQuantity);
	int ItemQuantityGet();
	void ItemQuantityDecrement();

	//int size();
	//int getListElement(int index);




};

#pragma region FunctionDef
void InventoryTotals::ItemNameSet(string inputInventoryItemName) {
	inventoryItemName = inputInventoryItemName;
}
string InventoryTotals::ItemNameGet() {
	return inventoryItemName;
}
void InventoryTotals::ItemPriceSet(double inputInventoryItemPrice) {
	inventoryItemPrice = inputInventoryItemPrice;
}
double InventoryTotals::ItemPriceGet() {
	return inventoryItemPrice;
}
void InventoryTotals::ItemQuantitySet(int inputInventoryItemQuantity) {
	inventoryItemQuantity = inputInventoryItemQuantity;
}
int InventoryTotals::ItemQuantityGet() {
	return inventoryItemQuantity;
}
void InventoryTotals::ItemQuantityDecrement() {
	inventoryItemQuantity--;
}


InventoryTotals::InventoryTotals() {

}

#pragma endregion  
//All definitions for the class

#pragma region InventoryChange Class

int InventoryChange::QuarterQuantityGet() {
	return quarterQuantity;
}
void InventoryChange::QuarterQuantityDecrement() {
	quarterQuantity--;
}
void InventoryChange::QuarterQuantityIncrement() {
	quarterQuantity++;
}
InventoryChange::InventoryChange() {

}
#pragma endregion

//change initialization
InventoryChange changeInitialize() {
	InventoryChange startingChangeInventory;
	return startingChangeInventory;
}

//this menu adds money to the user's wallet
void moneyEntryMenu(double &money) {
	int entry = 0;
	int numQuarters = 0;
	cout << "\n\n\n"
		<< "==========Please enter money!==========" << endl;
	cout << "1) $0.25 \n2) $1.00 \n3) $5.00 \n4) Exit" << endl;
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> entry;
	while (entry < 1 || entry>4 || cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "You have made an invalid selection. Please try again." << endl;
		cin >> entry;
	}

	if (entry == 1) {
		cout << "You must enter at least 4 quarters to proceed. How many quarters would you like to enter?" << endl;
		cin >> numQuarters;
		while (numQuarters < 4 || numQuarters>20||cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "You have entered an invalid number of quarters. Please try again." << endl;
			cin >> numQuarters;
		}
		money += (0.25)*numQuarters;
	}
	else if (entry == 2) {
		money += 1.00;
	}
	else if (entry == 3) {
		money += 5.00;
	}
	else {
		cout << "Goodbye..." << endl;
		exit(0);
	}
}



//this menu receives the amount the user has input
//this also runs through the array of InventoryTotals objects instead of manually printing out fixed data
//the loop step-to # can be changed obviously to a less hard-coded number
void selectionMenu(double &amt, InventoryTotals inv[]) {
	cout << "You have $" << amt << endl;
	cout << "Please make a selection" << endl;
	for (int x = 0; x < 7; x++) {
		cout << (x + 1) << ") " << inv[x].ItemNameGet() << " - $" << inv[x].ItemPriceGet() << endl;
	}
	cout << "\n[Your Selection]->";



}

//this performs the analysis of the vending machine selection
//the while loop in main() will handle the '0' value
int getSelectionChoice(double &amt) {
	int snackSelection;
	cin >> snackSelection;
	while (snackSelection < 1 || snackSelection>8 || cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "You have entered an invalid choice. Please try again." << endl;
		cin >> snackSelection;
	}
	if (snackSelection < 1 || snackSelection>8) {
		return 0;
	}
	return snackSelection;

}
//don't know wtf this is about
double calculateChange(double &totalMoney, double itemCost, InventoryChange &totalChange) {
	double change = 0;
	int howManyQuarters = 0;
	change = totalMoney - itemCost;
	if (change < 0) {
		cout << "Sorry, you do not have enough money for this purchase\n"
			<< "Please make another selection" << endl;
		//show the menu again
		return totalMoney;
	}
	else {
		howManyQuarters = change / .25;
		cout <<howManyQuarters<<" quarters." << endl;
		if (howManyQuarters > totalChange.QuarterQuantityGet()) {
			cout << "Sorry, this machine is out of quarters. Your change is $" << totalMoney << ". Please come back later. Goodbye." << endl;
			system("pause");

			exit(0);
		}
		for (int i = 0; i < howManyQuarters; i++) {
			totalChange.QuarterQuantityDecrement();
		}
		return change;
	}
}

int main() {
	//exit variable
	bool readyToExit = false;
#pragma region initializeInventoryStock
	InventoryTotals startingInventoryStock[7];
	startingInventoryStock[0].ItemNameSet("Water");
	startingInventoryStock[0].ItemPriceSet(1.00);
	startingInventoryStock[0].ItemQuantitySet(10);
	startingInventoryStock[1].ItemNameSet("Sun Drop");
	startingInventoryStock[1].ItemPriceSet(1.00);
	startingInventoryStock[1].ItemQuantitySet(10);
	startingInventoryStock[2].ItemNameSet("Coca Cola");
	startingInventoryStock[2].ItemPriceSet(1.00);
	startingInventoryStock[2].ItemQuantitySet(10);
	startingInventoryStock[3].ItemNameSet("Zima");
	startingInventoryStock[3].ItemPriceSet(1.00);
	startingInventoryStock[3].ItemQuantitySet(10);
	startingInventoryStock[4].ItemNameSet("Peanut Butter Crackers");
	startingInventoryStock[4].ItemPriceSet(1.25);
	startingInventoryStock[4].ItemQuantitySet(10);
	startingInventoryStock[5].ItemNameSet("Chips");
	startingInventoryStock[5].ItemPriceSet(1.25);
	startingInventoryStock[5].ItemQuantitySet(10);
	startingInventoryStock[6].ItemNameSet("Pickled Eggs");
	startingInventoryStock[6].ItemPriceSet(1.25);
	startingInventoryStock[6].ItemQuantitySet(10);
#pragma endregion
#pragma region variableDeclaration

	InventoryChange changeStartingAmount = changeInitialize();


#pragma endregion
	// run through this process of grabbing money and resetting variables until...
	// readyToExit becomes true (which is done in the if-statement below)

	while (readyToExit == false) {

		double moneyEntryTotal = 0, currentSelectionCost = 0, changeToReturn = 0;

		moneyEntryMenu(moneyEntryTotal);
		//set the choice of snack via the getSelectionChoice function
	menu:selectionMenu(moneyEntryTotal, startingInventoryStock);

		int choiceOfSnack = getSelectionChoice(moneyEntryTotal);






#pragma region SnackChoiceSwitch
		//this block of if-else replaces the ENTIRE switch block that was here before
		// choiceOfSnack-1 is the index used to access the InventoryTotals[] array objects
		if (choiceOfSnack > 0 && choiceOfSnack < 8) {

			cout << "You have selected " << startingInventoryStock[choiceOfSnack - 1].ItemNameGet() << ". That will be $" << startingInventoryStock[choiceOfSnack - 1].ItemPriceGet() << "." << endl;
			currentSelectionCost = startingInventoryStock[choiceOfSnack - 1].ItemPriceGet();
			if (currentSelectionCost > moneyEntryTotal) {
				cout << "===SORRY, YOU DO NOT HAVE ENOUGH MONEY FOR THIS===" << endl;

			}
			else if (startingInventoryStock[choiceOfSnack - 1].ItemQuantityGet() < 1) {
				cout << "Sorry, this item is out of stock. Please choose again." << endl;
				goto menu;
				/*system("pause");
				exit(0);*/
			}
			else {
				startingInventoryStock[choiceOfSnack - 1].ItemQuantityDecrement();
				changeToReturn = calculateChange(moneyEntryTotal, currentSelectionCost, changeStartingAmount);
				double change = moneyEntryTotal - currentSelectionCost;
				moneyEntryTotal -= currentSelectionCost;
				cout << "Your change is $" << change << ". Thank you." << endl;
			}

		}
		else if (choiceOfSnack == 8) {
			cout << "Goodbye!";
			system("pause");
			readyToExit = true;

		}

		else {
			cout << "===Invalid Selection Sir===" << endl << "Please try again" << endl;

		}
	}
	system("pause");


}