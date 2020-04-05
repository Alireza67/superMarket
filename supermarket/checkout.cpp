#include "pch.h"
#include "checkout.h"

using namespace std;

Checkout::Checkout() :total(0) {

}

void Checkout::addItemPrice(string lItem, int lPrice) {

	prices[lItem] = lPrice;
}

void Checkout::addItem(string lItem) {

	items[lItem]++;
}

void Checkout::addDiscount(std::string item, int numberOfItems, int discountPrice) {
	Discount conditionDiscount;
	conditionDiscount.numberOfItems = numberOfItems;
	conditionDiscount.discountPrice = discountPrice;
	discounts[item] = conditionDiscount;
}

int Checkout::calculateTotall() {

	total = 0;

	for (std::map<string, int>::iterator itemIter = items.begin();
		itemIter != items.end(); itemIter++) {

		string itemName = itemIter->first;
		int numberOfItem = itemIter->second;
		calculateItem(itemName, numberOfItem);
	}
	return total;
}

void Checkout::calculateItem(std::string itemName, int numberOfItem) {
	std::map<string, Discount>::iterator findCase;
	findCase = discounts.find(itemName);

	if (findCase != discounts.end()) {
		Discount localCase = findCase->second;
		calculateDiscount(itemName, numberOfItem, localCase);
	}
	else {
		total += numberOfItem * prices[itemName];
	}
}

void Checkout::calculateDiscount(std::string itemName, int numberOfItem, Discount lDiscount) {
	
	if (numberOfItem >= lDiscount.numberOfItems) {
		int pack = numberOfItem / lDiscount.numberOfItems;
		total += pack * lDiscount.discountPrice;
		int reminder = numberOfItem % lDiscount.numberOfItems;
		total += reminder * prices[itemName];
	}
	else {
		total += numberOfItem * prices[itemName];
	}
}