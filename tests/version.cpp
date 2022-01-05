
#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include "library.h"
}

using ::testing::MatchesRegex;

static const char* DATE_REGEX = "^[0-9]{4}-[0-9]{2}-[0-9]{2} [0-9]{2}:[0-9]{2}:[0-9]{2}.*";
static const char* GITREPO_REGEX = "^git@.*";
static const char* PATH_REGEX = "^/.*";


TEST(library, print_version) {
	// smoke test
	print_version();
}

TEST(library, project_name) {
	EXPECT_STREQ(get_project_name(), "clib_template");
}

TEST(library, git_source_version)
{
	EXPECT_STRNE(get_git_source_version(), "");
}

TEST(library, git_source_date)
{
	EXPECT_THAT(get_git_source_date(), MatchesRegex(DATE_REGEX));
}

TEST(library, git_repository)
{
	EXPECT_THAT(get_git_repository(), MatchesRegex(GITREPO_REGEX));
}

TEST(library, compile_host)
{
	EXPECT_STRNE(get_compile_host(), "");
}

TEST(library, compile_date)
{
	EXPECT_THAT(get_compile_date(), MatchesRegex(DATE_REGEX));
}

TEST(library, compile_user)
{
	EXPECT_STRNE(get_compile_user(), "");
}

TEST(library, compile_source)
{
	EXPECT_THAT(get_compile_source(), MatchesRegex(PATH_REGEX));
}

TEST(library, compile_dir)
{
	EXPECT_THAT(get_compile_dir(), MatchesRegex(PATH_REGEX));
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
