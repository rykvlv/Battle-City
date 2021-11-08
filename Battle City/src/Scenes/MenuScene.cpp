#include "MenuScene.h"
#include <iostream>
#include "GameScene.h"

using namespace std::string_literals;

namespace rykvlv {
	MenuScene::MenuScene(SPtrGameData data) : _data(data), pointerPos(0) {
		_text = sf::Text();
		_pointer = sf::Text();
	}

	void MenuScene::init() {
		ConfigureText(_text, AMInstance->getFont("tank_font"s), "Battle City"s, 80);
		ConfigureText(_pointer, AMInstance->getFont("prstartk"s), ">"s, 40);
		_text.setPosition(sf::Vector2f(_data->width / 2, _data->height / 2 - 200));
		_text.setColor({ 255, 120, 100, 255 });
		_buttons = {
			{ "Play", AMInstance->getFont("prstartk"s), 40 },
			{ "Exit", AMInstance->getFont("prstartk"s), 40 }
		};
		
		for (int i = 0; i < _buttons.size(); ++i) {
			auto& button = _buttons[i];
			button.setOrigin(button.getGlobalBounds().width / 2, button.getGlobalBounds().height / 2);
			button.setPosition(sf::Vector2f(_data->width / 2, _data->height / 2 + i * 60));
		}
		_pointer.setPosition(
			sf::Vector2f(_buttons[0].getPosition().x - _buttons[0].getGlobalBounds().width / 2 - 35,
				         _buttons[0].getPosition().y)
		);
	}

	void MenuScene::handleInput() {
		sf::Event event;

		while (_data->window.pollEvent(event)) {
			if (sf::Event::Closed == event.type) {
				//TODO: Perform some save actions if needed before exit program
				std::cout << "Window closed" << std::endl;
				_data->window.close();
			}

			if (sf::Keyboard::Down == event.key.code && sf::Event::KeyPressed == event.type) {
				if (pointerPos < _buttons.size() - 1) {
					pointerPos++;
					_pointer.setPosition(
						sf::Vector2f(_buttons[pointerPos].getPosition().x - _buttons[pointerPos].getGlobalBounds().width / 2 - 35,
							_buttons[pointerPos].getPosition().y)
					);
				}
			}

			if (sf::Keyboard::Up == event.key.code && sf::Event::KeyPressed == event.type) {
				if (pointerPos > 0) {
					pointerPos--;
					_pointer.setPosition(
						sf::Vector2f(_buttons[pointerPos].getPosition().x - _buttons[pointerPos].getGlobalBounds().width / 2 - 35,
							_buttons[pointerPos].getPosition().y)
					);
				}
			}

			if (sf::Keyboard::Enter == event.key.code && sf::Event::KeyPressed == event.type) {
				switch (pointerPos) {
				case 0:
					_data->sceneManager.addScene(std::make_unique<GameScene>(_data));
					break;
				case 1:
					_data->window.close();
					break;
				}
			}
		}
	}

	void MenuScene::update() {

	}

	void MenuScene::draw() {
		_data->window.clear(sf::Color::Black);
		_data->window.draw(_text);
		for (auto& button : _buttons) {
			_data->window.draw(button);
		}
		_data->window.draw(_pointer);
		_data->window.display();
	}
}