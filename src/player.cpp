#include "player.h"

Player::Player(const sf::Sprite& _sprite) : sprite(_sprite), sa(sprite, 0.1) {

}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(sprite, states);
}

void Player::Tick(float dt) {
	sa.Tick(dt);
}