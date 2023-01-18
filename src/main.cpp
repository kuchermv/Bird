#include <iostream>
#include <SFML/Graphics.hpp>

#include "spritesheet.h"
#include "background.h"
#include "obstacle.h"
#include "player.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(800, 480), "Bird");
	window.setFramerateLimit(30);

	sf::Clock clock;
	Spritesheet spritesheet;

	sf::Sprite bgSprite;
	spritesheet.InitSprite(bgSprite, "background");
	Background bg(bgSprite, 50);

	std::vector<sf::Vector2f> rockHitPoints;
	{
		rockHitPoints.push_back(sf::Vector2f(0, 0));
		rockHitPoints.push_back(sf::Vector2f(6, 24));
		rockHitPoints.push_back(sf::Vector2f(15, 52));
		rockHitPoints.push_back(sf::Vector2f(22, 78));
		rockHitPoints.push_back(sf::Vector2f(27, 102));
		rockHitPoints.push_back(sf::Vector2f(38, 121));
		rockHitPoints.push_back(sf::Vector2f(44, 147));
		rockHitPoints.push_back(sf::Vector2f(49, 170));
		rockHitPoints.push_back(sf::Vector2f(53, 194));
		rockHitPoints.push_back(sf::Vector2f(58, 218));
		rockHitPoints.push_back(sf::Vector2f(66, 237));
		rockHitPoints.push_back(sf::Vector2f(71, 214));
		rockHitPoints.push_back(sf::Vector2f(75, 187));
		rockHitPoints.push_back(sf::Vector2f(78, 160));
		rockHitPoints.push_back(sf::Vector2f(84, 136));
		rockHitPoints.push_back(sf::Vector2f(89, 111));
		rockHitPoints.push_back(sf::Vector2f(93, 82));
		rockHitPoints.push_back(sf::Vector2f(100, 59));
		rockHitPoints.push_back(sf::Vector2f(103, 33));
		rockHitPoints.push_back(sf::Vector2f(108, 0));
	}

	Obstacle o(100);
	o.move(800, 0);
	spritesheet.InitSprite(o, "rockDown");
	o.AddPoints(rockHitPoints);

	Player player;
	spritesheet.InitSprite(player, "planeRed1");
	SpriteAnimator& sa = player.GetSpriteAnimator();
	std::vector<std::string> frames{"planeRed1", "planeRed2", "planeRed3"};
	sa.SetFrames(spritesheet, frames);

	player.move(50, 150);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::Closed) || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))) {
				window.close();
			}
			if((event.type == sf::Event::MouseButtonPressed) && event.mouseButton.button == sf::Mouse::Button::Left) {
				std::cout << event.mouseButton.x << ", " << event.mouseButton.y << std::endl;
			}
		}

		float dt = clock.restart().asSeconds();
		bg.Tick(dt);
		player.Tick(dt);
		o.Tick(dt);

		if (o.IsLeftPlayArea()) {
			o.move(1000, 0);
		}

		player.setColor(sf::Color::White);
		if (o.CheckHit(player.getGlobalBounds())) {
			player.setColor(sf::Color::Red);
		}

		window.clear();
			bg.Draw(window);

			window.draw(o);
			o.DebugDrawPoints(window);

			window.draw(player);
		window.display();
	}
	return 0;
}