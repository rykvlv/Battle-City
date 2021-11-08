#include "Game.h"
#include "Scenes/MenuScene.h"
#include "AssetManager.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace rykvlv {
	Game::Game() {
		loadData();
		_data->window.create(sf::VideoMode(_data->width, _data->height), _data->title,
			sf::Style::Close | sf::Style::Titlebar);
		_data->window.setFramerateLimit(60);
		_data->sceneManager.addScene(std::make_unique<MenuScene>(_data));

		run();
	}

	Game::Game(const std::string& title, int width, int height) {
		_data->window.create(sf::VideoMode(width, height), title, 
			                 sf::Style::Close | sf::Style::Titlebar);
		_data->window.setFramerateLimit(60);
		_data->sceneManager.addScene(std::make_unique<MenuScene>(_data));

		run();
	}

	void Game::run() {
		float newTime, frameTime, interpolation;
		float currentTime = _clock.getElapsedTime().asSeconds();
		float accumulator = 0.0f;

		while (_data->window.isOpen()) {
			_data->sceneManager.processSceneChanges();
			newTime = _clock.getElapsedTime().asSeconds();
			frameTime = newTime - currentTime;
			if (frameTime > 0.25f) {
				frameTime = 0.25f;
			}
			currentTime = newTime;
			accumulator += frameTime;
			while (accumulator >= dt) {
				_data->sceneManager.getActiveState()->handleInput();
				_data->sceneManager.getActiveState()->update();
				accumulator -= dt;
			}
			interpolation = accumulator / dt;
			_data->sceneManager.getActiveState()->draw();
		}
	}

	void Game::loadData() {
		Json::Value& json = AMInstance->getProperties("parameters");
		_data->title = json["title"].asString();
		_data->width = json["screen_width"].asInt();
		_data->height = json["screen_height"].asInt();
		
	}
}