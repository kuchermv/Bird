#include "player.h"

Player::Player() : sa(*this, 0.1) {

}

void Player::Tick(float dt) {
	sa.Tick(dt);
}