#include <SFML/Graphics.hpp>

class Obstacle : public sf::Sprite {
private:
	std::vector<sf::Vector2f> points;
public:
	void Clear();
	void AddPoint(sf::Vector2f p);
	void AddPoints(std::vector<sf::Vector2f> pointsToAdd);

	//void Check();
	void DebugDrawPoints(sf::RenderWindow& rw);
};