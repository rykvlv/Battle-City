#pragma once

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include <memory>

#define CREATE_TEXT(text, font, size) rykvlv::TextFactory::GetInstance()->createText(text, font, size)

namespace rykvlv {
	using UPText = std::unique_ptr<sf::Text>;

	class TextFactory {
	public:
		TextFactory(const TextFactory& rhs) = delete;
		TextFactory& operator=(const TextFactory& rhs) = delete;

		static TextFactory* GetInstance();

		template<typename T,
			typename = std::enable_if_t<std::is_same_v<T, std::string>>
		>
		sf::Text* createText(const T&& text, T&& fontName, int characterSize) {
			std::string textString = text;
			sf::Font font = AMInstance->getFont(fontName);

			//_text->setCharacterSize(characterSize);

			return new sf::Text(textString, font);
		}
	private:
		TextFactory();

		static TextFactory* instance;
	};
}