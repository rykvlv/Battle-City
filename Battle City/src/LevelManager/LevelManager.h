#pragma once
#include <vector>
#include <stack>

namespace rykvlv {
	struct Level {
		std::vector<int> walls;
		std::stack<int> enemies;
		int order;
	};

	class LevelManager {
	public:
		void loadLevels() {

		}

	private:
		std::vector<Level> _levels;
		Level _level;
	};
}