#include "AssetManager.h"
#include <filesystem>
#include <fstream>

namespace rykvlv {
	AssetManager* AssetManager::instance = nullptr;

	AssetManager::AssetManager() {

	}

	AssetManager* AssetManager::GetInstance() {
		if (instance == nullptr) {
			instance = new AssetManager();
		}

		return instance;
	}

	bool AssetManager::tryLoadProperties(std::string name) noexcept {
		if (_cachedProperties.find(name) != _cachedProperties.end()) {
			return true;
		}

		std::string path = std::filesystem::current_path().string();
		Json::Value root;
		std::fstream ifs;
		ifs.open(path + "/res/" + name + ".json");

		Json::CharReaderBuilder builder;
		builder["collectComments"] = false;
		JSONCPP_STRING errs;
		if (!Json::parseFromStream(builder, ifs, &root, &errs)) {
			return false;
		}

		_cachedProperties[name] = root;
		return true;
	}

	Json::Value& AssetManager::getProperties(std::string name) {
		if (tryLoadProperties(name))
			return _cachedProperties[name];

		throw FileNotFoundException();
	}

	bool AssetManager::tryLoadTexture(std::string name) noexcept {
		if (_cachedTextures.find(name) != _cachedTextures.end())
			return true;

		std::string path = std::filesystem::current_path().string();
		path += "/res/img/" + name;

		sf::Texture texture;
		if (texture.loadFromFile(path + ".png")) {
			_cachedTextures[name] = texture;
			return true;
		}
		else if (texture.loadFromFile(path + "jpg")) {
			_cachedTextures[name] = texture;
			return true;
		}
		else {
			return false;
		}
	}

	sf::Texture& AssetManager::getTexture(std::string name) {
		if (tryLoadTexture(name))
			return _cachedTextures[name];
		throw FileNotFoundException();
	}

	bool AssetManager::tryLoadFont(std::string name) noexcept {
		if (_cachedFonts.find(name) != _cachedFonts.end())
			return true;

		std::string path = std::filesystem::current_path().string();
		path += "/res/fonts/" + name + ".ttf";

		sf::Font font;
		
		if (font.loadFromFile(path)) {
			_cachedFonts[name] = font;
			return true;
		}
		else {
			return false;
		}
	}

	sf::Font& AssetManager::getFont(std::string name) {
		if (tryLoadFont(name))
			return _cachedFonts[name];
		throw FileNotFoundException();
	}
}