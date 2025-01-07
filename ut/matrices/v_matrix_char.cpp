#include "gtest/gtest.h"
#include "../../src/matrices/v_matrix_char.h"

TEST(v_matrix_char, DefaultConstructor) {
	v_matrix_char cut;
	EXPECT_TRUE(cut.data().empty());
	EXPECT_EQ(cut.data(), std::vector<std::vector<char>>());
}



