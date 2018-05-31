#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <stdlib.h>
//#include "VendingMachine.h"
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

	int size();
	int getListElement(int index);




};

void moneyEntryMenu();

//***************I DON'T KNOW IF I NEED THIS OR NOT. EVALUATE******************************

//class InventoryItem {
//private:
//	string itemName;
//	double itemPrice;
//public:
//	InventoryItem();
//
//	void ItemNameSet(string inputItemName);
//	string ItemNameGet();
//	void ItemPriceSet(double inputItemPrice);
//	double ItemPriceGet();
//
//};

//InventoryItem::InventoryItem() {
//}
//
//
//void InventoryItem::ItemNameSet(string inputInventoryItemName) {
//	itemName = inputInventoryItemName;
//}
//string InventoryItem::ItemNameGet() {
//	return itemName;
//}
//void InventoryItem::ItemPriceSet(double inputItemPrice) {
//	itemPrice = inputItemPrice;
//}
//double InventoryItem::ItemPriceGet() {
//	return itemPrice;
//}
