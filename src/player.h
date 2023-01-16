#include <SFML/Graphics.hpp>

#include "spriteAnimator.h"

class Player : public sf::Sprite {
private:
	SpriteAnimator sa;

public:
	Player();
	SpriteAnimator& GetSpriteAnimator() { return sa; }
	void Tick(float dt);

};