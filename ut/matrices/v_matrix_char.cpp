#include "gtest/gtest.h"
#include "../../src/matrices/v_matrix_char.h"
// #include <iostream>

// ClassUnderTest
using CUT = v_matrix_char;


/// CUT()
class VMatrixChar {};
TEST(VMatrixChar, Container_created_by_default_constructor_is_empty) {
	const CUT cut;
	EXPECT_TRUE(cut.data().empty());
}
TEST(VMatrixChar, Container_created_by_default_constructor_can_be_compared_with_empty_stl_container) {
	const CUT cut;
	EXPECT_EQ(cut.data(), std::vector<std::vector<char>>());
}


/// CUT(const size_t)
class Constructor_SizeT : public ::testing::TestWithParam<size_t> {};
TEST_P(Constructor_SizeT, Container_height_matches_given_parameter) {
    const CUT cut(GetParam());
    EXPECT_EQ(cut.data().empty(), GetParam() == 0);
    EXPECT_EQ(cut.data().size(), GetParam());
}
TEST_P(Constructor_SizeT, Container_width_matches_given_parameter) {
    const CUT cut(GetParam());
	for (const auto& row : cut.data()) {
    	EXPECT_FALSE(row.empty());
    	EXPECT_EQ(row.size(), GetParam());
	}
}
TEST_P(Constructor_SizeT, All_elements_has_default_char_value) {
    const CUT cut(GetParam());
	const char defaultValue = char();
	for (const auto& row : cut.data()) {
		for (const auto value : row) {
    		EXPECT_EQ(value, defaultValue);
		}
	}
}
INSTANTIATE_TEST_SUITE_P(SimpleSizeValues, Constructor_SizeT,
    ::testing::Values(0, 1, 2, 3, 4, 5, 6, 99, 100, 999, 1000)
);


/// CUT(const size_t, const char)
class Constructor_SizeT_Char : public ::testing::TestWithParam<std::tuple<size_t, char>> {};
TEST_P(Constructor_SizeT_Char, Container_height_matches_given_parameter) {
	const auto pSize = std::get<0>(GetParam());
	const auto pValue = std::get<1>(GetParam());
    const CUT cut(pSize, pValue);
    EXPECT_EQ(cut.data().empty(), pSize == 0);
    EXPECT_EQ(cut.data().size(), pSize);
}
TEST_P(Constructor_SizeT_Char, Container_width_matches_given_parameter) {
	const auto pSize = std::get<0>(GetParam());
	const auto pValue = std::get<1>(GetParam());
    const CUT cut(pSize, pValue);
	for (const auto& row : cut.data()) {
    	EXPECT_EQ(row.empty(), pSize == 0);
    	EXPECT_EQ(row.size(), pSize);
	}
}
TEST_P(Constructor_SizeT_Char, All_elements_has_matching_char_value) {
	const auto pSize = std::get<0>(GetParam());
	const auto pValue = std::get<1>(GetParam());
    const CUT cut(pSize, pValue);
	for (const auto& row : cut.data()) {
		for (const auto value : row) {
    		EXPECT_EQ(value, pValue);
		}
	}
}
namespace __Constructor_SizeT_Char {
	const std::vector<size_t> sizeValues = {0, 1, 2, 3, 999};
	const std::vector<char> simpleValues = {'a', 'b', 'c', 'd', '0', '1', '9', '!', '@', '#', '$', ' ', '\t', '\n'};
	const std::vector<char> edgeValues = {-128, -1, 0, 1, 2, 27, 127, std::numeric_limits<char>::min(), std::numeric_limits<char>::max()};
}
INSTANTIATE_TEST_SUITE_P(SimpleValues, Constructor_SizeT_Char, 
    ::testing::Combine(
        ::testing::ValuesIn(__Constructor_SizeT_Char::sizeValues),
        ::testing::ValuesIn(__Constructor_SizeT_Char::simpleValues)
    )
);
INSTANTIATE_TEST_SUITE_P(EdgeValues, Constructor_SizeT_Char, 
    ::testing::Combine(
        ::testing::ValuesIn(__Constructor_SizeT_Char::sizeValues),
        ::testing::ValuesIn(__Constructor_SizeT_Char::edgeValues)
    )
);


/// CUT(const size_t, const size_t)
class Constructor_SizeT_SizeT : public ::testing::TestWithParam<std::tuple<size_t, size_t>> {};
TEST_P(Constructor_SizeT_SizeT, Container_height_matches_given_parameter) {
	const auto pHeight = std::get<0>(GetParam());
	const auto pWidth = std::get<1>(GetParam());
    const CUT cut(pHeight, pWidth);
    EXPECT_EQ(cut.data().empty(), pHeight == 0);
    EXPECT_EQ(cut.data().size(), pHeight);
}
TEST_P(Constructor_SizeT_SizeT, Container_width_matches_given_parameter) {
	const auto pHeight = std::get<0>(GetParam());
	const auto pWidth = std::get<1>(GetParam());
    const CUT cut(pHeight, pWidth);
	for (const auto& row : cut.data()) {
    	EXPECT_EQ(row.empty(), pWidth == 0);
    	EXPECT_EQ(row.size(), pWidth);
	}
}
TEST_P(Constructor_SizeT_SizeT, All_elements_has_default_char_value) {
	const auto pHeight = std::get<0>(GetParam());
	const auto pWidth = std::get<1>(GetParam());
    const CUT cut(pHeight, pWidth);
	const char defaultValue = char();
	for (const auto& row : cut.data()) {
		for (const auto value : row) {
    		EXPECT_EQ(value, defaultValue);
		}
	}
}
namespace __Constructor_SizeT_SizeT {
	const std::vector<size_t> values = {0, 1, 2, 3, 4, 5, 6, 99, 100, 999, 1000};
}
INSTANTIATE_TEST_SUITE_P(SimpleSizeValues, Constructor_SizeT_SizeT, 
    ::testing::Combine(
        ::testing::ValuesIn(__Constructor_SizeT_SizeT::values),
        ::testing::ValuesIn(__Constructor_SizeT_SizeT::values)
    )
);





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