#include "GameScene.h"

namespace rykvlv {
	GameScene::GameScene(SPtrGameData data) : _data(data) {

	}

	void GameScene::init() {

	}

	void GameScene::handleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				_data->window.close();
			}
		}
	}

	void GameScene::update() {

	}

	void GameScene::pause() {

	}

	void GameScene::resume() {

	}

	void GameScene::draw() {
		_data->window.clear(sf::Color::Red);
		_data->window.display();
	}
}