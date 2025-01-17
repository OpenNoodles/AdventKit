#pragma once

#include <vector>
#include <string>
#include <cassert>

template<typename> class Walker;
template<typename> class VMatrix;
template<> class Walker<VMatrix<char>>;
	

class v_matrix_char {
	using DataType = std::vector<std::vector<char>>;
	DataType _data;

public:
	/// Member functions
	v_matrix_char();																// empty container
	v_matrix_char(const size_t size);												// square container with default values
	v_matrix_char(const size_t size, const char value);								// square container with given value for all elements
	v_matrix_char(const size_t height, const size_t width);							// rectangle container with default values
	v_matrix_char(const size_t height, const size_t width, const char value);		// rectangle container with given value for all elements
	v_matrix_char(const std::initializer_list<char>& initRow);								// square from given values, row is duplicated 'n' times
	v_matrix_char(const std::initializer_list<char>& initRow, const size_t height);			// rectangle from given values, row is duplicated 'height' times
	v_matrix_char(const std::initializer_list<std::initializer_list<char>>& initMatrix);	// custom matrix, will throw if given rows with unequal size
	v_matrix_char(const v_matrix_char& copy);
	v_matrix_char(const v_matrix_char&& copy);
	v_matrix_char(const std::vector<std::vector<char>>& copy);
	v_matrix_char(const std::vector<std::vector<char>>&& copy);	

	~v_matrix_char();
	// operator=		assigns values to the container		(public member function)
	// assign			assigns values to the container		(public member function)
	// assign_range	(C++23)	assigns a range of values to the container		(public member function)
	// get_allocator	returns the associated allocator	(public member function)



	/// Element access
	void show() const;
	char value(const size_t x, const size_t y) const;
	char& value(const size_t x, const size_t y);
	const std::vector<std::vector<char>>& data() const;		// undefined behaviour when v_matrix_char removed
	std::vector<std::vector<char>>& data();					// undefined behaviour when v_matrix_char removed

	// at				access specified element with bounds checking		(public member function)
	// operator[]		access specified element							(public member function)
	// data				direct access to the underlying contiguous storage	(public member function)



	/// Slices
	std::string row(const size_t startX, const size_t y) const;
	std::string column(const size_t x, const size_t startY) const;
	std::string diagonalDown(size_t x, size_t y) const;
	std::string diagonalUp(size_t x, size_t y) const;

	std::vector<std::string> allRows() const;
	std::vector<std::string> allColumns() const;
	std::vector<std::string> allDiagonalsDown() const;
	std::vector<std::string> allDiagonalsUp() const;



	/// Iterators
	std::vector<std::vector<char>>::iterator begin();
	std::vector<std::vector<char>>::iterator end(); 
	std::vector<std::vector<char>>::const_iterator begin() const;
	std::vector<std::vector<char>>::const_iterator end() const;
	// begin / cbegin	 (C++11)		returns an iterator to the beginning	(public member function)
	// end / cend		 (C++11)		returns an iterator to the end			(public member function)
	// rbegin / crbegin (C++11)		returns a reverse iterator to the beginning	(public member function)
	// rend / crend	 (C++11)		returns a reverse iterator to the end		(public member function)



	/// Walkers
	Walker<VMatrix<char>> find(const char v, size_t x = 0, size_t y = 0);
	// Walker front			access the first element							(public member function)
	// Walker back			access the last element								(public member function)



	/// Capacity
	size_t width(const size_t y = 0) const;
	size_t height() const;
	void shrinkToFit();
	// empty		checks whether the container is empty			(public member function)
	// size			returns the number of elements					(public member function)
	// max_size		returns the maximum possible number of elements	(public member function)
	// reserve		reserves storage								(public member function)
	// capacity	returns the number of elements that can be held in currently allocated storage		(public member function)
	// shrink_to_fit	(DR*)	reduces memory usage by freeing unused memory						(public member function)



	/// Modifiers
	void pushRow(const std::vector<char>& row);
	// clear	clears the contents											(public member function)
	// insert	inserts elements											(public member function)
	// insert_range		(C++23)		inserts a range of elements				(public member function)
	// emplace			(C++11)		constructs element in-place				(public member function)
	// erase		erases elements											(public member function)
	// push_back	adds an element to the end								(public member function)
	// emplace_back		(C++11)		constructs an element in-place at the end	(public member function)
	// append_range		(C++23)		adds a range of elements to the end			(public member function)
	// pop_back		removes the last element								(public member function)
	// resize		changes the number of elements stored					(public member function)
	// swap			swaps the contents										(public member function)



	/// Non-member functions
	// operator==		(function template)
	// operator<=>		(C++20)
		// operator!=		(removed in C++20)
		// operator<		(removed in C++20)
		// operator<=		(removed in C++20)
		// operator>		(removed in C++20)
		// operator>=		(removed in C++20)
	// std::swap(std::vector)			specializes the std::swap algorithm					(function template)
	// erase(std::vector)		(C++20) erases all elements satisfying specific criteria	(function template)
	// erase_if(std::vector)	(C++20) erases all elements satisfying specific criteria	(function template)


private:
	DataType initData(const size_t height, const size_t width, const char value = char()) const;
	DataType initData(const v_matrix_char& copy) const;
	DataType initData(const std::initializer_list<char>& initRow, size_t height = 0) const;
};
