#include "pch.h"
#include "../supermarket/checkout.h"
#include "../supermarket/checkout.cpp"

class CheckoutTests :public ::testing::Test {

public:


protected:

	Checkout checkOut;
};

TEST_F(CheckoutTests, canCalculateCurrentTotall) {

	checkOut.addItemPrice("a", 1);
	checkOut.addItem("a");
	int totall = checkOut.calculateTotall();
	ASSERT_EQ(1, totall);
}

TEST_F(CheckoutTests, canGetTotallForMultipleItem) {

	checkOut.addItemPrice("a", 1);
	checkOut.addItemPrice("b", 2);
	checkOut.addItem("a");
	checkOut.addItem("b");
	int totall = checkOut.calculateTotall();
	ASSERT_EQ(3, totall);
}

TEST_F(CheckoutTests, canAddDiscount) {

	checkOut.addDiscount("a", 3, 2);
}

TEST_F(CheckoutTests, canCalculateTotalWithDiscount) {

	checkOut.addItemPrice("a", 1);
	checkOut.addDiscount("a", 3, 2);
	checkOut.addItem("a");
	checkOut.addItem("a");
	checkOut.addItem("a");
	checkOut.addItem("a");
	checkOut.addItem("a");
	int total = checkOut.calculateTotall();
	ASSERT_EQ(4, total);
}

TEST_F(CheckoutTests, canExceptionWithoutPrice) {

	ASSERT_THROW(checkOut.addItem("a"), std::invalid_argument);
}