#pragma once
#include <SFML/Graphics.hpp>

namespace rykvlv {
	class GameObject {
	public:
		GameObject() : _x{ 0 }, _y{ 0 } {

		}

		virtual float x()      const noexcept = 0;
		virtual float y()      const noexcept = 0;
		virtual float left()   const noexcept = 0;
		virtual float right()  const noexcept = 0;
		virtual float bottom() const noexcept = 0;
		virtual float top()    const noexcept = 0;

		void setXY(float x, float y) noexcept {
			_x = x;
			_y = y;
		}

		void setX(float x) noexcept {
			_x = x;
		}

		void setY(float y) noexcept {
			_y = y;
		}

		void setSprite(sf::Texture texture) {
			_sprite.setTexture(texture);
		}

		sf::Sprite getSprite() const noexcept{
			return _sprite;
		}

		bool isInteracting(const GameObject& object) const noexcept{
			return right() > object.left() &&
				   left() < object.right() &&
				   bottom() > object.top() &&
				   top() < object.bottom();
		}
	protected:
		sf::Sprite _sprite;
		float _x, _y;
	};
}