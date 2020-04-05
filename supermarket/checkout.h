#pragma once
#include <map>
#include <string>
class Checkout
{
public:
	Checkout();
	void addItemPrice(std::string lItem, int lPrice);
	void addItem(std::string lItem);
	void addDiscount(std::string, int numberOfItems, int discountPrice);
	int calculateTotall();
	void calculateItem(std::string itemName, int numberOfItem);

private:

	struct Discount {
		int numberOfItems;
		int discountPrice;
	};
	std::map<std::string, int> prices;
	std::map<std::string, Discount> discounts;
	std::map<std::string, int> items;
	void calculateDiscount(std::string itemName, int numberOfItem, Discount lDiscount);

	int total;
};