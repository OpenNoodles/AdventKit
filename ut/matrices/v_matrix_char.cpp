#include "gtest/gtest.h"
#include "../../src/matrices/v_matrix_char.h"
// #include <iostream>


TEST(v_matrix_char, DefaultConstructor) {
	const v_matrix_char cut;
	EXPECT_TRUE(cut.data().empty());
	EXPECT_EQ(cut.data(), std::vector<std::vector<char>>());
}

class SizeParametersForConstructor : public ::testing::TestWithParam<size_t> {};
TEST_P(SizeParametersForConstructor, SquareSizeConstructor) {
    const auto sizeValue = GetParam();
    const v_matrix_char cut(sizeValue);
    const auto& data = cut.data();
    EXPECT_EQ(data.empty(), sizeValue == 0);
    EXPECT_EQ(data.size(), sizeValue);

	const char defaultValue = char();
	for (const auto& row : data) {
    	EXPECT_EQ(data.size(), sizeValue);
		for (const auto value : row) {
    		EXPECT_EQ(value, defaultValue);
		}
	}
}
INSTANTIATE_TEST_SUITE_P(SimpleValues, SizeParametersForConstructor,
    ::testing::Values(0, 1, 2, 3, 4, 5, 6, 99, 100, 999, 1000)
);



// class SizeParametersForConstructor : public ::testing::TestWithParam<size_t> {
// protected:
//     v_matrix_char _cut;
//     const std::vector<std::vector<char>>& data;
//     const char defaultValue = char();

// 	static void SetUpTestSuite() {
// 		std::cerr << "hehehe 1\n";
// 	}

//     void SetUp() override {
// 		std::cerr << "hehehe 2\n";

//         _cut = v_matrix_char(GetParam());
//         data = cut.data();
//     }
// };

// TEST_P(SizeParametersForConstructor, SquareSizeConstructor) {
// 	const auto& sizeValue = GetParam();
//     EXPECT_EQ(data.empty(), sizeValue == 0);
//     EXPECT_EQ(data.size(), sizeValue);

//     for (const auto& row : data) {
//         EXPECT_EQ(data.size(), sizeValue);
//         for (const auto value : row) {
//             EXPECT_EQ(value, defaultValue);
//         }
//     }
// }

