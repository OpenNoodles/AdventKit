#include "gtest/gtest.h"
#include "../../src/matrices/v_matrix_char.h"

TEST(v_matrix_char, DefaultConstructor) {
	const v_matrix_char cut;
	EXPECT_TRUE(cut.data().empty());
	EXPECT_EQ(cut.data(), std::vector<std::vector<char>>());
}

class SizeParametersForConstructor : public ::testing::TestWithParam<size_t> {};
TEST_P(SizeParametersForConstructor, SquareSizeConstructor) {
    const size_t size = GetParam();
	const char defaultValue = char();
    const v_matrix_char cut(size);
    const auto& data = cut.data();

    EXPECT_EQ(data.empty(), size == 0);
    EXPECT_EQ(data.size(), size);
	for (const auto& row : data) {
    	EXPECT_EQ(data.size(), size);
		for (const auto value : row) {
    		EXPECT_EQ(value, defaultValue);
		}
	}
}
INSTANTIATE_TEST_SUITE_P(SimpleValues, SizeParametersForConstructor,
    ::testing::Values(0, 1, 2, 3, 4, 5, 6, 99, 100, 999, 1000)
);
