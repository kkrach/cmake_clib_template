/**
 * @file answer.cpp
 *
 * @brief Unit tests for answers
 *
 * @author Karl Krach
 *
 * @copyright Copyright 2021 Karl Krach
 * @license{This file is licensed under the MIT license.}
 *
 */

#include <gtest/gtest.h>
#include <climits>

extern "C" {
#include "library.h"
}

// Warning: This only works at the very start - shall be avoided without setup()/reset!
TEST(library, initial) {
	EXPECT_EQ(clib_get_answer(), 42);
}

TEST(library, positive) {
	clib_set_answer(1);
	EXPECT_EQ(clib_get_answer(), 1);

	clib_set_answer(123);
	EXPECT_EQ(clib_get_answer(), 123);

	clib_set_answer(INT_MAX);
	EXPECT_EQ(clib_get_answer(), INT_MAX);
}

TEST(library, zero) {
	clib_set_answer(0);
	EXPECT_EQ(clib_get_answer(), 0);
}

TEST(library, negative) {
	clib_set_answer(-1);
	EXPECT_EQ(clib_get_answer(), -1);

	clib_set_answer(-123);
	EXPECT_EQ(clib_get_answer(), -123);

	clib_set_answer(INT_MIN);
	EXPECT_EQ(clib_get_answer(), INT_MIN);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
