
#include "gtest/gtest.h"

extern "C" {
#include "library.h"
}

TEST(library, version) {
	ASSERT_EQ(get_version(), 1);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
