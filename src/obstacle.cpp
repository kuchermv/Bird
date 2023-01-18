#include "obstacle.h"

Obstacle::Obstacle(float theSpeed) : speed(theSpeed) {
}

void Obstacle::Tick(float dt) {
	move(-speed * dt, 0);
}

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
	sf::CircleShape shape(3);
	shape.setOrigin(3, 3);
    shape.setFillColor(sf::Color::Red);
	
	for (sf::Vector2f p : points) {
		shape.setPosition(ToGlobal(p));
		rw.draw(shape);
	}
}

bool Obstacle::CheckHit(sf::FloatRect rect) {
	for (sf::Vector2f p : points) {
		if (rect.contains(ToGlobal(p))) {
			return true;
		}
	}
	return false;
}

bool Obstacle::IsLeftPlayArea() {
	sf::FloatRect fr = getGlobalBounds();
	return (fr.left + fr.width) <= 0;
}

sf::Vector2f Obstacle::ToGlobal(sf::Vector2f& p) const {
	const sf::IntRect& r = getTextureRect();
	if (r.width < 0) {
		p.x = -(p.x + r.width);
	}
	if (r.height < 0) {
		p.y = -(p.y + r.height);
	}
	return getPosition() + p;
}