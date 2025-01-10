#include "gtest/gtest.h"
#include "../../src/matrices/v_matrix_char.h"
// #include <iostream>


class VMatrixChar {};
TEST(VMatrixChar, Container_created_by_default_constructor_is_empty) {
	const v_matrix_char cut;
	EXPECT_TRUE(cut.data().empty());
}
TEST(VMatrixChar, Container_created_by_default_constructor_can_be_compared_with_empty_stl_container) {
	const v_matrix_char cut;
	EXPECT_EQ(cut.data(), std::vector<std::vector<char>>());
}


class Constructor_SizeT : public ::testing::TestWithParam<size_t> {};
TEST_P(Constructor_SizeT, Containers_size_matches_given_parameters) {
    const auto sizeValue = GetParam();
    const v_matrix_char cut(sizeValue);
    const auto& data = cut.data();
    EXPECT_EQ(data.empty(), sizeValue == 0);
    EXPECT_EQ(data.size(), sizeValue);
}
TEST_P(Constructor_SizeT, All_rows_have_the_same_size_equal_given_parameters) {
    const auto sizeValue = GetParam();
    const v_matrix_char cut(sizeValue);
    const auto& data = cut.data();
	for (const auto& row : data) {
    	EXPECT_FALSE(data.empty());
    	EXPECT_EQ(data.size(), sizeValue);
	}
}
TEST_P(Constructor_SizeT, All_elements_has_default_char_value) {
    const auto sizeValue = GetParam();
    const v_matrix_char cut(sizeValue);
    const auto& data = cut.data();
	const char defaultValue = char();
	for (const auto& row : data) {
		for (const auto value : row) {
    		EXPECT_EQ(value, defaultValue);
		}
	}
}
INSTANTIATE_TEST_SUITE_P(SimpleSizeValues, Constructor_SizeT,
    ::testing::Values(0, 1, 2, 3, 4, 5, 6, 99, 100, 999, 1000)
);







// class SizeParametersForConstructor : public ::testing::TestWithParam<std::tuple<size_t, size_t>> {};
// TEST_P(SizeParametersForConstructorZ, SquareSizeConstructor) {
// 	const auto width = std::get<0>(GetParam());
// 	const auto height = std::get<1>(GetParam());

//     const v_matrix_char cut(width, height);
//     const auto& data = cut.data();
//     EXPECT_EQ(data.empty(), height == 0);
//     EXPECT_EQ(data.size(), height);

// 	const char defaultValue = char();
// 	for (const auto& row : data) {
//     	EXPECT_EQ(data.size(), width);
// 		for (const auto value : row) {
//     		EXPECT_EQ(value, defaultValue);
// 		}
// 	}
// }
// INSTANTIATE_TEST_SUITE_P(
//     SimpleValuesWidthHeight,
//     WidthAndHeightParametersForConstructor,
//     ::testing::Values(
//         std::make_tuple(1, 2),
//         std::make_tuple(3, 4),
//         std::make_tuple(5, 6)
//     )
// );

// INSTANTIATE_TEST_SUITE_P(SimpleValuesWidthHeight, WidthAndHeightParametersForConstructor,
//     // ::testing::Values(0, 1, 2, 3, 4, 5, 6, 99, 100, 999, 1000)
//     ::testing::Values(		
//         std::make_tuple(0, 0),
//         std::make_tuple(1, 1),
//         std::make_tuple(2, 2),
//         std::make_tuple(3, 3),
//         std::make_tuple(4, 4),

//         std::make_tuple(5, 5),
//         std::make_tuple(6, 6),
//         std::make_tuple(99, 99),
//         std::make_tuple(100, 100),
//         std::make_tuple(999, 999),
//         std::make_tuple(1000, 1000)
// 	)
// );











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



// class AAAAA : public ::testing::TestWithParam<size_t> {};
// TEST_P(BBBBB, CCCCCC) {
// 	// ...
// }
// INSTANTIATE_TEST_SUITE_P(CCCCCC, DDDDDDD,
//     ::testing::Values(...)
// );