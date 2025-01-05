#pragma once

#include "Coordinates.h"
#include "CartesianCoordinates.h"
#include <vector>
#include <array>
#include <cassert>
#include "Direction.h"

class Tile {
	CartesianCoordinates _local;

	std::array<Tile*, 4> _neighbours;
	// Tile* _up;
	// Tile* _down;
	// Tile* _left;
	// Tile* _right;

public:

	Tile():
		_local(0, 0),
		_neighbours({nullptr, nullptr, nullptr, nullptr})
	// 	_up(nullptr),
	// 	_down(nullptr),
	// 	_left(nullptr),
	// 	_right(nullptr),
	{}

	Tile(CartesianCoordinates local):
		_local(local),
		_neighbours({nullptr, nullptr, nullptr, nullptr})
	// 	_up(nullptr),
	// 	_down(nullptr),
	// 	_left(nullptr),
	// 	_right(nullptr),
	{}

    int localX() const {
        return _local.x();
    }

    int localY() const {
        return _local.y();
    }

	bool is(Direction direction) const {
		return _neighbours[direction.toSizeT()];
	}

	Tile* neighbour(Direction direction) const {
		return _neighbours[direction.toSizeT()];
	}

	// void add(Direction direction) {
	// 	assert(!is(direction));
	// 	auto coordinates = prepareCartesianCoordinates(direction);
	// 	_neighbours[direction] = new Tile(coordinates);
	// }

	CartesianCoordinates prepareCartesianCoordinates(Direction direction) const {
		switch (direction.toEnum()) {
		case Direction::Value::UP: return CartesianCoordinates(_local.x(), _local.y() - 1);
		case Direction::Value::LEFT: return CartesianCoordinates(_local.x() - 1, _local.y());
		case Direction::Value::DOWN: return CartesianCoordinates(_local.x(), _local.y() + 1);
		case Direction::Value::RIGHT: return CartesianCoordinates(_local.x() + 1, _local.y());
		}
		throw "";
	}


	// bool isUp() const {
	// 	return _up;
	// }

	// bool isDown() const {
	// 	return _down;
	// }

	// bool isLeft() const {
	// 	return _left;
	// }

	// bool isRight() const {
	// 	return _right;
	// }
	
};