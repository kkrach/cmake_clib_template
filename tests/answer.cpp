
#include <gtest/gtest.h>
#include <climits>

extern "C" {
#include "library.h"
}

// Warning: This only works at the very start - shall be avoided without setup()/reset!
TEST(library, initial) {
	EXPECT_EQ(get_answer(), 42);
}

TEST(library, positive) {
	set_answer(1);
	EXPECT_EQ(get_answer(), 1);

	set_answer(123);
	EXPECT_EQ(get_answer(), 123);

	set_answer(INT_MAX);
	EXPECT_EQ(get_answer(), INT_MAX);
}

TEST(library, zero) {
	set_answer(0);
	EXPECT_EQ(get_answer(), 0);
}

TEST(library, negative) {
	set_answer(-1);
	EXPECT_EQ(get_answer(), -1);

	set_answer(-123);
	EXPECT_EQ(get_answer(), -123);

	set_answer(INT_MIN);
	EXPECT_EQ(get_answer(), INT_MIN);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
