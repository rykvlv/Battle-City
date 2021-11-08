#pragma once

#include <memory>
#include <stack>

#include "Scene.h"

namespace rykvlv {
	using UPtrScene = std::unique_ptr<Scene>;

	class SceneManager {
	public:
		SceneManager();

		void addScene(UPtrScene newScene, bool isReplacing = true);
		void removeScene() noexcept;

		void processSceneChanges();

		UPtrScene& getActiveState();
	private:
		std::stack<UPtrScene> _scenes;
		UPtrScene _newScene;

		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
	};
}

