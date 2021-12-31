#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <ctime>
#include "BigNumber.h"
#include "Calandar.h"
#include <iostream>

using namespace std;


TEST(BigNumberTest, mult) {
  	BigNumber a(124);
	BigNumber b(456);
	BigNumber out1 = a.multiply(b);
	ASSERT_TRUE(out1.number() == "56544");

	BigNumber c("734");
	BigNumber d(432);
	BigNumber out2 = c.multiply(d);
	ASSERT_TRUE(out2.number() == "317088");

}

TEST(BigNumberTest, overflow) {
 	BigNumber e(2);
	BigNumber f("111111111111111111111");
	BigNumber out3 = e.multiply(f);
	ASSERT_TRUE(out3.number() == "222222222222222222222");


	BigNumber g("12345678900");
	BigNumber h("12345678900");
	BigNumber out4 = g.multiply(h);
	ASSERT_TRUE(out4.number() == "152415787501905210000");

}

TEST(CalandarTest, cal) {
	ASSERT_TRUE(1 == 1);

}