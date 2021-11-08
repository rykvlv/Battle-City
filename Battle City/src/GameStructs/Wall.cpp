#include "Wall.h"

namespace rykvlv {
	Wall::Wall() : _x(0), _y(0), _width(0), _height(0), _type(WallType::BRICK) {

	}

	Wall::Wall(float x, float y, WallType type) : _x(x), _y(y), _type(type), _width(20), _height(20) {
		_sprite.setOrigin(_width / 2, _height / 2);
		_sprite.setPosition(x, y);
	}

	float Wall::x() const noexcept {
		return _x;
	}

	float Wall::y() const noexcept {
		return _y;
	}

	float Wall::left() const noexcept {
		return x() - _sprite.getGlobalBounds().width / 2;
	}

	float Wall::right() const noexcept {
		return x() + _sprite.getGlobalBounds().width / 2;
	}

	float Wall::top() const noexcept {
		return y() - _sprite.getGlobalBounds().height / 2;
	}

	float Wall::bottom() const noexcept {
		return y() + _sprite.getGlobalBounds().height / 2;
	}
}