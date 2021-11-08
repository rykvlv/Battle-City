#pragma once

#include "../AssetManager.h"
#include <SFML/Graphics.hpp>

namespace rykvlv {
	class Scene {
	public:
		virtual void init() = 0;
		virtual void handleInput() = 0;
		virtual void update() = 0;
		virtual void draw() = 0;

		virtual void pause() {}
		virtual void resume() {}

		void ConfigureText(sf::Text& text, sf::Font& font, std::string s, int size) {
			text.setFont(font);
			text.setCharacterSize(size);
			text.setString(s);
			text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
		}
	};
}