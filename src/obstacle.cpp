#include "obstacle.h"

void Obstacle::Clear() { 
	points.clear(); 
}

void Obstacle::AddPoint(sf::Vector2f p) { 
	points.push_back(p); 
};

void Obstacle::AddPoints(std::vector<sf::Vector2f> pointsToAdd) {
	points.reserve(points.size() + pointsToAdd.size());
	points.insert(points.end(), pointsToAdd.begin(), pointsToAdd.end());
}

void Obstacle::DebugDrawPoints(sf::RenderWindow& rw) {
	const sf::IntRect& r = getTextureRect();
	
	sf::CircleShape shape(3);
	shape.setOrigin(3, 3);
    shape.setFillColor(sf::Color::Red);
	
	for (sf::Vector2f p : points) {		
		if (r.width < 0) {
			p.x = -(p.x + r.width);
		}
		if (r.height < 0) {
			p.y = -(p.y + r.height);
		}
		shape.setPosition(getPosition() + p);
		rw.draw(shape);
	}
}