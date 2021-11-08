#include "SceneManager.h"
#include "Scene.h"

namespace rykvlv {
	SceneManager::SceneManager() : _isAdding{ false }, _isRemoving{ false }, _isReplacing{ false }{

	}

	void SceneManager::addScene(UPtrScene newScene, bool isReplacing) {
		_isAdding = true;
		_isReplacing = isReplacing;
		_newScene = std::move(newScene);
	}

	void SceneManager::removeScene() noexcept {
		_isRemoving = true;
	}

	void SceneManager::processSceneChanges() {
		if (_isRemoving && !_scenes.empty()) {
			_scenes.pop();
			if (!_scenes.empty()) {
				_scenes.top()->resume();
			}
		}

		if (_isAdding) {
			if (!_scenes.empty()) {
				if (_isReplacing)
					_scenes.pop();
				else
					_scenes.top()->pause();
			}
			_scenes.push(std::move(_newScene));
			_scenes.top()->init();

			_isAdding = false;
		}
	}

	UPtrScene& SceneManager::getActiveState() {
		return _scenes.top();
	}
}