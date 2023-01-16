#include "background.h"
#include <cmath>
#include <iostream>

Background::Background(const sf::Sprite& sprite, float theSpeed) : s(sprite), speed(theSpeed){
	width = fabs(sprite.getTextureRect().width);
}

void Background::Tick(float dt) {
	sf::Vector2f pos = s.getPosition();
	pos.x = fmodf(pos.x - speed * dt, width);
	s.setPosition(pos);
}

void Background::Draw(sf::RenderTarget& target) const {
	target.draw(s);
	sf::RenderStates states(sf::Transform().translate(width, 0));
	target.draw(s, states);
}