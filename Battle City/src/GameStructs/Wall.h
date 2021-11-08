#pragma once
#include "GameObject.h"

namespace rykvlv {
	class Wall : public GameObject {
	public:
		enum class WallType {
			BRICK, IRON, BUSH, WATER, ICE
		};

		Wall();
		Wall(float x, float y, WallType type);

		float x()      const noexcept override;
		float y()      const noexcept override;
		float left()   const noexcept override;
		float right()  const noexcept override;
		float bottom() const noexcept override;
		float top()    const noexcept override;
	private:
		sf::Sprite _sprite;
		float _x, _y;
		float _width, _height;
		WallType _type;
	};
}