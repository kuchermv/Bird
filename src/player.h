#include <SFML/Graphics.hpp>

#include "spriteAnimator.h"

class Player : public sf::Drawable {
private:
    sf::Sprite sprite;
	SpriteAnimator sa;

public:
	Player(const sf::Sprite& sprite);
	SpriteAnimator& GetSpriteAnimator() { return sa; }
	void Tick(float dt);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};