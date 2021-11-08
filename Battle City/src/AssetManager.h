#pragma once

#include <unordered_map>
#include <json/json.h>
#include <SFML/Graphics.hpp>
#include <memory>

#define AMInstance AssetManager::GetInstance()

namespace rykvlv {

	struct FileNotFoundException : public std::exception {
		const char* what() const throw() {
			return "File not found exception";
		}
	};

	class AssetManager {
	public:
		AssetManager(const AssetManager& rhs) = delete;
		AssetManager& operator=(const AssetManager& rhs) = delete;

		static AssetManager* GetInstance();

		bool tryLoadProperties(std::string name) noexcept;
		Json::Value& getProperties(std::string name);

		bool tryLoadTexture(std::string name) noexcept;
		sf::Texture& getTexture(std::string name);

		bool tryLoadFont(std::string name) noexcept;
		sf::Font& getFont(std::string font);

		
	private:
		AssetManager();

		static AssetManager* instance;
		std::unordered_map<std::string, sf::Texture> _cachedTextures;
		std::unordered_map<std::string, sf::Font> _cachedFonts;
		std::unordered_map<std::string, Json::Value> _cachedProperties;
	};
}