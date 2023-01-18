#include <SFML/Graphics.hpp>

class Obstacle : public sf::Sprite {
private:
	std::vector<sf::Vector2f> points;
	float speed;
public:
	Obstacle(float theSpeed);
	void Tick(float dt);

	void Clear();
	void AddPoint(sf::Vector2f p);
	void AddPoints(std::vector<sf::Vector2f> pointsToAdd);

	bool CheckHit(sf::FloatRect rect);
	void DebugDrawPoints(sf::RenderWindow& rw);
	bool IsLeftPlayArea();

private:
	sf::Vector2f ToGlobal(sf::Vector2f& p) const;
};