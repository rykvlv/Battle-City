#pragma once

#include "../SceneManager/Scene.h"
#include "../Game.h"

namespace rykvlv {
	class GameScene : public Scene {
	public:
		GameScene(SPtrGameData data);

		void init() override;
		void handleInput() override;
		void update() override;
		void draw() override;

		void pause() override;
		void resume() override;
	private:
		SPtrGameData _data;
	};
}