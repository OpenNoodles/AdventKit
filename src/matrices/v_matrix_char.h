#pragma once

#include <vector>
#include <string>
#include <cassert>

template<typename> class Walker;
template<typename> class VMatrix;
template<> class Walker<VMatrix<char>>;
	

class v_matrix_char {
	std::vector<std::vector<char>> _data;

public:
	/// Member functions
	v_matrix_char();
		// explicit vector( size_type count);
		// explicit vector( size_type count, const T& value = T());

		// template< class InputIt >
		// vector( InputIt first, InputIt last);

		// template< container-compatible-range<T> R >
		// constexpr vector( std::from_range_t, R&& rg);

		// vector( const vector& other );
		// vector( vector&& other );
		// vector( const vector& other);
		// constexpr vector( const vector& other);
		
		// vector( vector&& other);
		// constexpr vector( vector&& other);
		// vector( std::initializer_list<T> init);
	~v_matrix_char();
	// operator=		assigns values to the container		(public member function)
	// assign			assigns values to the container		(public member function)
	// assign_range	(C++23)	assigns a range of values to the container		(public member function)
	// get_allocator	returns the associated allocator	(public member function)



	/// Element access
	void show() const;
	char value(const size_t x, const size_t y) const;
	char& value(const size_t x, const size_t y);
	const std::vector<std::vector<char>>& data() const;
	std::vector<std::vector<char>>& data();
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
};
