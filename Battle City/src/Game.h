#pragma once

#include <memory>
#include <string>
#include <json/json.h>

#include <SFML/Graphics.hpp>

#include "SceneManager/SceneManager.h"
#include "AssetManager.h"

namespace rykvlv {

	struct GameData {
		SceneManager sceneManager;
		sf::RenderWindow window;
		std::string title;
		int width, height;
	};

	using SPtrGameData = std::shared_ptr<GameData>;

	class Game {
	public:
		Game();
		Game(const std::string& title, int width, int height);
	private:
		void run();

		void loadData();
		void saveData();

		const float dt = 1.0f / 60.0f;
		sf::Clock _clock;

		SPtrGameData _data = std::make_shared<GameData>();
	};
}