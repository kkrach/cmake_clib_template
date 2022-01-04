
#include "gtest/gtest.h"

extern "C" {
#include "library.h"
}

TEST(library, initial_value) {
	ASSERT_EQ(get_answer(), 42);
}

TEST(library, positive_value) {
	set_answer(123);
	ASSERT_EQ(get_answer(), 123);
}

TEST(library, zero_value) {
	set_answer(0);
	ASSERT_EQ(get_answer(), 0);
}

TEST(library, negative_value) {
	set_answer(-123);
	ASSERT_EQ(get_answer(), -123);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
