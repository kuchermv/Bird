#include "spritesheet.h"
#include <fstream>

Spritesheet::Spritesheet() {
	tex.loadFromFile("assets/sheet.png");

	std::ifstream ifs("assets/sheet.data");
	while (!ifs.eof()) {
		std::string name;
		sf::IntRect rect;
	
		ifs >> name;
		if (name.length() == 0) {
			return;
		}

		ifs >> rect.left;
		ifs >> rect.top;
		ifs >> rect.width;
		ifs >> rect.height;

		items[name] = rect;
	}
}

sf::Sprite Spritesheet::GetSprite(const std::string& name, FlipStatus flipStatus) {
	sf::Sprite result(tex);
	sf::IntRect rect = items[name];
	if (flipStatus == FlipStatus::FLIPED_X || flipStatus == FlipStatus::FLIPED_XY) {
		rect.left += rect.width;
		rect.width = -rect.width;
	}
	if (flipStatus == FlipStatus::FLIPED_Y || flipStatus == FlipStatus::FLIPED_XY) {
		rect.top += rect.height;
		rect.height = -rect.height;
	}
	result.setTextureRect(rect);
	return result;
}