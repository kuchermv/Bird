#include <SFML/Graphics.hpp>

class Background : public sf::Drawable {
private:
    sf::Sprite bg1, bg2;
	float width;

public:
	Background(const sf::Sprite& sprite, float yPos = 0.0);

	void MoveLeft(float offset);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};