#include "background.h"
#include <cmath>
#include <iostream>

Background::Background(const sf::Sprite& sprite, float yPos) {
	bg1 = sprite;
	bg2 = sprite;

	width = fabs(sprite.getTextureRect().width);
	bg1.setPosition(0, yPos);
	bg2.setPosition(width, yPos);
}

void Background::MoveLeft(float offset) {
	sf::Vector2f pos = bg1.getPosition();
	pos.x = fmodf(pos.x - offset, width);
	bg1.setPosition(pos);
	pos.x += width;
	bg2.setPosition(pos);
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(bg1, states);
	target.draw(bg2, states);
}