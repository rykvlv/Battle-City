#include "TextFactory.h"

namespace rykvlv {
	TextFactory* TextFactory::instance = nullptr;

	TextFactory::TextFactory() {

	}

	TextFactory* TextFactory::GetInstance() {
		if (instance == nullptr) {
			instance = new TextFactory();
		}

		return instance;
	}
}