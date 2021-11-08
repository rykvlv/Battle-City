#pragma once

#include <vector>

#include "../SceneManager/Scene.h"
#include "../Game.h"

namespace rykvlv {
	class MenuScene : public Scene {
	public:
		MenuScene(SPtrGameData data);

		void init() override;
		void handleInput() override;
		void update() override;
		void draw() override;
	private:
		SPtrGameData _data;
		sf::Text _text;
		sf::Text _pointer;
		
		std::vector<sf::Text> _buttons;

		int pointerPos;

		sf::CircleShape shape;
	};
}