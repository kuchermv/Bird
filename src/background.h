#include <SFML/Graphics.hpp>

class Background : public sf::Sprite {
private:
	sf::Sprite s;
	int width;
	float speed;

public:
	Background(const sf::Sprite& sprite, float theSpeed);
	void Tick(float dt);
	void Draw(sf::RenderTarget& target) const;
};